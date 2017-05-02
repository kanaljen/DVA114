#include <assert.h>
#include <stdio.h>
#include "BSTree.h"

void testTree(void)
{
	BSTree tree = emptyTree();
	assert(isEmpty(tree));

	// S�tt in 7 element i tr�det
	int arr[7] = {5,10,1,3,7,18,20}, i;
	for (i = 0; i < 7; i++)
	{
		insertSorted(&tree, arr[i]);
	}

	for (i = 0; i < 7; i++)
	{
		// Verifiera att alla element finns i tr�det
		assert(find(tree, arr[i]));
	}

	assert(numberOfNodes(tree) == 7);
	assert(depth(tree) == 4); // Om vi s�tter in noderna i denna ordning blir djupet 4
	assert(minDepth(tree) == 3); // Med 7 noder �r minimidjupet 3

	removeElement(&tree, 18); // Tar bort ett element med ett barn
	removeElement(&tree, 5); // Tar bort ett element med tv� barn

	assert(numberOfNodes(tree) == 5); // Tv� noder har blivit borttagna
	
	// Verifiera att talen blivit borttagna
	assert(!find(tree, 18));
	assert(!find(tree, 5));

	// Addera 10 element s� att tr�det blir obalancerat
	for (i = 0; i < 10; i++)
		insertSorted(&tree, i+100);
	
	assert(numberOfNodes(tree) == 10 + 5);
	balanceTree(&tree);
	assert(numberOfNodes(tree) == 10 + 5); // Verifiera att antalet noder �r detsamma
	assert(depth(tree) == minDepth(tree)); // Verifiera att tr�det �r balancerat

	// T�m tr�det och kontrollera att det �r tomt
	freeTree(&tree);
	assert(isEmpty(tree));
	assert(numberOfNodes(tree) == 0);
	assert(depth(tree) == 0);
}


void menuTree(void)
{
    BSTree tree = NULL;
    int input = 1, element,i;
    for(i = 1;i<16;i++)insertSorted(&tree,i);
    
    while(input != 0){
        
        printf("MENU\n");
        printf("1. Add\n");
        printf("2. Remove\n\n");
        printf("3. Print - Preorder\n");
        printf("4. Print - InOrder\n");
        printf("5. Print - Postorder\n\n");
        printf("6. Find\n\n");
        printf("7. Depth - Minimum\n");
        printf("8. Depth\n");
        printf("9. Sort\n\n");
        printf("0. Exit\n");
        
        scanf(" %d",&input);
        
        switch (input) {
            case 1:{
                printf("Add element: ");
                scanf(" %d",&element);
                insertSorted(&tree,element);
                break;
            }
            case 2:{
                printf("Remove element: ");
                scanf(" %d",&element);
                removeElement(&tree,element);
                break;
            }
            case 3:{
                printf("\nPRINT PREORDER\n");
                printPreorder(tree);
                printf("\nEND\n");
                printf("Number of nodes: %d\n",numberOfNodes(tree));
                break;
            }
            case 4:{
                printf("\nPRINT INORDER\n");
                printInorder(tree);
                printf("\nEND\n");
                printf("Number of nodes: %d\n",numberOfNodes(tree));
                break;
            }
            case 5:{
                printf("\nPRINT POSTORDER\n");
                printPostorder(tree);
                printf("\nEND\n");
                printf("Number of nodes: %d\n",numberOfNodes(tree));
                break;
            }
            case 6:{
                printf("Find element: ");
                scanf(" %d",&element);
                element = find(tree,element);
                if(element == 1)printf("Element in tree!\n");
                else printf("Element not in tree!\n");
                break;
            }

            case 7:{
                printf("Min Depth: %d\n",minDepth(tree));
                break;
            }
            case 8:{
                printf("Depth: %d\n",depth(tree));
                if(depth(tree)>minDepth(tree)){
                    printf("Tree needs sorting!\n");
                }
                break;
            }
            case 9:{
                balanceTree(&tree);
                break;
            }
            case 666:{
                printf("Number of nodes: %d\n",numberOfNodes(tree));
                break;
            }
            case 0: break;
        }
        
    }
    
}

    
    int main(void)
{
	testTree();
	//menuTree();

}