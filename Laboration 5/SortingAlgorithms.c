#define _CRT_SECURE_NO_WARNINGS
#include "SortingAlgorithms.h"
#include "Statistics.h"
#include "Array.h"
#include <assert.h>
#include <string.h>

int isImplemented(SortingAlgorithm algorithm)
{
	switch (algorithm)
	{
	case BUBBLE_SORT:
//	case INSERTION_SORT:
	case SELECTION_SORT:
//	case QUICK_SORT:
	case MERGE_SORT:
		return 1;
	default:
		return 0;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Era algoritmer h‰r:
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void bubbleSort(ElementType* arrayToSort, size_t size, Statistics* statistics)
{
    int i, j;

    for(j = size;greaterThan(j,0, statistics);j--){

        for (i = 0;lessThan(i,size-1,statistics);i++){

            if(greaterThan(arrayToSort[i],arrayToSort[i+1],statistics)){

                swapElements(&arrayToSort[i],&arrayToSort[i+1],statistics);

            }

        }

    }

}

static void insertionSort(ElementType* arrayToSort, size_t size, Statistics* statistics)
{
}

static void selectionSort(ElementType* arrayToSort, size_t size, Statistics* statistics)
{
    int i, j;

    for(i = 0 ;lessThan(i, size,statistics);i++){

        for (j = i+1;lessThan(j, size,statistics);j++) {

            if(greaterThan(arrayToSort[i],arrayToSort[j],statistics)){

                swapElements(&arrayToSort[i],&arrayToSort[j],statistics);

            }

        }
    }
}

static void mergeStatic(ElementType* inArr,int l, int r,Statistics* stats){


    if(greaterThan(r, 1, stats)){ //r > 1

        int i, j ,k, m, sizeL, sizeR;

        m = r/2; //Räkna fram mitten

        sizeL = m - l; //Storleken på vänstra arr, +1 för att det blir enklare med loopar

        sizeR = r - m; //Storleken på den högra arr

        ElementType *L, *R;

        L = malloc(sizeof(ElementType) * sizeL);
        R = malloc(sizeof(ElementType) * sizeR);

        for(i = 0; lessThan(i,sizeL,stats); i++) swapElements(&L[i],&inArr[i], stats); //Skriv till L, i < sizeL, L[i] = inArr[i]
        for(j = 0; lessThan(j,sizeR,stats); j++) swapElements(&R[j],&inArr[m+j], stats); //Skriv till R, j < sizeR, R[j] = inArr[m + j]

        mergeStatic( &(*L) , l, sizeL, stats); //Gör det igen med vänster
        mergeStatic( &(*R) , l, sizeR, stats); //Höger

        i = 0; //Left

        j = 0; //Right

        k = 0; //Merg arrayen


        while (lessThan(i,sizeL, stats) && lessThan(j,sizeR, stats)) //Sortera, i < sizeL && j < sizeR
        {
            if (lessThan(L[i],R[j],stats)) //L[i] < R[j]
            {
                swapElements(&inArr[k], &L[i],stats); //inArr[k] = L[i]
                i++;
            }
            else
            {
                swapElements(&inArr[k], &R[j],stats); //inArr[k] = R[j]
                j++;
            }
            
            k++;
        }

        if(lessThan(i,sizeL,stats)){ //Om det finns nåt kvar i L, i < sizeL

            while(lessThan(i,sizeL,stats)){
                swapElements(&inArr[k], &L[i],stats); //inArr[k] = L[i]
                i++;
                k++;
            }

        }

        if(lessThan(j,sizeR,stats)){ //Om det finns nåt kvar i R, j < sizeR

            while(lessThan(j,sizeR,stats)){ //j < sizeR
                swapElements(&inArr[k], &R[j],stats); //inArr[k] = R[j]
                j++;
                k++;
            }
            
        }


        free(L);
        free(R);


    }

};

static void mergeSort(ElementType* arrayToSort, size_t size, Statistics* statistics)
{

    mergeStatic(arrayToSort,0,(unsigned int)size,statistics);


}

static void quickSort(ElementType* arrayToSort, size_t size, Statistics* statistics)
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


char* getAlgorithmName(SortingAlgorithm algorithm)
{
	/* ƒr inte str‰ngen vi allokerar lokal fˆr funktionen? 
	   Nej, inte i detta fall. Str‰ngkonstanter ‰r ett speciallfall i C */
	switch (algorithm)
	{
	case BUBBLE_SORT:	 return "  Bubble sort "; 
	case SELECTION_SORT: return "Selection sort";
	case INSERTION_SORT: return "Insertion sort";
	case MERGE_SORT:	 return "  Merge sort  ";
	case QUICK_SORT:	 return "  Quick sort  "; 
	default:
		assert(0 && "Ogiltig algoritm!");
		return "";
	}
}

// Sorterar 'arrayToSort' med 'algorithmToUse'. Statistik fˆr antal byten och j‰mfˆrelser hamnar i *statistics
static void sortArray(ElementType* arrayToSort, size_t size, SortingAlgorithm algorithmToUse, Statistics* statistics)
{
	if(statistics != NULL)
		resetStatistics(statistics);

	switch (algorithmToUse)
	{
	case BUBBLE_SORT:	 bubbleSort(arrayToSort, size, statistics); break;
	case SELECTION_SORT: selectionSort(arrayToSort, size, statistics); break;
	case INSERTION_SORT: insertionSort(arrayToSort, size, statistics); break;
	case MERGE_SORT:	 mergeSort(arrayToSort, size, statistics); break;
	case QUICK_SORT:	 quickSort(arrayToSort, size, statistics); break;
	default:
		assert(0 && "Ogiltig algoritm!");
	}
}

// Fˆrbereder arrayer fˆr sortering genom att allokera minne fˆr dem, samt intialisera dem 
static void prepareArrays(SortingArray sortingArray[], SortingAlgorithm algorithm, const ElementType* arrays[], const unsigned int sizes[])
{
	assert(isImplemented(algorithm));

	int i;
	int totalArraySize;

	for (i = 0; i < NUMBER_OF_SIZES; i++)
	{
		totalArraySize = sizeof(ElementType)*sizes[i];
		sortingArray[i].arrayToSort = malloc(totalArraySize);
		memcpy(sortingArray[i].arrayToSort, arrays[i], totalArraySize);

		sortingArray[i].algorithm = algorithm;
		sortingArray[i].arraySize = sizes[i];
		resetStatistics(&sortingArray[i].statistics);
	}
}

// Sorterar arrayerna
static void sortArrays(SortingArray toBeSorted[])
{
	int i;
	for (i = 0; i < NUMBER_OF_SIZES; i++)
	{
		SortingArray* current = &toBeSorted[i];
		sortArray(current->arrayToSort, current->arraySize, current->algorithm, &current->statistics);
	
		if (!isSorted(current->arrayToSort, current->arraySize))
		{
			printf("Fel! Algoritmen %s har inte sorterat korrekt!\n", getAlgorithmName(current->algorithm));
			printf("Resultatet ‰r: \n");
			printArray(current->arrayToSort, current->arraySize, stdout);
			assert(0); // Aktiveras alltid
		}
	}
}

void printResult(SortingArray sortedArrays[], FILE* file)
{
	assert(file != NULL);

	int i;
	for (i = 0; i < NUMBER_OF_SIZES; i++)
	{
		fprintf(file, "%4d element: ", sortedArrays[i].arraySize);
		printStatistics(&sortedArrays[i].statistics, file);
		fprintf(file, "\n");
	}
	fprintf(file, "\n");
}

void sortAndPrint(SortingArray sortingArray[], SortingAlgorithm algorithm, const ElementType* arrays[], unsigned int sizes[], FILE* file)
{
	assert(file != NULL);

	prepareArrays(sortingArray, algorithm, arrays, sizes);
	sortArrays(sortingArray);
	printResult(sortingArray, file);
}

void freeArray(SortingArray sortingArray[])
{
	int i;
	for (i = 0; i < NUMBER_OF_SIZES; i++)
	{
		if (sortingArray[i].arrayToSort != NULL)
			free(sortingArray[i].arrayToSort);
		sortingArray[i].arrayToSort = NULL;
		sortingArray[i].arraySize = 0;
		resetStatistics(&sortingArray[i].statistics);
	}
}
