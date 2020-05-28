#include "stdio.h"
#include "stdlib.h"
#include "BSTtree.h"

struct Page* createTAD() {
	struct Page* new = (struct Page*)malloc(sizeof(struct Page));
	new = NULL;
	return new;
}

struct Page* newElement(int value) {
	struct Page* newElement = (struct Page*)malloc(sizeof(struct Page));

	newElement->value = value;
	newElement->left = NULL;
	newElement->right = NULL;

	return newElement;
}

struct Page* insertBST(struct Page* tree, int value) {

	if (tree == NULL) {
		tree = newElement(value);
	} else if (value < tree->value) {
		tree->left = insertBST(tree->left, value);
	} else if (value > tree->value) {
		tree->right = insertBST(tree->right, value);
	} 

	return tree;
}

struct Page* searchBST(struct Page* tree, int value) {

	if (value == tree->value) {
		return tree;	
	} else if (value > tree->value) {
		tree->right = searchBST(tree->right, value);
	} else if (value < tree->value) {
		tree->left = searchBST(tree->left, value);
	}
}

struct Page* searchForSmallNumberAtRightTree(struct Page* subtree) {
	if (subtree != NULL)
		subtree->right = searchForSmallNumberAtRightTree(subtree->right);

	return subtree;
}

struct Page* deleteBST(struct Page* tree, int value) {

	if (value == tree->value) {
		if (tree->left == NULL || tree->right == NULL) {
			struct Page* aux = tree;
			if (tree->left != NULL)
				tree = tree->left;
			else
				tree = tree->right;

			free(aux);
		} else {
			struct Page* deleteNode2 = searchForSmallNumberAtRightTree(tree->right);
			tree->value = deleteNode2->value;
			tree->right = deleteBST(tree->right, deleteNode2->value);
		}
	} else if (value > tree->value) {
		tree->right = deleteBST(tree->right, value);
	} else if (value < tree->value) {
		tree->left = deleteBST(tree->left, value);
	}

	return tree;
}

void preOrder(struct Page* tree) {
	if (tree != NULL) {
			
		printf("%d ", tree->value);
		preOrder(tree->left);
		preOrder(tree->right);
	}
}