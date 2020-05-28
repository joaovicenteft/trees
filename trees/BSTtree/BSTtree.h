#ifndef _H_BSTtree
#endif
#define _H_BSTtree

struct Page {
	struct Page* left;
	struct Page* right;
	int value;
};

struct Page* createTAD();
struct Page* newElement(int value);
struct Page* insertBST(struct Page* tree, int value);
struct Page* searchBST(struct Page* tree, int value);
struct Page* searchForSmallNumberAtRightTree(struct Page* subtree);
struct Page* deleteBST(struct Page* tree, int value);
void preOrder(struct Page* tree);