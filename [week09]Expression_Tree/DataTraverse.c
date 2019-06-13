#include <stdio.h>
#include <stdlib.h>
#include "DataTraverse.h"

void InorderTraverse(BTreeNode* bt) {
	if (bt == NULL) { 
		return; 
	}
	InorderTraverse(bt->left); 
	if (bt->data < 10) {
		printf("%d  ", bt->data); //���� �״�� ���
	}
	else {
		printf("%c  ", bt->data); //ASCII �ڵ� �� ���� ���
	}
	 
	InorderTraverse(bt->right);
}

void PreorderTraverse(BTreeNode* bt) {
	if (bt == NULL) { 
		return; 
	}
	if (bt->data < 10) {
		printf("%d  ", bt->data);
	}
	else {
		printf("%c  ", bt->data);
	}
	PreorderTraverse(bt->left); 
	PreorderTraverse(bt->right);
}

void PostorderTraverse(BTreeNode* bt) {
	if (bt == NULL) { 
		return; 
	}
	PostorderTraverse(bt->left); 
	PostorderTraverse(bt->right); 
	if (bt->data < 10) {
		printf("%d  ", bt->data);
	}
	else {
		printf("%c  ", bt->data);
	}
}