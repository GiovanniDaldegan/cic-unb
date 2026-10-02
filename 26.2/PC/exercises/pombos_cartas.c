#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include "unistd.h"

#define N 10      //número de usuários
#define CARTAS 20 //quantidade máxima de cartas

pthread_mutex_t carta_lock  = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  carta_max   = PTHREAD_COND_INITIALIZER;
pthread_cond_t  pombo_disp  = PTHREAD_COND_INITIALIZER;

void * f_usuario(void *arg);
void * f_pombo(void *arg);
int cartas = 0;

int main(int argc, char **argv){
  int i;

  pthread_t usuario[N];
  int *id;
  for(i = 0; i < N; i++){
    id = (int *) malloc(sizeof(int));
    *id = i;
    pthread_create(&(usuario[i]),NULL,f_usuario,  (void *) (id));
  }

  pthread_t pombo;
  id = (int *) malloc(sizeof(int));
  *id = 0;
  pthread_create(&(pombo),NULL,f_pombo, (void*) (id));

  pthread_join(pombo,NULL);
}


void * f_pombo(void *arg){
  int id = *((int*) arg);

  while(1){
    //Inicialmente está em A, aguardar/dorme a mochila ficar cheia (20 cartas)
    //Leva as cartas para B e volta para A
    pthread_mutex_lock(&carta_lock);
    while (cartas < CARTAS)
      pthread_cond_wait(&carta_max, &carta_lock);

    printf("Levando %d cartas para B...\n", cartas);
    sleep(6);
    cartas = 0;
    printf("O pombo voltou. 🕊️👍\n");

    pthread_cond_broadcast(&pombo_disp);
    pthread_mutex_unlock(&carta_lock);

    //Acordar os usuários   
  }
}

void * f_usuario(void *arg){
  int id = *((int*) arg);

  while(1){
    //Escreve uma carta
    sleep(4 + rand() % 2);

    //Caso o pombo não esteja em A ou a mochila estiver cheia, então dorme	
    // no caso, coloquei pra ele esperar o pombo voltar e abrir o lock
    pthread_mutex_lock(&carta_lock);

    //Posta sua carta na mochila do pombo
    cartas ++;
    printf("Usuario %d postando %dª carta.\n", id, cartas);
    
    //Caso a mochila fique cheia, acorda o ṕombo 🕊️
    if (cartas == CARTAS)
      pthread_cond_signal(&carta_max);
    pthread_mutex_unlock(&carta_lock);
  }
}
