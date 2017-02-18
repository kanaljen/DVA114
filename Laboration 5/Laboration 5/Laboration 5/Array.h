#ifndef ARRAY_H
#define ARRAY_H
#include <stdlib.h>
#include <stdio.h>

/********************************************************

DVA104, Lab 5, Array.h
Inneh�ller funktioner f�r att hantera dynamiska arrayer.

Stefan Bygde VT2016

*********************************************************/

#define SEED 245802 // Detta g�r att vi f�r samma osorterade array varje g�ng, f�r att vi l�tt ska kunna j�mf�ra. Man kan �ndra p� denna till vad som helst om man vill
typedef unsigned int ElementType;

// Avg�r om "array" �r sorterad eller ej
int isSorted(const ElementType* array, size_t size);

// Skapar arrayer av given storlek och sortering
// Notera att dessa arrayer �r dynamiskt allokerade och att minnet beh�ver frig�ras n�r man anv�nt dem f�rdigt
ElementType* createForwardSortedArray(size_t size);
ElementType* createBackwardSortedArray(size_t size);
ElementType* createUnsortedArray(size_t size);

// Skriver en array till fil
void printArray(const ElementType* array, size_t size, FILE* file);



#endif
