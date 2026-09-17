#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAXCANIBAIS 20

void *canibal(void*meuid);
void *cozinheiro(int m);

int porcoes = 0;

pthread_mutex_t caldeirao    = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  rango_pronto = PTHREAD_COND_INITIALIZER;
pthread_cond_t  boia_cabou   = PTHREAD_COND_INITIALIZER;


void main(argc, argv)
int argc;
char *argv[];
{
  int erro;
  int i, n, m;
  int *id;

  pthread_t tid[MAXCANIBAIS];

  if(argc != 3){
    printf("erro na chamada do programa: jantar <#canibais> <#comida>\n");
    exit(1);
  }
  
  n = atoi (argv[1]); //número de canibais
  m = atoi (argv[2]); // quantidade de porções que o cozinheiro consegue preparar por vez
  printf("numero de canibais: %d -- quantidade de comida: %d\n", n, m);

  if(n > MAXCANIBAIS){
    printf("o numero de canibais e' maior que o maximo permitido: %d\n", MAXCANIBAIS);
    exit(1);
  }
  
  for (i = 0; i < n; i++)  {
    id = (int *) malloc(sizeof(int));
    *id = i;
    erro = pthread_create(&tid[i], NULL, canibal, (void *) (id));

    if(erro){
      printf("erro na criacao do thread %d\n", i);
      exit(1);
    }
  }

  cozinheiro(m);
}

void * canibal (void* pi){
  
  while(1) {
    //pegar uma porção de comida e acordar o cozinheiro se as porções acabaram
    pthread_mutex_lock(&caldeirao);

      if (porcoes <= 0) {
        pthread_cond_signal(&boia_cabou);
        pthread_cond_wait(&rango_pronto, &caldeirao);
      }
      porcoes --;
    
    pthread_mutex_unlock(&caldeirao);

    printf("%d: vou comer a porcao que peguei\n", *(int *)(pi));
    //sleep(8);
  }
  
}

void *cozinheiro (int m){
 
  while(1){
    if (porcoes < 0)
      printf("NEGATIVOU PORCOES : %i\n", porcoes);
    //dormir enquanto tiver comida
    pthread_mutex_lock(&caldeirao);

    pthread_cond_wait(&boia_cabou, &caldeirao);

      printf("cozinheiro: vou cozinhar\n");
      sleep(1);
      porcoes += m;
      printf("cozinheiro: rango pronto\n");

      //acordar os canibais
      pthread_cond_broadcast(&rango_pronto);

    pthread_mutex_unlock(&caldeirao);
   }

}
