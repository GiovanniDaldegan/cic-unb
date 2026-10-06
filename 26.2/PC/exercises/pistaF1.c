#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>


#define NUMCARROS 2
#define NUMEQUIPES 10
#define CAPACIDADEPISTA 5


pthread_t car[NUMCARROS*NUMEQUIPES];
int equipes[NUMEQUIPES];
sem_t sem_eq[NUMEQUIPES];
sem_t sem_pista;
int livre;

void * piloto(void *arg);


int main(int argc, char **argv){
    int i;
    int *id;
    srand48(time(NULL));

    sem_init(&sem_pista, 0, CAPACIDADEPISTA);

    for (i = 0; i < NUMEQUIPES; i++) {
    	sem_init(&sem_eq[i], 0, 1);
    }

    for(i = 0; i < NUMCARROS*NUMEQUIPES;i++){
        id = (int *) malloc(sizeof(int));
        *id = i;
	pthread_create(&(car[i]),NULL,piloto, (void*) (id));
    }
   pthread_join(car[0],NULL);
  
}


void * piloto(void *arg){
    int id = *((int *) arg);
    int eq = id%NUMEQUIPES;
    printf("Carro %d da equipe %d criado\n",id,eq);
    while(1){
        //ENTRAR NA PISTA
	sem_wait(&sem_pista);
	sem_wait(&sem_eq[eq]);

        //TREINAR
	sem_getvalue(&sem_pista, &livre);
        printf("Carro %d da equipe %d está treinando. Carros na pista: %d\n", id, eq, CAPACIDADEPISTA - livre);
	sleep(8);
        //SAIR DA PISTA
	sem_post(&sem_pista);
	sem_post(&sem_eq[eq]);

	printf("Carro %d da equipe %d saiu da pista\n", id, eq);
    }
}

