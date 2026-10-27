#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define C 10
#define N 3

sem_t sem_cadeiras;
sem_t sem_cadeira_corte;
sem_t sem_atendimento;
sem_t sem_finalizado;

pthread_t t_clientes[C];
pthread_t t_barbeiro;


void* cliente (void* arg) {
  int id = *((int*) arg);
  for (int i = 0; i < 4; i++) {
    if (sem_trywait(&sem_cadeiras) != 0)
      sleep(6);
    else {
      sem_wait(&sem_cadeira_corte);             // espera cadeira de corte
      sem_post(&sem_cadeiras);                  // levanta da cadeira de espera
      sem_post(&sem_atendimento);               // acorda o barbeiro p atendimento
      printf("%d: acorda aí fi\n", id);
      sem_wait(&sem_finalizado);                // espera finalizar atendimento
      printf("%d: ficou top tmj. vlww!\n", id);
      sem_post(&sem_cadeira_corte);             // libera caidera de corte
      sleep(4);
    }
  }
}

void* barbeiro (void* arg) {
  //int id = (int*) *arg;
  while (true) {
    sem_wait(&sem_atendimento);                 // espera alguém pedir atendimento
    printf("opa, tô de pé. vambora arrumar esse cabelo\n");
    sleep(1);
    sem_post(&sem_finalizado);                  // avisa que terminou serviço
    printf("tá pronto chefe, ficou bom?\n");
  }
}

int main() {
  sem_init(&sem_cadeiras, 0, N);
  sem_init(&sem_cadeira_corte, 0, 1);
  sem_init(&sem_atendimento, 0, 0);
  sem_init(&sem_finalizado, 0, 0);

  int i;
  int* id = (int*) malloc(sizeof(int));

  for (i = 0; i < C; i++) {
    *id = i;
    pthread_create(&t_clientes[i], NULL, &cliente, (void*) id); // cliente
  }

  pthread_create(&t_barbeiro, NULL, &barbeiro, (void*) 0); // barbeiro

  for (i = 0; i < C; i++) {             // não garante todas threads
    pthread_join(t_clientes[i], NULL);
  }
}

