#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "pthread.h"

#define N 4
#define X 100000

int contador = 0;
int contador_unsafe = 0;

pthread_mutex_t lock_contador = PTHREAD_MUTEX_INITIALIZER;


void * incrementar(void * arg){
    int id = *((int *) arg); 
    printf("Criou um pthread com id = %d \n",id);
    int i = 0;
    for(i = 0; i < X; i++){
          //PEGAR O LOCK
          pthread_mutex_lock(&lock_contador);
          contador++;
          //LIBERAR O LOCK
          pthread_mutex_unlock(&lock_contador);
          contador_unsafe++;
    }
    pthread_exit(0);    
}

int main() {
   //pthread_mutex_init(&lock_contador,NULL);

   pthread_t a[N];
   int i;
   int * id;
   for (i = 0; i < N ; i++) {
        id = (int *) malloc(sizeof(int));
        *id = i;
        pthread_create(&a[i], NULL, incrementar, (void *) (id));
   }

  for (i = 0; i < N ; i++) {
      pthread_join(a[i],NULL);
  }
  printf("Valor final do contador = %d\n",contador); 
  printf("Valor final do contador_unsafe = %d\n",contador_unsafe); 
  printf("FIM!!!\n");
  return 0;
}

















