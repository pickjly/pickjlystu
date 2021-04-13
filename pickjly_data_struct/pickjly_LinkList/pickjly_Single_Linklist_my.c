#include <stdio.h>
#include <stdlib.h>

typedef int elemtype;

typedef struct Node {
    elemtype data;
    struct Node *next;
}_node;

_node* createNode (elemtype data) {
    _node *node = (_node *)malloc(sizeof(_node));
    node->data = data;
    node->next = NULL;

    return node;
}

typedef struct Linklist {
    int real_length;
    _node *Head;
}_linklist;

void initLinklist(_linklist *list) {
    list = (_linklist *) malloc (sizeof(_linklist));
    list->Head = NULL;
    list->real_length = 0;
}

void echolinklistInfo(_linklist *Linklist) {

}

void printlinklistdata(_linklist *Linklist) {

}

void addlinklistHeadelem(_linklist *Linklist, int data) {

}

void addlinklistTailelem(_linklist *Linklist, int data) {

}

void findlinklistelem(_linklist *Linklist, int data) {

}

void dellinklistHeadelem (_linklist *Linklist, int data) {

}

void dellinklistTailelem (_linklist *Linklist, int data) {

}

void linklistinversion(_linklist *Linklist) {

}

int destroyNode(_node* node) {
    if (node == NULL) {
        return 1;
    } else {
        if (node->next == NULL) {
            free(node);
            node->next = NULL;
        } else {
            destroyNode(node->next);
        }
    }
}

int destroylinklist(_linklist* Linklist) {
    if (Linklist == NULL) {
        return 1;
    } else {
        if (Linklist->Head->next == NULL) {
            free(Linklist);
            Linklist->Head = NULL;
            return 1;
        } else {
            while(Linklist->Head->next != NULL) {
                destroyNode(Linklist->Head->next);
            }
        }
    }
}

int main() {
    _linklist *mylist;
    initLinklist(mylist);
    destroylinklist(mylist);
}