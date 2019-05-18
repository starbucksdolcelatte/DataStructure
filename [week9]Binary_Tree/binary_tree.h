#pragma once
#include <stdio.h> 
#define TRUE 1 
#define FALSE 0

typedef struct _BTreeNode{ 
	int data; 
	struct BTreeNode* left; 
	struct BTreeNode* right; 
}BTreeNode;

int GetData(BTreeNode* bt);
void SetData(BTreeNode* bt, int data);
BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);
void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);