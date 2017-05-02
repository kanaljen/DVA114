/* Laboration 2 - Datastrukturer och Algoritmer */
/* Länkad lista */

#ifndef LIST_H
#define LIST_H

#include "Bucket.h"

typedef struct Bucket Data;

/* 1. Struct-definitioner ********************************/
/*                                                       */
/* Lägg era struct-definitioner nedan                    */
/* Ni kan göra en enkellänkad eller dubbellänkad         */
/* lista. Ni får också välja hur ni vill representera    */
/* listan (nodpekare eller strukt).                      */
/*********************************************************/

struct node{
    
    Data data;
    
    struct node *next;
    
};

/* 2. Typdefinition **************************************/
/* Ersätt ordet 'int' nedan med den typ ni valt          */
/* T.ex:											     */
/* typedef struct node* List;                            */
/* eller											     */
/* typedef struct list List;                             */
/* *******************************************************/

typedef struct node *List;	// Obs: ändra ej namnet "List", det kommer att användas i kommande lab

/* 3. Interface ****************************************************/
/* Här lägger ni era funktionsdeklarationer för er länkade lista   */
/* Läs labbinstruktioner för vilka som ska vara med                */
/*																   */		
/* OBS:															   */
/* ALLA funktioner i interfacet måste returnera eller ta ett       */
/* argument av typen List eller List*                              */
/* *****************************************************************/

List createList();

int listIsEmpty(const List list);

List createNode();

List addFirstElement(List head,const Data input);

List addLastElement(List head,const Data input);

List removeFirstElement(List head);

List removeLastElement(List head);

void removeElement(List *bucket,const int rem);

int searchElement(List head,Key key);

void printList(List head);

#endif // Ska vara sist
