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

int removeElement(List *head,const Data rem){
    
  List temp;
    
    if(head == NULL)return 0; //Listan Šr tom
    
    if(*head == NULL)return 0;
    
    if((*head)->data == rem){ //Elementet hittas fšrst
        temp = (*head)->next;
        free(*head);
        *head = temp;
        return 1;
    }
    
    else if ((*head)->data != rem || (*head)->next != NULL)removeElement(&(*head)->next,rem); //Om elementet ej hittas
    
    return 0;
    
};

int searchElement(List head,Data element){
    
    if(head == NULL)return 0;;
    
    if(head->data == element)return 1;
    
    else if(head->next == NULL)return 0;
    
    return searchElement(head->next,element);
    
};

int printList(List head,int num){
    
    if (num == 0)printf("START OF LIST\n");
    
    if (head == NULL){
        
        printf("END OF LIST\n");
        
    }
    
    else {
        
        num++;
        printf("%d Address: %p, Data: %d, Next: %p\n",num,head,head->data,head->next);
        num = printList(head->next,num);
        
    }
    
    return num;
    
};