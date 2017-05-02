#define _CRT_SECURE_NO_WARNINGS // Behövs i Visual studio för att tillåta vissa funktioner
#include "HashTable.h"

#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "Person.h"

static int addRandomPersonToTable(HashTable* htable)
{
	Person person = getRandomPerson();
	insertElement(htable, person.personalNumber, person);
	assert(lookup(htable, person.personalNumber)->personalNumber == person.personalNumber); // Se till att personnummret returnerar namnet
	return person.personalNumber;
}

void test(unsigned int tableSize)
{
	assert(tableSize >= 50); // Vi ska lägga till 50 personer så vi måste minst ha 50 platser

	HashTable htable = createHashTable(tableSize); // Vi gör storleken till ett primtal
	int personalNumbers[50];
	srand((unsigned int)time(0));

	assert(getSize(&htable) == tableSize);

	int i;
	for (i = 0; i < 50; i++)
	{
		int personalNumber = addRandomPersonToTable(&htable);
		personalNumbers[i] = personalNumber;
	}


	// Ta bort några existerande personer från tabellen
	for (i = 0; i < 10; i++)
	{
		deleteElement(&htable, personalNumbers[i]);
		assert(lookup(&htable, personalNumbers[i]) == NULL); // Det borttagna ska inte längre finnas i tabellen
	}

	// Slutligen lägger vi till några till
	for (i = 0; i < 10; i++)
	{
		addRandomPersonToTable(&htable);
	}

    printHashTable(&htable);

	freeHashTable(&htable);
	assert(getSize(&htable) == 0); 
}


int main(void)
{
	unsigned int size;
	do
	{
		printf("Ange storlek pa Hashtabellen (minst 50): ");
		scanf("%u", &size);
	} while (size < 50);


	test(size);





    getchar();

	return 0;
}