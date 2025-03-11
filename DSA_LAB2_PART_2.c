#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int stack1[MAX_SIZE];
    int stack2[MAX_SIZE];
    int top1;
    int top2;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->top1 = -1;
    queue->top2 = -1;
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->stack1[++(obj->top1)] = x;
}

int myQueuePop(MyQueue* obj) {
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->stack2[++(obj->top2)] = obj->stack1[(obj->top1)--];
        }
    }
    return obj->stack2[(obj->top2)--];
}

int myQueuePeek(MyQueue* obj) {
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->stack2[++(obj->top2)] = obj->stack1[(obj->top1)--];
        }
    }
    return obj->stack2[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->top1 == -1 && obj->top2 == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

int main() {
    MyQueue* myQueue = myQueueCreate();
    myQueuePush(myQueue, 1);
    myQueuePush(myQueue, 2);
    printf("Peek: %d\n", myQueuePeek(myQueue)); // returns 1
    printf("Pop: %d\n", myQueuePop(myQueue));   // returns 1
    printf("Empty: %d\n", myQueueEmpty(myQueue)); // returns false
    myQueueFree(myQueue);
    return 0;
}
