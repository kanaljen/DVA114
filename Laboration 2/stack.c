#include "stack.h"
#include<assert.h>


Stack initializeStack(void)
{
	return createList(); // Ersätt denna rad med rätt returvärde
}

int stackIsEmpty(const Stack stack)
{
	return listIsEmpty(stack); // Ersätt denna rad med rätt returvärde
}

int stackIsFull(const Stack stack)
{
    int size = 0;
    
    
    if(listIsEmpty(stack) == 1)return 0; //Stacken Šr tom
    
    Stack nextNode = stack->next;
    
    while(nextNode != NULL){ // Stegar i stacken
        nextNode = nextNode->next;
        size++;
    }
    
    if(nextNode == NULL)size++; //The botten is nŒdd
    
    if(size>25)return 1; //25 godtycklig storlek pŒ stacken

    return 0;
    
}

void push(Stack* stack, const Data data)
{
	// Precondition: stacken får inte vara full
    assert(stackIsFull(*stack)!=1);
    
    *stack = addFirstElement(*stack,data);
    
	// Postcondition 'data' ligger överst på stacken
    assert(peekStack(*stack)== data);
}

void pop(Stack* stack)
{
	// Precondition: stacken får inte vara tom
    assert(stackIsEmpty(*stack) != 1);
    
    *stack = removeFirstElement(*stack);
    
}

Data peekStack(const Stack stack)
{
	// Precondition: stacken får inte vara tom
    assert(stackIsEmpty(stack) != 1);
    
    
	return stack->data; // Ers'tt denna rad med rätt returvärde
}
