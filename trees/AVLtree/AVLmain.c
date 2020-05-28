#include "stdio.h"
#include "stdlib.h"
#include "AVLtree.h"

int main(int argc, char* argv[]) {
    	struct Page* Node = createTAD();

	insertAVL(&Node, 9);
	insertAVL(&Node, 5);
	insertAVL(&Node, 10);
	insertAVL(&Node, 0);
	insertAVL(&Node, 6);
	insertAVL(&Node, 11);
	insertAVL(&Node, -1);
	insertAVL(&Node, 1);
	insertAVL(&Node, 2);

	deleteElement(&Node, 10);

	printAVL_inOrder(Node); // in order print
	printf("\n");
	printAVL_postOrder(Node); // post order print
	printf("\n");
	printAVL_preOrder(Node); // pre order print
	printf("\n");
	printHeight(Node); // height of each node, follow in order print
	printf("\n");
}   