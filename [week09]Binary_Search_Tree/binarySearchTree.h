#pragma once
#include "binaryTree.h"

void BSTMakeAndInit(BTreeNode** pRoot);
int BSTGetNodeData(BTreeNode* bst);
void BSTInsert(BTreeNode** pRoot, int data);
BTreeNode* BSTSearch(BTreeNode* bst, int target);
BTreeNode* RemoveLeftSubTree(BTreeNode* bt);
BTreeNode* RemoveRightSubTree(BTreeNode* bt);
void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub);
BTreeNode* BSTRemove(BTreeNode** pRoot, int target);
void BSTShowAll(BTreeNode* bst);
void InorderTraverse(BTreeNode* bt);