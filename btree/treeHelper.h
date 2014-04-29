/*
				21
			      /   \
			     2	   23
			    / \	    \
			   1   6     43
			      / \    /\
			     4   11 29 68
                            / \  /\    /\
		            3  5 9 15 64 99

*/

#include <stdio.h>
#include <malloc.h>

struct binNode {
	int data;
	struct binNode* left;
	struct binNode* right;
};

void inOrder(struct binNode* binNode) {
	if (binNode == NULL) return;

	inOrder(binNode->left);
	printf("%d ", binNode->data);
	inOrder(binNode->right);
} 

void preOrder(struct binNode* binNode) {
	if (binNode == NULL) return;

	printf("%d ", binNode->data);
	preOrder(binNode->left);
	preOrder(binNode->right);
} 

void postOrder(struct binNode* binNode) {
	if (binNode == NULL) return;

	postOrder(binNode->left);
	postOrder(binNode->right);
	printf("%d ", binNode->data);
} 

/* allocate a new binNode */
struct binNode* NewNode(int data) {
	struct binNode* new = (struct binNode*)malloc(sizeof(struct binNode));
	new->data = data;
	new->left = NULL;
	new->right = NULL;

	return(new);
} 

struct binNode* insert(struct binNode* binNode, int data) {
	if (binNode == NULL) {
		return(NewNode(data));
  	}
	else {
		if (data <= binNode->data) 
			binNode->left = insert(binNode->left, data);
		else 
			binNode->right = insert(binNode->right, data);

		return(binNode);
  	}
} 

struct binNode* buildtree() {
	struct binNode* root = NULL;
	root = insert(root, 21);
	root = insert(root, 2);
	root = insert(root, 1);
	root = insert(root, 6);
	root = insert(root, 4);
	root = insert(root, 5);
	root = insert(root, 23);
	root = insert(root, 43);
	root = insert(root, 3);
	root = insert(root, 11);
	root = insert(root, 68);
	root = insert(root, 64);
	root = insert(root, 99);
	root = insert(root, 15);
	root = insert(root, 9);
	root = insert(root, 29);
	return(root);
} 

struct binNode* buildsubtree() {
        struct binNode* root = NULL;
        root = insert(root, 6);
        root = insert(root, 4);
        root = insert(root, 5);
        root = insert(root, 23);
        return(root);
}

void inOrderChar(struct binNode* binNode) {
	if (binNode == NULL) return;

	inOrderChar(binNode->left);
	printf("%c ", binNode->data);
	inOrderChar(binNode->right);
} 

void preOrderChar(struct binNode* binNode) {
	if (binNode == NULL) return;

	printf("%c ", binNode->data);
	preOrderChar(binNode->left);
	preOrderChar(binNode->right);
} 

void postOrderChar(struct binNode* binNode) {
	if (binNode == NULL) return;

	postOrderChar(binNode->left);
	postOrderChar(binNode->right);
	printf("%c ", binNode->data);
}
