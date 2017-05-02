#include "list.h"
#include "Queue.h"
#include "stack.h"
#include "Set.h"
#include <assert.h>
#include <stdio.h>

void testQueue(void);
void testStack(void);
void testSet(void);
int listMenu(List*);
void flushInput();

int main(void)
{
	/* Uppgift 2.1: Avkommentera raden nedan när stacken är klar att testas */
	//testStack();

	/* Uppgift 2.2: Avkommentera raden nedan när kön är klar att testas */
	//testQueue();

	/* Uppgift 2.3: Avkommentera raden nedan när set är klar att testas */
	testSet();

	// Uppgift 2: kommentera bort listMenu() när ni vill testa ADT:erna */
    
    
    // Uppgift 1.4
    /*List* head;
    
    while(listMenu(head) != 0 )flushInput();*/

}

void flushInput(){
    
    int ch;
    while ((ch=getchar()) != EOF && ch != '\n');
    
}

int listMenu(List* head)
{
    
    int input,element;
    printf("MENU\n");
    printf("1. Create List\n");
    printf("2. Check if list is Empty\n\n");
    printf("3. Add element First\n");
    printf("4. Add Element Last\n\n");
    printf("5. Remove First element\n");
    printf("6. Remove Last element\n");
    printf("7. Remove element\n");
    printf("8. Search list for Element\n\n");
    printf("9. Print List\n\n");
    printf("0. Exit\n\n");
    
    scanf(" %d",&input);
    
    switch (input) {
        case 1:*head = createList();break;
        case 2:{
            if(listIsEmpty(*head) == 0){
                printf("List is NOT empty\n");
            }
            else printf("List IS empty\n");
            break;
        }
        case 3:{
            printf("Element to add: ");
            scanf(" %d",&element);
            *head = addFirstElement(*head,element);
            break;
        }
        case 4:{
            printf("Element to add: ");
            scanf(" %d",&element);
            *head = addLastElement(*head,element);
            break;
        }
        case 5:{
            *head = removeFirstElement(*head);
            break;
        }
        case 6:{
            *head = removeLastElement(*head);
            break;
        }
        case 7:{
            printf("Element to remove: ");
            scanf(" %d",&element);
            removeElement(head,element);
            break;
        }
        case 8:{
            printf("Element to search for: ");
            scanf(" %d",&element);
            element = searchElement(*head,element);
            if(element == 0)printf("No such element.\n");
            else printf("Element exist!\n");
            break;
        }
        case 9:printf("Total number of nodes: %d\n",printList(*head,0));break;
        case 0:return 0;
        default: return 1;
    }
    return 1;
}

void testQueue(void)
{
    Queue queue = initializeQueue();
	
	// Kön ska vara tom och inte full
	assert(queueIsEmpty(queue));
	assert(!queueIsFull(queue));

	int i;
	// Fyller kön med 1 2 3 4 5 6 7 8 9 10
	for (i = 1; i <= 10; i++)
		enqueue(&queue, i);

	assert(!queueIsEmpty(queue));
	assert(peekQueue(queue) == 1);	// 1 ska stå först i kön

	for (i = 0; i < 5; i++)
		dequeue(&queue);	// Ta bort de fem första i kön (bör vara 1,2,3,4 och 5)

	assert(!queueIsEmpty(queue));
	assert(peekQueue(queue) == 6);	// 6 bör alltså stå först i kön nu

	enqueue(&queue, 11);
	assert(peekQueue(queue) == 6);	// 6 bör fortfarande vara först i kön

	// Ta bort alla element
	for (i = 0; i < 6; i++) // Kön ska nu innehålla 6 element totalt
		dequeue(&queue);	

	// Återigen ska kön vara tom och inte full
	assert(queueIsEmpty(queue));
	assert(!queueIsFull(queue));

	// Lägg till och ta bort 100 element
	for (i = 0; i < 100; i++)
	{
		enqueue(&queue, i);
		assert(peekQueue(queue) == i);
		dequeue(&queue);	
		assert(queueIsEmpty(queue));
	}
}

void testStack(void)
{
	Stack stack = initializeStack();

	// Stacken ska vara tom och inte full
	assert(stackIsEmpty(stack));
	assert(!stackIsFull(stack));

	int i;
	// Fyller stacken med 1 2 3 4 5 6 7 8 9 10
	for (i = 1; i <= 10; i++)
		push(&stack, i);

	assert(!stackIsEmpty(stack));
	assert(peekStack(stack) == 10);	// översta elementet bör vara 10

	for (i = 0; i < 5; i++)
		pop(&stack);	// Ta bort de fem översta i stacken (10, 9, 8, 7 och 6)

	assert(!stackIsEmpty(stack));
	assert(peekStack(stack) == 5);	// 5 bör alltså vara överst på stacken nu

	push(&stack, 0); // Lägg 0 överst på stacken
	assert(peekStack(stack) == 0);	
	pop(&stack);
	assert(peekStack(stack) == 5); // 5 är näst överst

	// Ta bort de kvarvarande elementen
	for (i = 0; i < 5; i++)
		pop(&stack);

	// Återigen ska kön vara tom och inte full
	assert(stackIsEmpty(stack));
	assert(!stackIsFull(stack));
}

void testSet(void)
{
	Set set = initializeSet();
	int i;

	for (i = 1; i <= 10; i++)
		assert(!isInSet(set, i)); // Inget element får finnas i settet

	for (i = 1; i <= 10; i++)
		if (i % 2 == 0)
			addToSet(&set, i);	// Lägg till alla jämna tal mellan 1 och 10 (dvs 2,4,6,8,10)

	for (i = 1; i <= 10; i++)
		if (i % 3 == 0)
			removeFromSet(&set, i); // Ta bort alla tal som är delbara med 3 från set (dvs tar bort 6, kvar ska 2,4,8,10 vara)

	for (i = 1; i <= 10; i++)
		if (i % 2 == 0 && i % 3 != 0)
		{
			assert(isInSet(set, i)); // Talet ska finnas i set om det är jämnt men inte delbart med tre
		}
		else
		{
			assert(!isInSet(set, i)); // Annars ska det inte finnas
		}
}
