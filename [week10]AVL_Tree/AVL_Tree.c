#include <stdio.h>
#include "AVL_Tree.h"

BTreeNode* RotateLL(BTreeNode* bst) {
	BTreeNode* pNode; 
	BTreeNode* cNode;
	pNode = bst;
	cNode = GetLeftSubTree(pNode);
	ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
	ChangeRightSubTree(cNode, pNode);
	return cNode;
} // end of RotateLL()

BTreeNode* RotateRR(BTreeNode* bst) {
	BTreeNode* pNode;
	BTreeNode* cNode;
	pNode = bst;
	cNode = GetRightSubTree(pNode);
	ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
	ChangeLeftSubTree(cNode, pNode);
	return cNode;
} // end of RotateRR()

BTreeNode* RotateLR(BTreeNode* bst) {
	BTreeNode* pNode; 
	BTreeNode* cNode;
	pNode = bst; 
	cNode = GetLeftSubTree(pNode);
	ChangeLeftSubTree(pNode, RotateRR(cNode)); 
	return RotateLL(pNode);
} // end of RotateLR()

BTreeNode* RotateRL(BTreeNode* bst) {
	BTreeNode* pNode; 
	BTreeNode* cNode;
	pNode = bst; 
	cNode = GetRightSubTree(pNode);
	ChangeRightSubTree(pNode, RotateLL(cNode)); 
	return RotateRR(pNode);
} // end of RotateRL()

int GetHeight(BTreeNode* bst) {
	int leftH;
	int rightH;
	if (bst == NULL)
	{
		return 0;
	}
	leftH = GetHeight(GetLeftSubTree(bst));
	rightH = GetHeight(GetRightSubTree(bst));
	if (leftH > rightH)
	{
		return leftH + 1;
	}
	else
	{
		return rightH + 1;
	}
} // end of GetHeight()

int GetHeightDiff(BTreeNode* bst) {
	int lsh;
	int rsh;
	if (bst == NULL)
	{
		return 0;
	}
	lsh = GetHeight(GetLeftSubTree(bst));
	rsh = GetHeight(GetRightSubTree(bst));
	return lsh - rsh;
} // end of GetHeightDiff()


BTreeNode* Rebalance(BTreeNode** pRoot) {
	int hDiff = GetHeightDiff(*pRoot);
	if (hDiff > 1) {
		if (GetHeightDiff(GetLeftSubTree(*pRoot)) > 0) {
			*pRoot = RotateLL(*pRoot);
		}
		else {
			*pRoot = RotateLR(*pRoot);
		}
	}
	if (hDiff < -1) {
		if (GetHeightDiff(GetRightSubTree(*pRoot)) < 0) {
			*pRoot = RotateRR(*pRoot);
		}
		else {
			*pRoot = RotateRL(*pRoot);
		}
	}
	return *pRoot;
} // end of Rebalance()


BTreeNode* AVLInsert(BTreeNode** pRoot, int data) {
	if (*pRoot == NULL) {
		*pRoot = MakeBTreeNode();
		SetData(*pRoot, data);
	}
	else if (data < GetData(*pRoot)) {
		BSTInsert(&((*pRoot)->left), data);
		*pRoot = Rebalance(pRoot);
	}
	else if (data > GetData(*pRoot)) {
		BSTInsert(&((*pRoot)->right), data);
		*pRoot = Rebalance(pRoot);
	}
	else {
		return NULL;
	}
	return *pRoot;
} // end of AVLInsert()