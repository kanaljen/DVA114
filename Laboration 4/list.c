#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Skriv era funktionsimplementationer för interfacet till er länkade lista här 
   Det går också bra att skriva statiska hjälpfunktioner i denna fil            */


List createList(){
    
    return NULL;
    
};

int listIsEmpty (const List list){
    
    if(list == NULL) return 1;
    if(list != NULL) return 0;
    
    return 0;
    
};

List createNode(){
    
    List newNode;
    
    newNode = malloc(sizeof(struct node));

    return newNode;
    
};

List addFirstElement(List head,const Data input){
    
    List newNode;
    
    newNode = createNode();
    newNode->data = input;
    newNode->next = head;
    
    return newNode;
    
};

List addLastElement(List head,const Data input){
    
    List newNode;
    
    if(head == NULL)return addFirstElement(head,input);
    
    if(head->next == NULL){
            
        newNode = createNode();
        newNode->data = input;
        newNode->next = NULL;
        head->next = newNode;
        
    }
    
    else addLastElement(head->next,input);

    return head;
};

List removeFirstElement(List head){
    
    if(head == NULL)return NULL;
    
    List temp = head->next;
    free(head);
    return temp;
    
};


List removeLastElement(List head){
    
    if(head == NULL)return NULL;
    
    if(head->next == NULL)return removeFirstElement(head);
    
    if(head->next->next == NULL){
        
        free(head->next);
        head->next = NULL;
        
    }
    
    else removeLastElement(head->next);
    
    return head;
    
};

void removeElement(List *bucket,const int rem){
    
    if(bucket != NULL){

        if((*bucket)->data.key == rem){

            List temp = (*bucket)->next;

            free(*bucket);

            *bucket = temp;

        }

        else removeElement(&(*bucket)->next,rem);

    }
    
};

int searchElement(List head,Key key){
    
    if(head == NULL)return 0;
    
    if(head->data.value.personalNumber == key)return 1;
    
    else if(head->next == NULL)return 0;
    
    return searchElement(head->next,key);
    
};

void printList(List head){

    if(head != NULL){

        printf("%d %s %.2f\n",head->data.value.personalNumber,head->data.value.name,head->data.value.weight);

        if(head->next != NULL)printList(head->next);
    }
    
};