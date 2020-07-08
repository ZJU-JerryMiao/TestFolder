#include "linkedlist.h"
#include <stdlib.h>
List list_create() //list initialize
{
    List Temp;
    Temp.head = malloc(sizeof(Node));
    Temp.head->next = NULL;
    Temp.head->prev = NULL;
    Temp.length = 0;
    Temp.head->c[0] = ' ';
    Temp.head->c[1] = '\0';
    return Temp;
}

Node* list_find(List *list, int x)
{
    int cnt = 0;
    Node * temp = list->head;
    while(cnt < x){
        temp = temp->next;
        cnt++;
    }
    return temp;
}

void list_insert(List *list, int x, char c)
{
    //initialize insert node
    Node* p = (Node*)malloc(sizeof(Node));
    p->c[0] = c;
    p->c[1] = '\0';
    p->next = NULL;
    p->prev = NULL;
    //find position
    Node* temp = list_find(list, x);
    //insert possess
    if(x == list->length){//list tail
        //temp <-> p
        temp->next = p;
        p->prev = temp;
        //renew length
        list->length++;
    }else if(x < list->length && x >= 0){ //not tail
        //p <-> old
        p->next = temp->next;
        temp->next->prev = p;
        //temp <-> p
        temp->next = p;
        p->prev = temp;
        //renew length
        list->length++;
    }
}

void list_remove(List *list, int x)
{
    //find position
    Node* temp = list_find(list, x);
    //remove process
    if(x > 0 && x <= list->length){
        temp->prev->next = temp->next;
        if(temp->next){ //not tail
            temp->next->prev = temp->prev;
        }
        free(temp);
        list->length--; //renew length
    }
}