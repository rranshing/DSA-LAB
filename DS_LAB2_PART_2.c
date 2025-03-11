#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void stackInit(Stack *s) {
    s->top = -1;
}

bool stackEmpty(Stack *s) {
    return s->top == -1;
}

void stackPush(Stack *s, int x) {
    if (s->top < MAX_SIZE - 1) {
        s->data[++s->top] = x;
    }
}

int stackPop(Stack *s) {
    if (!stackEmpty(s)) {
        return s->data[s->top--];
    }
    return -1; // Error case
}

int stackTop(Stack *s) {
    if (!stackEmpty(s)) {
        return s->data[s->top];
    }
    return -1; // Error case
}

typedef struct {
    Stack stack1;
    Stack stack2;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue *q = (MyQueue*)malloc(sizeof(MyQueue));
    stackInit(&q->stack1);
    stackInit(&q->stack2);
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    stackPush(&obj->stack1, x);
}

int myQueuePop(MyQueue* obj) {
    if (stackEmpty(&obj->stack2)) {
        while (!stackEmpty(&obj->stack1)) {
            stackPush(&obj->stack2, stackPop(&obj->stack1));
        }
    }
    return stackPop(&obj->stack2);
}

int myQueuePeek(MyQueue* obj) {
    if (stackEmpty(&obj->stack2)) {
        while (!stackEmpty(&obj->stack1)) {
            stackPush(&obj->stack2, stackPop(&obj->stack1));
        }
    }
    return stackTop(&obj->stack2);
}

bool myQueueEmpty(MyQueue* obj) {
    return stackEmpty(&obj->stack1) && stackEmpty(&obj->stack2);
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

int main() {
    MyQueue* myQueue = myQueueCreate();
    myQueuePush(myQueue, 1);
    myQueuePush(myQueue, 2);
    printf("Peek: %d\n", myQueuePeek(myQueue)); // Should print 1
    printf("Pop: %d\n", myQueuePop(myQueue));   // Should print 1
    printf("Empty: %d\n", myQueueEmpty(myQueue)); // Should print 0 (false)
    myQueueFree(myQueue);
    return 0;
}
