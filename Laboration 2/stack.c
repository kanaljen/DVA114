#include "stack.h"
#include<assert.h>


Stack initializeStack(void)
{
	return createList(); // Ers�tt denna rad med r�tt returv�rde
}

int stackIsEmpty(const Stack stack)
{
	return listIsEmpty(stack); // Ers�tt denna rad med r�tt returv�rde
}

int stackIsFull(const Stack stack)
{
    int size = 0;
    
    
    if(listIsEmpty(stack) == 1)return 0; //Stacken �r tom
    
    Stack nextNode = stack->next;
    
    while(nextNode != NULL){ // Stegar i stacken
        nextNode = nextNode->next;
        size++;
    }
    
    if(nextNode == NULL)size++; //The botten is n�dd
    
    if(size>25)return 1; //25 godtycklig storlek p� stacken

    return 0;
    
}

void push(Stack* stack, const Data data)
{
	// Precondition: stacken f�r inte vara full
    assert(stackIsFull(*stack)!=1);
    
    *stack = addFirstElement(*stack,data);
    
	// Postcondition 'data' ligger �verst p� stacken
    assert(peekStack(*stack)== data);
}

void pop(Stack* stack)
{
	// Precondition: stacken f�r inte vara tom
    assert(stackIsEmpty(*stack) != 1);
    
    *stack = removeFirstElement(*stack);
    
}

Data peekStack(const Stack stack)
{
	// Precondition: stacken f�r inte vara tom
    assert(stackIsEmpty(stack) != 1);
    
    
	return stack->data; // Ers'tt denna rad med r�tt returv�rde
}
