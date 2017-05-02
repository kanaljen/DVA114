#ifndef DSTRING_H
#define DSTRING_H
#include <stdio.h>

typedef char* DString;

/* Returnerar en str‰ng som innehÂller samma text som textstr‰ngen 'str'. 
  Den returnerade str‰ngen ‰r dynamiskt allokerad (dvs, pÂ heapen) */
DString dstring_initialize(const char* str);

/* SlÂr ihop originalstr‰ngen med source */
int dstring_concatenate(DString* destination, DString source);

/* Fˆrkortar *destination sÂ att den innehÂller hˆgst truncatedLength tecken 
  Om 'truncatedLength' ‰r l‰ngre ‰n str‰ngens l‰ngd h‰nder inget */
void dstring_truncate(DString* destination, unsigned int truncatedLength);

/* Skriver str‰ngen till en textfil. 
   Textfilen fˆrv‰ntas redan vara ˆppnad och forts‰tter vara ˆppnad efter anropet */
void dstring_print(DString stringToPrint, FILE* textfile);

/* Frigˆr minnet fˆr en dynamisk str‰ng och s‰tter str‰ngen (*stringToDelete) till NULL */
void dstring_delete(DString* stringToDelete);

#endif
