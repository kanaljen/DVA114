#include "Set.h"
#include <assert.h>


Set initializeSet(void)
{
	return createList(); // Ers�tt med r�tt returv�rde
}

void addToSet(Set* set, const Data element)
{
	// Precondition: set �r inte full
    assert(!isSetFull(*set));
    

	// Tips: t�nk p� att inte l�gga till elementet om det redan finns i *set
    if(isInSet(*set,element) != 1)*set = addFirstElement(*set,element);
    

	// Postcondition: 'element' finns i set (tips: anv�nd isInSet() f�r att verifiera)
    assert(isInSet(*set,element));
}

void removeFromSet(Set* set, const Data element)
{
    removeElement(set,element);
	// Postcondition: 'element' finns INTE i set (tips: anv�nd isInSet() f�r att verifiera)
    assert(!isInSet(*set,element));
}

int isSetFull(const Set set)
{
    int size = 0;
    
    
    if(listIsEmpty(set) == 1)return 0; //Setet �r tomt
    
    Set nextNode = set->next;
    
    while(nextNode != NULL){ // Stegar i setet
        nextNode = nextNode->next;
        size++;
    }
    
    if(nextNode == NULL)size++; //The botten is n�dd
    
    if(size>25)return 1; //25 godtycklig storlek p� setet
    
    return 0;
}

int isInSet(const Set set, const Data element)
{

    return searchElement(set,element);
    
//    if(listIsEmpty(set) == 1)return 0; //Setet �r tomt
//    
//    if(set->data == element)return 1;
//    
//    if(set->next != NULL)return isInSet(set->next,element);
//    
//    return 0;
}


