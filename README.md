# Thread Library

Thread Library is a simple C library that provides basic threading functionalities. It allows you to create threads with or without argument, set thread priorities and more.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)

## Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/AbhishekRana21/ThreadLibrary.git
    ```

2. Change the directory:

    ```bash
    cd ThreadLibrary
    ```

3. Compile the source files:

    ```bash
    gcc ThreadLibrary.c sample.c -o exe
    ```

4. Run the executable:

    ```bash
    ./exe
    ```

## Usage

Include the `ThreadLibrary.h` header file in your project and link the compiled `ThreadLibrary.c` file. Initialize the library with `initThreadLibrary()` and start creating and managing threads.

## Examples

### Creating Threads

#### Normal Thread

```c
#include "ThreadLibrary.h"
#include <stdio.h>

void normalThread(void) {
    printf("Normal thread is running\n");
    printf("Thread ID = %d\n", getID());
}

int main(void) {
    initThreadLibrary();
    int priority = 0;
    int thread1 = createThread(normalThread, priority);

    start();

    return 0;
}
```

#### Thread with Argument

```c
#include "ThreadLibrary.h"
#include <stdio.h>

void *threadWithArg(void *arg) {
    int *value = (int *)arg;
    printf("Thread with argument is running\n");
    printf("Thread ID = %d\n", getID());
    printf("Argument value = %d\n", *value);
}

int main(void) {
    initThreadLibrary();
    int priority = 1, value = 7;
    int thread2 = createThreadWithArg(threadWithArg, &value, priority);

    start();

    return 0;
}
```
