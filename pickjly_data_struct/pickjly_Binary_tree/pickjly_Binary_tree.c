#include <stdio.h>
#include <stdlib.h>

typedef int elemtype;

typedef struct BinaryTreeNode {
    struct BinaryTreeNode *leftchild;
    struct BinaryTreeNode *rightchild;
    elemtype elem;
}_Node;

_Node* createNode(elemtype data) {
    _Node *node = (_Node*)malloc(sizeof(_Node));
    node ->leftchild = NULL;
    node ->rightchild = NULL;
    node ->elem = data;

    return node;
}

typedef struct Tree {
    int depth;
    int rootNode_flag;
    _Node *rootNode;
}_tree;

_tree* InitTree_without_root () {
    _tree *tree = (_tree *) malloc (sizeof(_tree));
    tree->rootNode = (_Node*)malloc(sizeof(_Node));
    
    tree->rootNode->leftchild = NULL;
    tree->rootNode->rightchild = NULL;
    tree->depth = 0;
    tree->rootNode_flag = -1;

    return tree;
}

_tree* InitTree_with_root (elemtype data) {
    _tree *tree = (_tree *) malloc (sizeof(_tree));
    tree->rootNode = (_Node*)malloc(sizeof(_Node));
    
    tree->rootNode->leftchild = NULL;
    tree->rootNode->rightchild = NULL;
    tree->depth = 0;
    tree->rootNode_flag = 1;
    tree->rootNode->elem = data;

    return tree;
}

void destroyNode(_Node *node) {
    if ( NULL == node) {
        printf(" this node is null\n");
    } else {
        if ( NULL == node ->leftchild && NULL == node->rightchild) {
            free(node);
            node = NULL;
        } else if( NULL == node->leftchild && NULL != node->rightchild) {
            destroyNode(node->rightchild);
        } else if (NULL != node->leftchild && NULL == node->rightchild) {
            destroyNode(node->leftchild);
        } else {
            destroyNode(node->rightchild);
            destroyNode(node->leftchild);
        }
    }
}

void destroyTree(_tree* tree) {
    if (tree == NULL) {
        printf(" thid tree is NULL\n");
    } else {
        if (tree->rootNode == NULL) {
            printf(" this tree does not init");
        } else {
            destroyNode(tree->rootNode);
            free(tree);
            tree = NULL;
        }
    }
}

int getNodedepth(_Node* node) {
    if (node == NULL) {
        return 0;
    } else {
        int length = 0;
        length ++;
        if ( node->leftchild != NULL || node->rightchild != NULL) {
            return length+=getNodedepth();
        }
    }
}

int getTreeDepth(_tree *tree) {
    if ( NULL == tree) {
        printf(" this tree is NULL");
        return 0;
    } else {
        return getNodedepth(tree->rootNode);
    }
}

int main() {
    _tree *mytree = InitTree();
    destroyTree(mytree);
}