#ifndef THREADLIBRARY_H
#define THREADLIBRARY_H

#include <ucontext.h>
#include <time.h>

#define MAX_THREADS 10
#define STACK_SIZE 4096
#define DEFAULT_PRIORITY 0

enum ThreadStatus {
    READY,
    RUNNING,
    BLOCKED,
    FINISHED
};

struct statistics {
    int ID;
    enum ThreadStatus state;
    int burst;
    int total_exec_time;
    int total_slp_time;
    float avg_time_quant;
    float avg_wait_time;
    int RedTimeTotal;
    clock_t RunTimeStart;
    clock_t RedTimeStart;
};

typedef struct {
    ucontext_t context;
    int id;
    enum ThreadStatus status;
    int priority;
    void (*function)(void);
    void *(*argFunction)(void *);
    void *arg;
    void *result;
    int joinID;
    int mutex;  // Simple mutex (0: unlocked, 1: locked)
    struct statistics stat;
} Thread;

void initThreadLibrary(void);
int createThread(void (*function)(void), int);
int createThreadWithArgs(void *(*function)(void *), void *arg, int);
void yieldThread(void);
void runThread(int threadID);
void runScheduler(void);
void start(void);
void lockMutex(int threadID);
void unlockMutex(int threadID);
void waitCondition(int threadID, int conditionVariable);
void signalCondition(int conditionVariable);
void setThreadPriority(int threadID, int priority);
void deleteThread(int threadID);
void sleepThread(int sec);
struct statistics *getThreadStatus(int threadID);
int getID(void);
void cleanThread(void);
void joinThread(int threadID);

#endif
