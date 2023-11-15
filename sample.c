#include "ThreadLibrary.h"
#include <stdio.h>

void normalThread(void) {
    printf("Normal thread is running\n");
    printf("Thread ID = %d\n", getID());
}

void *threadWithArg(void *arg) {
    int *value = (int *)arg;
    printf("Thread with argument is running\n");
    printf("Thread ID = %d\n", getID());
    printf("Argument value = %d\n", *value);
}

int main(void) {
    initThreadLibrary();
    int priority1 = 0, priority2 = 1, value = 7;
    int thread1 = createThread(normalThread, priority1);
    int thread2 = createThreadWithArg(threadWithArg, &value, priority2);

    start();

    return 0;
}
