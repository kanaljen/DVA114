#ifndef STACK_H
#define STACK_H

typedef int Data;	

/* 1. Välj implementation. *****************************/
/*    Avkommentera exakt en av dessa två rader.        */

#define STACK_LIST_IMP // Avkommentera denna rad om stacken ska implementeras som en länkad lista
//#define STACK_ARRAY_IMP // Avkommentera denna rad om stacken ska implementeras som en array



/* 2A. Om stacken implementeras som en länkad lista *************************/

#ifdef STACK_LIST_IMP
#include "list.h"		// Er lista inkluderas
typedef List Stack;     // Ordet 'Stack' kommer att vara er listtyp
#else



/* 2B. Om stacken implementeras som en array ********************************/

#ifdef STACK_ARRAY_IMP
#define MAXLENGTH 20
struct arrayStack
{
	Data elements[MAXLENGTH];				// Detta är arrayen av element

	/* 2B: Lägg till fler struct-medlemmar om det behövs */
};
typedef struct arrayStack Stack;	// Ordet 'Stack' kommer att vara denna struct-typ



/* Ignorera detta (men ta inte bort det) *************************************/
#else
typedef int Stack;	// Ingen implementation, används ej
#endif
#endif
/*****************************************************************************/


/* 3. Interface ****************************************************************/
/* Detta får inte ändras på något vis. Typen 'Stack' kommer att bero på vilken */
/* Implementation ni valt.                                                     */

// Skapar en ny tom stack
Stack initializeStack(void);

// Returnerar 1 om stacken är tom, 0 annars
int stackIsEmpty(const Stack stack);

// Returnerar 1 om stacken är full, 0 annars 
int stackIsFull(const Stack stack);

// Lägger ett element överst på stacken
void push(Stack* pStack, const Data element);

// Tar bort det översta elementet från stacken
void pop(Stack* pStack);

// Returnerar det översta elementet på stacken
Data peekStack(const Stack stack);


#endif // Ska vara sist
