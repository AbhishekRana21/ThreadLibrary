# Thread Library

Thread Library is a simple C library that provides basic threading functionalities. It allows you to create threads with or without arguments, set thread priorities and more.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)

## Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/your-username/thread-library.git
    ```

2. Compile the source files:

    ```bash
    gcc ThreadLibrary.c sample.c -o exe
    ```

3. Run the executable:

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
    for (int i = 0; i < 5; ++i) {
        printf("Thread %d: %d\n", getID(), i);
    }
}

int main(void) {
    initThreadLibrary();
    int priority = 0;
    int thread1 = createThread(normalThread, priority);

    start();

    return 0;
}
```

#### Thread with Arguments

```c
#include "ThreadLibrary.h"
#include <stdio.h>

void *threadWithArgs(void *arg) {
    int *value = (int *)arg;
    for (int i = 0; i < 5; ++i) {
        printf("Thread %d: %d\n", getID(), *value);
    }
    return NULL;
}

int main(void) {
    initThreadLibrary();
    int priority = 1, value = 7;
    int thread2 = createThreadWithArgs(threadWithArgs, &value, priority);

    start();

    return 0;
}
```
