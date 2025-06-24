#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *threadFunction1(void *arg) {
    for (int i = 1; i <= 5; i++) {
        printf("Thread 1: %d\n", i);
        sleep(1);
    }
    return NULL;
}

void *threadFunction2(void *arg) {
    for (int i = 1; i <= 5; i++) {
        printf("Thread 2: %d\n", i);
        sleep(1); 
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, threadFunction1, NULL);
    pthread_create(&t2, NULL, threadFunction2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Both threads finished.\n");

    return 0;
}

