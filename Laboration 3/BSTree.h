#ifndef BSTREE_H
#define BSTREE_H

struct treeNode
{
	int data;
	struct treeNode* left;
	struct treeNode* right;
};

typedef struct treeNode* BSTree;

// Skapar ett tomt tr�d
BSTree emptyTree(void);

// Returnerar 1 ifall tr�det �r tomt, 0 annars
int isEmpty(const BSTree tree);

// S�tter in 'data' sorterat i *tree
void insertSorted(BSTree* tree, int data);

// Utskriftsfunktioner
void printPreorder(const BSTree tree);
void printInorder(const BSTree tree);
void printPostorder(const BSTree tree);

// Returnerar 1 om 'data' finns i tree, 0 annars
int find(const BSTree tree, int data);

// Tar bort 'data' fr�n tr�det om det finns
void removeElement(BSTree* tree, int data);

// Returnerar hur m�nga noder som totalt finns i tr�det
int numberOfNodes(const BSTree tree);

// Returnerar hur djupt tr�det �r
int depth(const BSTree tree);

// Returnerar minimidjupet f�r tr�det
int minDepth(const BSTree tree);

// Balansera tr�det s� att depth(tree) == minDepth(tree)
void balanceTree(BSTree* tree);

// Frig�r minne f�r tr�det samt g�r det tomt
void freeTree(BSTree* tree);

#endif
