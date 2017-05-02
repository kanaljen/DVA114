#define _CRT_SECURE_NO_WARNINGS // Beh�vs i Visual studio f�r att till�ta vissa funktioner
#include "Person.h"
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

static void getRandomName(char* name)
{
	assert(name != NULL);

	char* names[] = { "Stefan", "Anna" , "Bengt", "Sture", "Johan", "Therese", "Alva", "Lisa", "Emma", "Linnea", "Lena", "Johanna",
		"Moa", "Per", "Alex", "Fredrik", "Kent", "Tobias", "Malin", "Sara", "Ida", "Hanna", "Sixten", "Borje" };

	const int numberOfNames = sizeof(names) / sizeof(char*);
	int index = rand() % numberOfNames;
	strcpy(name, names[index]);
}

static int getRandomPersonalNumber(void)
{
	int day = rand() % 30 + 1; // F�r enkelhetens skull antar vi att vaje m�nad har 30 dagar (blir vissa om�jliga datum i februari, men det �r inte viktigt h�r)
	int month = rand() % 12 + 1;
	int year = rand() % 60 + 40;
	return day + 100 * month + 10000 * year;
}

Person getRandomPerson(void)
{
	Person randomPerson;
	getRandomName(randomPerson.name);
	randomPerson.personalNumber = getRandomPersonalNumber();
	randomPerson.weight = (float)(rand() % 70 + 50);
	return randomPerson;
}

void printPerson(Person* personToPrint)
{
	printf("%d: %s, weight: %f ", personToPrint->personalNumber, personToPrint->name, personToPrint->weight);
}
