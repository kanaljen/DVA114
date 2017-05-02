#define _CRT_SECURE_NO_WARNINGS // Behövs för vissa funktioner i visual studio
#include "HashTable.h"
#include "Bucket.h"
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>

#define UNUSED 0	// Används för att markera en ledig plats i Hashtabellen


/* Denna funktion tar en nyckel och returnerar ett hash-index
dvs ett index till arrayen som är Hashtabellen */

static int hash(Key key, int tablesize)
{

	return key % tablesize; // Ersätt med ett index

}

static void freeNodes(List* list){

    if(*list != NULL){

        if((*list)->next != NULL)freeNodes(&(*list)->next);

    }

    free(*list);

    *list = NULL;

};


HashTable createHashTable(unsigned int size)
{

    HashTable newTable;

    newTable.table = malloc(sizeof(struct node) * size);

    newTable.size = size;

	return newTable;

}

void insertElement(HashTable* htable, const Key key, const Value value)
{

    int hashKey = hash(key,htable->size);

    if(lookup(htable,key) != NULL)deleteElement(htable,key);

    Data newBucket;

    newBucket.key = key;
    newBucket.value = value;

    htable->table[hashKey] = addFirstElement(htable->table[hashKey],newBucket);

}

void deleteElement(HashTable* htable, const Key key)
{

    removeElement(&htable->table[hash(key,htable->size)],key);

}

const Value* lookup(const HashTable* htable, const Key key)
{
    if(searchElement(htable->table[hash(key,htable->size)],key) == 0)return NULL;

    return &htable->table[hash(key,htable->size)]->data.value; // Ersätt med rätt värde
}

unsigned int getSize(const HashTable* htable)
{

    return htable->size; // Ersätt med rätt värde

}

void freeHashTable(HashTable* htable)
{
    for(int i = 0; i < htable->size ; i++){

        freeNodes(&htable->table[i]);

    }


    free(htable->table);

    htable->table = NULL;

    htable->size = 0;
	// Postcondition: hashtabellen har storlek 0
}

void printHashTable(const HashTable* htable)
{
    printf("START OF TABLE\n\n");

    for (int i = 0; i < htable->size; i++) {
        printf("---------------------\n");
        printf("Key: %d \n",i);
        printList(htable->table[i]);
        printf("---------------------\n");
    }
    printf("END OF TABLE\n");

	// Tips: använd printPerson() i Person.h för att skriva ut en person
}
