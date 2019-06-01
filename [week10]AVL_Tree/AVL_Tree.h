#pragma once
#include "binary_tree.h"
#include "binarySearchTree.h"

BTreeNode* RotateLL(BTreeNode* bst);
BTreeNode* RotateRR(BTreeNode* bst);
BTreeNode* RotateLR(BTreeNode* bst);
BTreeNode* RotateRL(BTreeNode* bst);
int GetHeight(BTreeNode* bst);
int GetHeightDiff(BTreeNode* bst);
BTreeNode* Rebalance(BTreeNode** pRoot);
BTreeNode* AVLInsert(BTreeNode** pRoot, int data);