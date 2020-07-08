#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H
//#define NULL 0
typedef struct _node {
    char c[2];
    struct _node *prev;
    struct _node *next;
} Node;

typedef struct {
    Node *head;
    int length;
} List;

List list_create();
Node* list_find(List *list, int x);
void list_insert(List *list, int x, char c);
void list_remove(List *list, int x);

#endif