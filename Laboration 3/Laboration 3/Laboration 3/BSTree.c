#include <stdlib.h>
#include "BSTree.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>

// Statiska hj�lpfunktioner /////////////////////////////////////////////////////////////

// Skapar en tr�dnod med det givna datat samt allokerar minne f�r det
static struct treeNode* createNode(int data)
{
    BSTree newNode;
    
    newNode = malloc(sizeof(struct treeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode; // Ers�tt med r�tt returv�rde
}

// Returnerar en dynamiskt allokerad array som inneh�ller tr�dets data sorterat
static int* writeSortedToArray(const BSTree tree)
{

    if(tree->left != NULL)return writeSortedToArray(tree->left);

    int* data = malloc(sizeof(int));
    *data = tree->data;
    return data;


}

static void buildFromArray(BSTree* tree, const int arr[], int start, int end){

    int mid = (start + end) / 2;

    if (start <= end){

        *tree = createNode(arr[mid]);
        buildFromArray(&(*tree)->left, arr, start, mid - 1);
        buildFromArray(&(*tree)->right, arr, mid + 1, end);
    }



    
}
// Bygger upp ett sorterat balancerat tr�d fr�n en sorterad array
void buildTreeSortedFromArray(BSTree* tree, const int arr[], int size)
{

    buildFromArray(tree, arr, 0, size-1);

}

// Implementation av tr�det ////////////////////////////////////////////////////////

BSTree emptyTree(void)
{
	return NULL; // Denna funktion �r klar
}

int isEmpty(const BSTree tree)
{
    if(tree == NULL)return 1;
    else return 0;
    
}

void insertSorted(BSTree* tree, int data)
{
    if((*tree) == NULL)(*tree) = createNode(data);
    
    else{
        
        if(data > (*tree)->data)insertSorted(&(*tree)->right,data);
        if(data < (*tree)->data)insertSorted(&(*tree)->left,data);
    
    }
    // Post-condition: data finns i tr�det
    //assert(find(*tree,data));
}

void printPreorder(const BSTree tree)
{
    if(tree != NULL){
        
        printf("%d ",tree->data);
        if(tree->left != NULL)printInorder(tree->left);
        if(tree->right != NULL)printInorder(tree->right);
        
    }
}

void printInorder(const BSTree tree)
{
    
    if(tree != NULL){
        
        if(tree->left != NULL)printInorder(tree->left);
        printf("%d ",tree->data);
        if(tree->right != NULL)printInorder(tree->right);
        
    }
    
}

void printPostorder(const BSTree tree)
{
    if(tree != NULL){
        
        if(tree->left != NULL)printInorder(tree->left);
        if(tree->right != NULL)printInorder(tree->right);
        printf("%d ",tree->data);
        
    }

}

int find(const BSTree tree, int data)
{
    if(tree == NULL)return 0;
    if(tree->data == data)return 1;
    if(tree->data > data)return find(tree->left,data);
    if(tree->data < data)return find(tree->right,data);
    return 1;
}

void removeElement(BSTree* tree, int data)
{
    
    if((*tree) == NULL) *tree = NULL;
    else if(data > (*tree)->data)removeElement(&(*tree)->right,data);
    else if(data < (*tree)->data)removeElement(&(*tree)->left,data);
    
    else if(data == (*tree)->data){ //Om data hittas
        
        if((*tree)->left == NULL && (*tree)->right == NULL){//Noden har inga barn
            
            free(*tree);
            *tree = NULL;
            
        }
        
        else if((*tree)->left != NULL){
            
            (*tree)->data = (*tree)->left->data;
            removeElement(&(*tree)->left,(*tree)->data);
            
        }
        
        else{
            
            (*tree)->data = (*tree)->right->data;
            removeElement(&(*tree)->right,(*tree)->data);
        }
    
    }
}

int numberOfNodes(const BSTree tree)
{
    if(tree == NULL)return 0;
    return numberOfNodes(tree->left) + numberOfNodes(tree->right) + 1;
}

int depth(const BSTree tree)
{
    int r = 0,l = 0;
    if(tree == NULL)return 0;
    r = depth(tree->right);
    l = depth(tree->left);
    if(r>=l)return r + 1;
    return l + 1;
}

int minDepth(const BSTree tree)
{
    int math,num;
    if(tree == NULL)return 0;
    num = numberOfNodes(tree);
    math = log(num + 1)/log(2);
    return math;
}

void balanceTree(BSTree* tree)
{
	// F�rslag p� algoritm:
	// - �verf�r tr�det till en dynamiskt allokerad array med writeSortedToArray()
	// - t�m tr�det med freeTree()
	// - bygg upp tr�det rekursivt fr�n arrayen med buildTreeSortedFromArray()
	// - frig�r minne f�r den dynamiskt allokerade arrayen
    
    int size = numberOfNodes(*tree),arr[size],*ret = NULL;
    for(int i = 0;i<size;i++){
        ret = writeSortedToArray(*tree);
        arr[i] = *ret;
        removeElement(tree,*ret);
        free(ret);
    };
    //for(int i = 0;i<size;i++)insertSorted(&(*tree),arr[i]);

    buildTreeSortedFromArray(&(*tree),arr,size);

	// Post-conditions:
	// - tree har lika m�nga noder som tidigare
	// - djupet f�r tr�det �r samma som minimumdjupet f�r tr�det
}

void freeTree(BSTree* tree)
{
    if((*tree)->left != NULL)freeTree(&(*tree)->left);
    if((*tree)->right != NULL)freeTree(&(*tree)->right);
    free(*tree);
    *tree = NULL;
    // Post-condition: tr�det �r tomt
    assert(*tree == NULL);
}

