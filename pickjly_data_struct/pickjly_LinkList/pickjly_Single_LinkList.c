#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct Node{
    datatype elem;
    struct Node *next;
}_linklist;

_linklist* initlink();                                          // 初始化链表
_linklist* createNode();                                        // 创建一个节点

void addHeadnode(_linklist *linklist, datatype data);                // 向开始位置插入节点
void addTailnode(_linklist *linklist, datatype data);                // 向最后位置插入节点
void addpositionnode(_linklist *_linklist, datatype data, int position);    // 向制定位置插入节点

void delnodebyposition(_linklist *linklist, int position);                // 删除指定位置节点
void delnodebydata(_linklist* _linklist, datatype data);                  // 删除指定值节点

void printlinklist(_linklist *linklist);                        // 打印链表

_linklist* initlink() {
    _linklist *head = (_linklist *)malloc(sizeof(_linklist));
    // head->elem = 0;
    head->next = NULL;
    return head;  
}

void addHeadnode(_linklist *linklist, datatype data) {
    _linklist *Node = createNode();
    Node->elem = data;
    Node->next = linklist->next;
    linklist->next = Node;
}

void addTailnode(_linklist *linklist, datatype data){
    _linklist *Node = (_linklist *)malloc(sizeof(_linklist));
    while (linklist->next != NULL) {
        linklist = linklist->next;
    }
    linklist->next = Node;
    Node->elem = data;
}

void printlinklist(_linklist *linklist) {
    if (linklist->next == NULL) {
        printf("\n");
    } else {
        printf("\t%d", linklist->next->elem);
        printlinklist(linklist->next);
    }
}

_linklist* createNode() {
    _linklist *Node = (_linklist*)malloc(sizeof(_linklist));
    Node->elem = 0;
    Node->next = NULL;
}

void delnodebydata(_linklist* linklist, datatype data) {
    _linklist* froNode = linklist;

    if ( NULL == froNode->next ) {
        printf(" Error occured while looking for the data \n");
        free(froNode);
        froNode = NULL;
    } else {
        if (froNode->next->elem == data) {
            froNode->next = froNode->next->next;
        } else {
            froNode = froNode->next;
            delnodebydata(froNode, data);
        }
    }
}

void destroylinklist(_linklist* linklist) {
    if (linklist -> next != NULL) {
        destroylinklist(linklist->next);
    }
    free(linklist);
    linklist = NULL;
}

int main() {
    _linklist *linklist = initlink();
    addHeadnode(linklist, 1);
    addHeadnode(linklist, 2);
    addHeadnode(linklist, 3);
    addHeadnode(linklist, 4);
    addHeadnode(linklist, 5);
    addHeadnode(linklist, 6);
    addHeadnode(linklist, 7);
    addHeadnode(linklist, 8);
    printlinklist(linklist);
    addHeadnode(linklist, 9);
    printlinklist(linklist);
    addTailnode(linklist, 10);
    printlinklist(linklist);
    delnodebydata(linklist, 3);
    printlinklist(linklist);
    destroylinklist(linklist);
    return 1;
}