#include <stdio.h>
#include <stdlib.h>
#include "DataTraverse.h"

void InorderTraverse(BTreeNode* bt) {
	if (bt == NULL) { 
		return; 
	}
	InorderTraverse(bt->left); 
	printf("%d  ", bt->data); 
	InorderTraverse(bt->right);
}

void PreorderTraverse(BTreeNode* bt) {
	if (bt == NULL) { 
		return; 
	}
	printf("%d  ", bt->data); 
	PreorderTraverse(bt->left); 
	PreorderTraverse(bt->right);
}

void PostorderTraverse(BTreeNode* bt) {
	if (bt == NULL) { 
		return; 
	}
	PostorderTraverse(bt->left); 
	PostorderTraverse(bt->right); 
	printf("%d  ", bt->data);
}