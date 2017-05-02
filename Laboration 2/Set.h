#ifndef SET_H
#define SET_H

typedef int Data;

/* 1. Välj implementation. *****************************/
/*    Avkommentera exakt en av dessa två rader.        */

#define SET_LIST_IMP // Avkommentera denna rad om ni vill implementera set som en länkad lista
//#define SET_ARRAY_IMP // Avkommentera denna rad om ni vill implementera set som en array

/* 2A. Om Set implementeras som en länkad lista *************************/
#ifdef SET_LIST_IMP
#include "list.h"	// Er lista inkluderas
typedef List Set;   // Ordet 'Set' kommer att referera till er listtyp
#else



/* 2B. Om Set implementeras som en array ********************************/
#ifdef SET_ARRAY_IMP
#define MAXLENGTH 20
struct arraySet
{
	Data data[MAXLENGTH];
	/*2B: lägg till fler struct-medlemmar ifall det behövs */
};
typedef struct arraySet Set; // Ordet 'Set' kommer att referera till denna struct



/* Ignorera detta (men ta inte bort det) *************************************/
#else
typedef int Set; // Används ej
#endif
#endif
/*****************************************************************************/




/* 3. Interface ****************************************************************/
/* Detta får inte ändras på något vis. Typen 'Set' kommer att bero på vilken   */
/* Implementation ni valt.                                                     */

// Skapar ett nytt set som inte innehåller några element
Set initializeSet(void);

// Lägger till ett element till settet, om elementet redan finns händer inget
void addToSet(Set* set, const Data element);

// Tar bort ett element till settet, om elementet inte finns händer inget
void removeFromSet(Set* set, const Data element);

// Returerar 1 ifall 'element' finns i 'set' och 0 annars
int isInSet(const Set set, const Data element);

// Returnerar 1 ifall det inte går att lägga till fler element till set, 0 annars
int isSetFull(const Set set);

#endif
