#ifndef _H_AVLtree
#endif
#define _H_AVLtree

struct Page {
	struct Page* left; // pointer to the left of the tree
	struct Page* right;  // same but to the right
	int Height; // height of each node
	int value;  // integer that the tree saves
};

struct Page* createTAD();
int Height(struct Page* AVL);
int maximo(int numberA, int numberB);
int BalanceFactor(struct Page* node);
struct Page* createPage(int value);
struct Page* rotateLL(struct Page* DesbalancedNode);
struct Page* rotateRR(struct Page* DesbalancedNode);
struct Page* rotateLR(struct Page* DesbalancedNode);
struct Page* rotateRL(struct Page* DesbalancedNode);
struct Page* verifityRotate(struct Page* SupposedDesbalancedNode);
void insertAVL(struct Page** AVL, int value);
void printAVL_preOrder(struct Page* AVL);
void printAVL_inOrder(struct Page* AVL);
void printAVL_postOrder(struct Page* AVL);
void printHeight(struct Page* AVL);
struct Page* search(struct Page* AVL, int value);
struct Page* searchForSmallNumberAtRightTree(struct Page* AVL);
void deleteElement(struct Page** AVL, int value);