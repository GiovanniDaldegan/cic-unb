#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MA 10 //macacos que andam de A para B
#define MB 10 //macacos que andam de B para A
#define GORILLA

pthread_mutex_t lock_a = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock_b = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock_g = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock_turno = PTHREAD_MUTEX_INITIALIZER;

int num_a = 0, num_b = 0;

void * macacoAB(void * a) {
  int i = *((int *) a);    
  while(1){
    //Procedimentos para acessar a corda
    pthread_mutex_lock(&lock_turno);
    pthread_mutex_lock(&lock_a);

    if (num_a == 0) {
      pthread_mutex_lock(&lock_b);
      pthread_mutex_lock(&lock_g);
    }
    num_a ++;

    pthread_mutex_unlock(&lock_a);
    pthread_mutex_unlock(&lock_turno);

    printf("Macaco %d passado de A para B \n",i);
    sleep(1);

    //Procedimentos para quando sair da corda
    pthread_mutex_lock(&lock_a);

    if (num_a == 1) {
      pthread_mutex_unlock(&lock_b);
      pthread_mutex_unlock(&lock_g);
    }
    num_a --;

    pthread_mutex_unlock(&lock_a);
  }
  pthread_exit(0);
}

void * macacoBA(void * a) {
  int i = *((int *) a);    
  while(1){
    //Procedimentos para acessar a corda
    pthread_mutex_lock(&lock_turno);
    pthread_mutex_lock(&lock_b);

    if (num_b == 0) {
      pthread_mutex_lock(&lock_a);
      pthread_mutex_lock(&lock_g);
    }
    num_b ++;

    pthread_mutex_unlock(&lock_b);
    pthread_mutex_unlock(&lock_turno);

    printf("Macaco %d passado de B para A \n",i);
    sleep(1);

    //Procedimentos para quando sair da corda

    pthread_mutex_lock(&lock_b);

    if (num_b == 1) {
      pthread_mutex_unlock(&lock_a);
      pthread_mutex_unlock(&lock_g);
    }
    num_b --;

    pthread_mutex_unlock(&lock_b);
  }
  pthread_exit(0);
}



void * gorilaAB(void * a){
  while(1){
    //Procedimentos para acessar a corda

    pthread_mutex_lock(&lock_turno);
    pthread_mutex_unlock(&lock_turno);

    pthread_mutex_lock(&lock_a);
    pthread_mutex_lock(&lock_b);
    pthread_mutex_lock(&lock_g);

    printf("Gorila passado de A para B \n");
    sleep(5);

    pthread_mutex_unlock(&lock_g);
    pthread_mutex_unlock(&lock_b);
    pthread_mutex_unlock(&lock_a);
    //Procedimentos para quando sair da corda
  }
  pthread_exit(0);
}

void * gorilaBA(void * a){
  while(1){
    //Procedimentos para acessar a corda

    pthread_mutex_lock(&lock_turno);
    pthread_mutex_unlock(&lock_turno);

    pthread_mutex_lock(&lock_a);
    pthread_mutex_lock(&lock_b);
    pthread_mutex_lock(&lock_g);

    printf("Gorila passado de B para A \n");
    sleep(5);

    pthread_mutex_unlock(&lock_g);
    pthread_mutex_unlock(&lock_b);
    pthread_mutex_unlock(&lock_a);
    //Procedimentos para quando sair da corda
  }
  pthread_exit(0);
}

int main(int argc, char * argv[])
{
  pthread_mutex_init(&lock_a, NULL);
  pthread_mutex_init(&lock_b, NULL);
  pthread_mutex_init(&lock_turno, NULL);

  pthread_t macacos[MA+MB];
  pthread_t g1, g2;

  int *id;
  int i = 0;

  for(i = 0; i < MA+MB; i++){
    id = (int *) malloc(sizeof(int));
    *id = i;

    if(i%2 == 0){
      if(pthread_create(&macacos[i], NULL, &macacoAB, (void*)id)){
        printf("Não pode criar a thread %d\n", i);
        return -1;
      }
    } else {
      if(pthread_create(&macacos[i], NULL, &macacoBA, (void*)id)){
        printf("Não pode criar a thread %d\n", i);
        return -1;
      }
    }
  }

  for (; i < MA+MB+2; i++) {
    id = (int *) malloc(sizeof(int));
    *id = i;

    if (i%2 == 0)
      pthread_create(&g1, NULL, &gorilaAB, (void*) id);
    else
      pthread_create(&g2, NULL, &gorilaBA, (void*) id);
  }

  for (int i = 0; i < MA+MB; i++) {
    pthread_join(macacos[i], NULL);
  }

  return 0;
}

