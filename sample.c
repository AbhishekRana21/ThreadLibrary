#include "ThreadLibrary.h"
#include <stdio.h>

void normalThread(void) {
    for (int i = 0; i < 5; ++i) {
        printf("Thread %d: %d\n", getID(), i);
    }
}

void *threadWithArgs(void *arg) {
    int *value = (int *)arg;
    for (int i = 0; i < 5; ++i) {
        printf("Thread %d: %d\n", getID(), *value);
    }
    return NULL;
}

int main(void) {
    initThreadLibrary();
    int priority1 = 0, priority2 = 1, value = 7;
    int thread1 = createThread(normalThread, priority1);
    int thread2 = createThreadWithArgs(threadWithArgs, &value, priority2);

    start();

    return 0;
}
