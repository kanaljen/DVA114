/* Laboration 2 - Datastrukturer och Algoritmer */
/* L�nkad lista */

#ifndef LIST_H
#define LIST_H

#include "Bucket.h"

typedef struct Bucket Data;

/* 1. Struct-definitioner ********************************/
/*                                                       */
/* L�gg era struct-definitioner nedan                    */
/* Ni kan g�ra en enkell�nkad eller dubbell�nkad         */
/* lista. Ni f�r ocks� v�lja hur ni vill representera    */
/* listan (nodpekare eller strukt).                      */
/*********************************************************/

struct node{
    
    Data data;
    
    struct node *next;
    
};

/* 2. Typdefinition **************************************/
/* Ers�tt ordet 'int' nedan med den typ ni valt          */
/* T.ex:											     */
/* typedef struct node* List;                            */
/* eller											     */
/* typedef struct list List;                             */
/* *******************************************************/

typedef struct node *List;	// Obs: �ndra ej namnet "List", det kommer att anv�ndas i kommande lab

/* 3. Interface ****************************************************/
/* H�r l�gger ni era funktionsdeklarationer f�r er l�nkade lista   */
/* L�s labbinstruktioner f�r vilka som ska vara med                */
/*																   */		
/* OBS:															   */
/* ALLA funktioner i interfacet m�ste returnera eller ta ett       */
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
