#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACKSIZE 20

typedef int datatype;

typedef struct stackNode {
    datatype elem;
    struct stackNode *next;
}_stackNode;

typedef struct stack {
    int reallength;
    int size;
    _stackNode top;
}_stack;

_stack* initstack(datatype data) {
    _stack *stack = (_stack *)malloc(sizeof(_stack));
    stack->size = STACKSIZE;
    stack->reallength = 0;
    stack->top.next = NULL;
    stack->top.elem = data;

    return stack;
}

_stackNode* CreatestackNode() {
    _stackNode *Node = (_stackNode *)malloc(sizeof(_stackNode));
    Node->elem = 0;
    Node->next = NULL;
}

bool stackPush(_stack *stack, int data) {
    if ( NULL == stack) {
        printf(" this stack is not exist\n");
        return false;
    } else if (stack->size >= STACKSIZE) {
        printf(" this stack is full\n");
        return false;
    } else {
        _stackNode *node = CreatestackNode();
        node->next = stack->top.next;
    }
}

bool stackPop(_stack *stack) {
    if ( NULL == stack ) {
        printf(" this stack is NULL");
    } else if (stack.top.)
}

int main() {
    _stack *mystack = initstack();

}