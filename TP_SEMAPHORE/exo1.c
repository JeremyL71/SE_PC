#include <pthread.h>
#include <stdio.h>
#define MAX 100000

int counter = 0;

void* count(void* data) {
    int i;
    for (i = 0; i < MAX; i++) counter++;
}

int main () {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, count, NULL); // create first thread
    pthread_create(&t2, NULL, count, NULL); // create second thread
    pthread_join(t1, NULL); // wait for first thread
    pthread_join(t2, NULL); // wait for second thread
    printf("Counter: %d\n", counter);
}