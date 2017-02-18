#include "Set.h"
#include <assert.h>


Set initializeSet(void)
{
	return createList(); // Ersätt med rätt returvärde
}

void addToSet(Set* set, const Data element)
{
	// Precondition: set är inte full
    assert(!isSetFull(*set));
    

	// Tips: tänk på att inte lägga till elementet om det redan finns i *set
    if(isInSet(*set,element) != 1)*set = addFirstElement(*set,element);
    

	// Postcondition: 'element' finns i set (tips: använd isInSet() för att verifiera)
    assert(isInSet(*set,element));
}

void removeFromSet(Set* set, const Data element)
{
    removeElement(set,element);
	// Postcondition: 'element' finns INTE i set (tips: använd isInSet() för att verifiera)
    assert(!isInSet(*set,element));
}

int isSetFull(const Set set)
{
    int size = 0;
    
    
    if(listIsEmpty(set) == 1)return 0; //Setet Šr tomt
    
    Set nextNode = set->next;
    
    while(nextNode != NULL){ // Stegar i setet
        nextNode = nextNode->next;
        size++;
    }
    
    if(nextNode == NULL)size++; //The botten is nŒdd
    
    if(size>25)return 1; //25 godtycklig storlek pŒ setet
    
    return 0;
}

int isInSet(const Set set, const Data element)
{

    return searchElement(set,element);
    
//    if(listIsEmpty(set) == 1)return 0; //Setet Šr tomt
//    
//    if(set->data == element)return 1;
//    
//    if(set->next != NULL)return isInSet(set->next,element);
//    
//    return 0;
}


