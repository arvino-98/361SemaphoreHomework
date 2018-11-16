#include <stdio.h>
#include <unistd.h>
#include "common_threads.h"

sem_t s;

void *child(void *arg) {
    printf("child\n");
    sem_post(&s); // use semaphore here
    sleep(1);
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t p;
    sem_init(&s, 0, 0); // init semaphore here
    printf("parent: begin\n");
    Pthread_create(&p, NULL, child, NULL);
    sem_wait(&s); // use semaphore here
    printf("parent: end\n");
    return 0;
}
