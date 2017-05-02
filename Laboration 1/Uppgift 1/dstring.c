#include "dstring.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>


DString dstring_initialize(const char* str)
{
	// Precondition: str är ej NULL
    assert(str != NULL);
	/* Tips:
	   - Allokera tillräckligt med minne för att få plats med str
	   - Det är tillåtet att använda inbyggda strängfunktioner (som t.ex strcpy())
	   - Kom ihåg att använda assert() */
    DString temp = malloc(sizeof(char)*strlen(str)+1);
    strcpy(temp, str);
	// Postcondition: returvärdet innehåller samma sträng som 'str'
    assert(temp != NULL);
	return temp; // Ersätt denna rad. Den är just nu med för att programmet ska kompilera
}

int dstring_concatenate(DString* destination, DString source)
{
	// Precondition: destination är ej NULL
    assert(destination != NULL);
	// Precondition: *destination är ej NULL
    assert(*destination != NULL);
	// Precondition: source är ej NULL
    assert(source != NULL);
    
	/* Tips: 
	   - Tänk på att *destination redan är en dynamiskt allokerad sträng
	   - Tänk på att vi kommer att behöva allokera mer minne för att få plats med den här längre strängen. 
	   */
    *destination = realloc(*destination,sizeof(char)*(strlen(source)+strlen(*destination))+1);
	// Post condition: *destination innehåller den gamla strängen ihopslagen med source
    strcat(*destination,source);
    
	return -1; // Ersätt denna rad. Den är just nu med för att programmet ska kompilera.
}

void dstring_truncate(DString* destination, unsigned int truncatedLength)
{
	// Precondition: destination är ej NULL, *destination är ej NULL
    assert(destination != NULL);
    
	/* Tips:
	   - Använd realloc för att frigöra det överflödiga minnet
	   - glöm inte nolltermineringen */
    
    *destination = realloc(*destination, (sizeof(char)*truncatedLength)+1);
    (*destination)[truncatedLength] = '\0';

    
	// Postcondition: *destination är inte längre än 'truncatedLength' tecken
}

void dstring_print(DString str, FILE* textfile)
{
	// Precondition: textfile är inte NULL
    assert(textfile != NULL);

	/* filpekaren får inte stängas, filen ska fungera som vanligt efter anropet */
    fwrite(str,sizeof(char),strlen(str),textfile);
}

void dstring_delete(DString* stringToDelete)
{
	// Precondition: stringToDelete är inte NULL
    assert(stringToDelete != NULL);
	// Postcondition: *stringToDelete -ÄR- NULL
    assert(*stringToDelete != NULL);
    
    free(*stringToDelete);
    
    *stringToDelete = NULL;
}
