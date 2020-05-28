#include "stdio.h"
#include "stdlib.h"
#include "AVLtree.h"

struct Page* createTAD() {
	struct Page* tree = (struct Page*)malloc(sizeof(struct Page));

	tree = NULL;

	return tree;
}

int Height(struct Page* AVL) {
	if (AVL == NULL) {
		return -1;
	} else {
		return AVL->Height;
	}
}

int maximo(int numberA, int numberB) {
	if (numberA > numberB)
		return numberA;
	else
		return numberB;
}

int BalanceFactor(struct Page* node) {
	if (node == NULL)
		return 0;
	else
		return ((Height(node->left) - Height(node->right)));
}

struct Page* createPage(int value) {
	struct Page* tree = (struct Page*)malloc(sizeof(struct Page));

	tree->left = NULL;
	tree->right = NULL;
	tree->value = value;
	tree->Height = 0;

	return tree;
}

struct Page* rotateLL(struct Page* DesbalancedNode) { // right-right rotations, case left-left
	struct Page* aux;

	aux = DesbalancedNode->left;
	DesbalancedNode->left = aux->right;
	aux->right = DesbalancedNode;

	DesbalancedNode->Height = maximo(Height(DesbalancedNode->left), Height(DesbalancedNode->right)) + 1;
	aux->Height = maximo(Height(aux->left), DesbalancedNode->Height) + 1;

	DesbalancedNode = aux;

	return DesbalancedNode; // now Balanced
}

struct Page* rotateRR(struct Page* DesbalancedNode) { // left-left rotations , case right-right
	struct Page* aux;

	aux = DesbalancedNode->right;
	DesbalancedNode->right = aux->left;
	aux->left = DesbalancedNode;

	DesbalancedNode->Height = maximo(Height(DesbalancedNode->left), Height(DesbalancedNode->right)) + 1;
	aux->Height = maximo(Height(aux->right), DesbalancedNode->Height) + 1;

	DesbalancedNode = aux;

	return DesbalancedNode; // now balanced
}

struct Page* rotateLR(struct Page* DesbalancedNode) { // right-left rotations, case left-right
	DesbalancedNode->left = rotateRR(DesbalancedNode->left);
	DesbalancedNode = rotateLL(DesbalancedNode);
	return DesbalancedNode;
}

struct Page* rotateRL(struct Page* DesbalancedNode) { // left-right rotations, case right-left
	DesbalancedNode->right = rotateLL(DesbalancedNode->right);
	DesbalancedNode = rotateRR(DesbalancedNode);
	return DesbalancedNode;
}


struct Page* verifityRotate(struct Page* SupposedDesbalancedNode) { // given a node, verifity if he is unbalanced

	if (SupposedDesbalancedNode != NULL) {

		if (BalanceFactor(SupposedDesbalancedNode) >= 2) {
			if (BalanceFactor(SupposedDesbalancedNode->left) <= -1) {
				SupposedDesbalancedNode = rotateLR(SupposedDesbalancedNode);
			} else if (BalanceFactor(SupposedDesbalancedNode->left) >= 0){
				SupposedDesbalancedNode = rotateLL(SupposedDesbalancedNode);
			}
		} else if (BalanceFactor(SupposedDesbalancedNode) <= -2) {
			if (BalanceFactor(SupposedDesbalancedNode->right) >= 1) {
				SupposedDesbalancedNode = rotateRL(SupposedDesbalancedNode);
			} else if (BalanceFactor(SupposedDesbalancedNode->right) <= 0) {
				SupposedDesbalancedNode = rotateRR(SupposedDesbalancedNode);
			}
		}
	}
	return SupposedDesbalancedNode;	
} 

void insertAVL(struct Page** AVL, int value) { // search, insert and recursively update the heights

	if ((*AVL) == NULL) {
		(*AVL) = createPage(value);
	} else {
		if (value < (*AVL)->value) {
			insertAVL(&((*AVL)->left), value);
		} else if (value > (*AVL)->value) {
			insertAVL(&((*AVL)->right), value);
		
		}
	}

	(*AVL)->Height = maximo(Height((*AVL)->left), Height((*AVL)->right)) + 1;
	(*AVL) = verifityRotate(*AVL);	
}

void printAVL_preOrder(struct Page* AVL) {
	if (AVL != NULL) {
		printf("%d ", AVL->value);
		printAVL_preOrder(AVL->left);
		printAVL_preOrder(AVL->right);
	}
}

void printAVL_inOrder(struct Page* AVL) {
	if (AVL != NULL) {
		printAVL_inOrder(AVL->left);
		printf("%d ", AVL->value);
		printAVL_inOrder(AVL->right);
	}
}

void printAVL_postOrder(struct Page* AVL) {
	if (AVL != NULL) {
		printAVL_postOrder(AVL->left);
		printAVL_postOrder(AVL->right);
		printf("%d ", AVL->value);
	}
}

void printHeight(struct Page* AVL) {
	if (AVL != NULL) {
		printf("%d ", AVL->Height);
		printHeight(AVL->left);
		printHeight(AVL->right);
	}
}

struct Page* search(struct Page* AVL, int value) { // return the pointer to the search node
	
	if (value < AVL->value) {
		AVL = search(AVL->left, value);
	} else if (value > AVL->value) {
		AVL = search(AVL->right, value);
	} else if (value == AVL->value) {
		return AVL;
	}
}

struct Page* searchForSmallNumberAtRightTree(struct Page* AVL) {
	if (AVL != NULL) {
		AVL->left = searchForSmallNumberAtRightTree(AVL->left);
	}
	return AVL;
}

void deleteElement(struct Page** AVL, int value) {

	if (value == (*AVL)->value) {
		if (((*AVL)->left == NULL) || ((*AVL)->right == NULL)) {
			struct Page* deleteNode1 = (*AVL);
			if ((*AVL)->left != NULL)
				(*AVL) = (*AVL)->left; // one child
			else
				(*AVL) = (*AVL)->right; // NULL or one child

			free(deleteNode1);
		} else { // two childs case
			struct Page* deleteNode2 = searchForSmallNumberAtRightTree((*AVL)->right);
			(*AVL)->value = deleteNode2->value;
			deleteElement(&((*AVL)->right), deleteNode2->value);
		}
	} else if (value < (*AVL)->value) {
		deleteElement(&((*AVL)->left), value);
	} else if (value > (*AVL)->value) {
		deleteElement(&((*AVL)->right), value);
	}

	if ((*AVL) != NULL) { // add one more level before climb the recursion stack
		(*AVL)->Height = maximo(Height((*AVL)->left), Height((*AVL)->right)) + 1;
		(*AVL) = verifityRotate(*AVL);
	}
}



