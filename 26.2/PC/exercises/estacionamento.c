// vale 1.0 na nota da P1

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define PROFS 5
#define FUNCS 13
#define ALUNS 30

int capacidade = 30;
int ocupadas = 0;
int espera_profs = 0;
int espera_funcs = 0;

pthread_mutex_t estacionamento = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t saindo = PTHREAD_COND_INITIALIZER;

void* professores(void* arg) {
  for (int i = 0; i < 3; i++){
    pthread_mutex_lock(&estacionamento);
      espera_profs ++;
      while(ocupadas == capacidade)
        pthread_cond_wait(&saindo, &estacionamento);
      espera_profs--;
      ocupadas ++;
      printf("prof entrando | %d vagas ocupadas\n", ocupadas);
    pthread_mutex_unlock(&estacionamento);

    sleep(50);

    pthread_mutex_lock(&estacionamento);
      ocupadas --;
      printf("prof saindo | %d vagas ocupadas\n", ocupadas);
      pthread_cond_broadcast(&saindo);
    pthread_mutex_unlock(&estacionamento);
  }
}

void* funcionarios(void* arg) {
  for (int i = 0; i < 5; i++) {
    pthread_mutex_lock(&estacionamento);
      espera_funcs ++;
      while(ocupadas == capacidade || espera_profs > 0)
        pthread_cond_wait(&saindo, &estacionamento);
      espera_funcs --;
      ocupadas ++;
      printf("func entrando | %d vagas ocupadas\n", ocupadas);
    pthread_mutex_unlock(&estacionamento);

    sleep(25);

    pthread_mutex_lock(&estacionamento);
      ocupadas --;
      printf("func saindo | %d vagas ocupadas\n", ocupadas);
      pthread_cond_broadcast(&saindo);
    pthread_mutex_unlock(&estacionamento);
  }
}

void* alunos(void* arg) {
  for (int i = 0; i < 8; i++) {
    pthread_mutex_lock(&estacionamento);
      while(ocupadas == capacidade || espera_profs > 0 || espera_funcs > 0)
        pthread_cond_wait(&saindo, &estacionamento);
      ocupadas ++;
      printf("alun entrando | %d vagas ocupadas\n", ocupadas);
    pthread_mutex_unlock(&estacionamento);

    sleep(10);

    pthread_mutex_lock(&estacionamento);
      ocupadas --;
      printf("alun saindo | %d vagas ocupadas\n", ocupadas);
      pthread_cond_broadcast(&saindo);
    pthread_mutex_unlock(&estacionamento);
  }
}


int main(int argc, char * argv[])
{
  int erro = 0;

  pthread_t profs[PROFS];
  pthread_t funcs[FUNCS];
  pthread_t aluns[ALUNS];

  for (int i = 0; i < PROFS + FUNCS + ALUNS; i++) {
    int* id = (int*) malloc(sizeof(int));
    *id = i;

    if (i < PROFS)
      erro = pthread_create(&profs[i], NULL, professores, (void*) id);
    else if (i < PROFS + FUNCS)
      erro = pthread_create(&funcs[i - PROFS], NULL, funcionarios, (void*) id);
    else
      erro = pthread_create(&aluns[i - (PROFS + FUNCS)], NULL, alunos, (void*) id);

    if (erro) {
      printf("ABLEBUBABKDL %d", erro);
      exit(1);
    }
  }

  for (int i = 0; i < PROFS + FUNCS + ALUNS; i++) {
    if (i < PROFS)
      pthread_join(profs[i], NULL);
    else if (i < PROFS + FUNCS)
      pthread_join(funcs[i - PROFS], NULL);
    else
      pthread_join(aluns[i - (PROFS + FUNCS)], NULL);
  }

  return 0;
}

