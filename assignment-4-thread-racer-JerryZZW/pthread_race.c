#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

#define NUM_THREADS 10

int my_global = 0;
void *func(void *arg);

/**
 * Can use the following struct for
 * the nanosleep function.
 * the first value is sleep time in seconds
 * the second vaue is sleep time in nanoseconds.
 *
 * struct timespec ts = {2, 0 };
 *
 * you can call nano sleep as nanosleep(&ts, NULL);
*/

struct timespec ts = {2, 0 };

int main() {

  pthread_t tid;

  for(int i = 0; i < NUM_THREADS; i++) {
    pthread_create(&tid, NULL, func, (void *)i);
  }

  pthread_join(tid, NULL);
  fprintf(stderr, "Final global counter: %d\n", my_global);

  return 0;
}

void *func(void *arg) {
  int myid = (int)arg;
  int my_local;

  fprintf(stderr, "hello I’m thread #%d's message:\n", myid);

  my_local = my_global;
  fprintf(stderr, "Thread id: %d, local thread variable: %d\n", myid, my_local);
  nanosleep(&ts, NULL);

  my_local += 10;
  fprintf(stderr, "Thread id: %d, new local thread variable: %d\n", myid, my_local);
  nanosleep(&ts, NULL);

  my_global = my_local;
  pthread_exit(0);
}
