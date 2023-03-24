#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List* list=(List*)malloc(sizeof(List));
  list->head=NULL;
  list->current=NULL;
     return list;
}

void * firstList(List * list) {
  if(!list->head) return NULL;
  list->current=list->head;
  return(list->head->data);
}

void * nextList(List * list) {
  if(!list) return NULL;
  if(!list->current) return NULL;
  if(!list->current->next) return NULL;
  list->current=list->current->next;
  return(list->current->data);
 
}

void * lastList(List * list) {
  if(!list->head) return NULL;
  list->current=list->tail;
  return(list->tail->data);
}

void * prevList(List * list) {
  if(!list) return NULL;
  if(!list->current) return NULL;
  if(!list->current->prev) return NULL;
  list->current=list->current->prev;
  return(list->current->data);
}

void pushFront(List * list, void * data) {
  Node* n= createNode(data);
  if(list->head)
  {
   n->next = list->head;
    list->head->prev=n;
    list->tail=list->head;
    list->head=n;
  }
  if(!list->head)
  {
    list->head=n;
    list->tail=list->head;
  }
  n->prev=NULL;  
  list->current++;
}

void pushBack(List * list, void * data) {
  Node* n= createNode(data);
  if(list->tail)
  {
   n->prev = list->tail;
    list->tail->next=n;
    //list->tail=list->head;
    list->tail=n;
  }
  if(!list->tail)
  {
    list->tail=n;
    //list->tail=list->head;
  }
  n->next=NULL;  
  list->current++;
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  Node* n= createNode(data);
  if(list->current)
  {
    list->current->next=n;
    n->prev=list->current;
  }
  if(list->current==list->tail)
  {
     n->prev = list->tail;
    list->tail->next=n;
    list->tail=n;
  }
  list->current++;
}

void * popFront(List * list) {
  void *popCurrent(List *list) { 
  
  if(list->current == NULL) return NULL;
  
  void* datoEliminado = list->current->data;
  
  
  if(list->current == list->head)
  {
    
    list->head = list->head->next;

    if(list->head->prev != NULL)
    {
      list->head->prev = NULL;
    }
    
  }
  else
  {
    list->current->prev->next = list->current->next;
    
  }
  
  if(list->current == list->tail)
  {
    
    list->tail = list->current->prev;
    list->tail->next = NULL;
  }
  else
  {
      
    list->current->next->prev = list->current->prev;
    
  }
  
  Node *nodoAux = list->current->next;
  
  free(list->current);

  list->current = nodoAux;

  return datoEliminado;
}
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}