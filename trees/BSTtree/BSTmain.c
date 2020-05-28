#include "stdio.h"
#include "stdlib.h"
#include "BSTtree.h"

int main(int argc, char* argv[]) {
	
	struct Page* newTree = createTAD();

	newTree = insertBST(newTree, 10);
	newTree = insertBST(newTree, 11);
	newTree = insertBST(newTree, 7);
	newTree = insertBST(newTree, 9);
	newTree = insertBST(newTree, 15);
	newTree = insertBST(newTree, 8);

	newTree = deleteBST(newTree, 7);
	preOrder(newTree);
	printf("\n");
}