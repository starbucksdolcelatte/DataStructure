#include <stdio.h>
#include "binarySearchTree.h"

void BSTMakeAndInit(BTreeNode** pRoot) { 
	*pRoot = NULL; 
}

int BSTGetNodeData(BTreeNode* bst) { 
	return GetData(bst); 
}

void BSTInsert(BTreeNode** pRoot, int data) {
	BTreeNode* pNode = NULL;    // parent node 
	BTreeNode* cNode= *pRoot;    // current node 
	BTreeNode* nNode= NULL;    // new node

	// find location for insert new Node 
	while(cNode!= NULL) { 
		if(data == GetData(cNode)) { 
			return;  // 중복을 허용하지 않는다.
		}
		pNode = cNode; 
		if (GetData(cNode) > data) { 
			cNode = GetLeftSubTree(cNode); 
		}
		else { 
			cNode = GetRightSubTree(cNode); 
		}
	} // end of while()
	// create new Node that attach to subNode of Node 
	nNode= MakeBTreeNode();    // create new Node 
	SetData(nNode, data);	// data store into new node
	// attach new node to subNode of Node    
	// if new Node is not Root node 
	if(pNode!= NULL) { 
		if(data < GetData(pNode)) { 
			MakeLeftSubTree(pNode, nNode); 
		} else { 
			MakeRightSubTree(pNode, nNode); 
		} 
	} else { // new node is root node 
		*pRoot= nNode; 
	} 
}// end of BSTInsert()

BTreeNode* BSTSearch(BTreeNode* bst, int target) {
	// current node 
	BTreeNode* cNode = bst;
	int cd;// current data
	while (cNode != NULL) {
		cd = GetData(cNode);
		if (target == cd) {
			return cNode;
		}
		else if (target < cd) {
			cNode = GetLeftSubTree(cNode);
		}
		else {
			cNode = GetRightSubTree(cNode);
		}
	} //end of while.
	return NULL;
}// end of BSTSearch()

BTreeNode* RemoveRightSubTree(BTreeNode* bt) {
	BTreeNode* delNode;
	if (bt != NULL) { 
		delNode = bt->right; 
		bt->right = NULL; 
	} 
	return delNode;
}

BTreeNode* RemoveLeftSubTree(BTreeNode* bt) {
	BTreeNode* delNode;
	if (bt != NULL) { 
		delNode = bt->left; 
		bt->left = NULL; 
	} 
	return delNode;
}

void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub) { 
	main->left = sub; 
}

void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub) { 
	main->right = sub; 
}

BTreeNode* BSTRemove(BTreeNode** pRoot, int target) {
	// if delete node is root node, how do we delete it ?! 
	BTreeNode* pVRoot= MakeBTreeNode(); // Virtual Root Node
	BTreeNode* pNode= pVRoot;    // parent node 
	BTreeNode* cNode= *pRoot;    // current node 
	BTreeNode* dNode;    // delete node
	// *pRoot(original root Node) is right sub node of the pVRoot 
	ChangeRightSubTree(pVRoot, *pRoot);
	// find the delete node 
	while(cNode!= NULL && GetData(cNode) != target) { 
		pNode= cNode;
		if (target < GetData(cNode)) { 
			cNode = GetLeftSubTree(cNode); 
		}
		else { 
			cNode = GetRightSubTree(cNode); 
		}
	} // end of while()
	// if not exist node for delete data 
	if(cNode== NULL) { 
		return NULL; 
	}
	// dNodepoint a target for delete node 
	dNode= cNode;
	// Case 1: Delete node is terminal node 
	if(GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL) { 
		if(GetLeftSubTree(pNode) == dNode) { 
			RemoveLeftSubTree(pNode); 
		} else { 
			RemoveRightSubTree(pNode); 
		} 
	} // end of Case 1.
	// Case 2: Delete node has one child node 
	else if(GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL) { 
		BTreeNode* dcNode;   // child node of the delete node
		if (GetLeftSubTree(dNode) != NULL) { 
			dcNode = GetLeftSubTree(dNode); 
		} else { 
			dcNode = GetRightSubTree(dNode); 
		}
		// 이어붙이기
		if (GetLeftSubTree(pNode) == dNode) { //left child will be deleted
			ChangeLeftSubTree(pNode, dcNode); 
		} else { //right child will be deleted
			ChangeRightSubTree(pNode, dcNode); 
		}
	}// end of Case 2.
	// Case 3. Delete node has two child nodes 
	else { 
		BTreeNode* mNode= GetRightSubTree(dNode); // mininum node 
		BTreeNode* mpNode= dNode;    // Parent node of mininum node 
		int delData;
		// find the delete node 
		while(GetLeftSubTree(mNode) != NULL) { 
			mpNode= mNode; 
			mNode= GetLeftSubTree(mNode); 
		} // end of while()
		delData = GetData(dNode);// data backupbefore store 
		SetData(dNode, GetData(mNode));
		// Connect node between substitute Parent and Child Node 
		if(GetLeftSubTree(mpNode) == mNode) { 
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode)); 
		} else { 
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode)); 
		}
		dNode = mNode; 
		SetData(dNode, delData);    // Restore backup data 
	} // end of Case 3.
	// if delete node is Root Node… 
	if(GetRightSubTree(pVRoot) != *pRoot) { 
		*pRoot= GetRightSubTree(pVRoot); 
	} 
	free(pVRoot); 
	return dNode; 
} // end of BSTRemove()

void BSTShowAll(BTreeNode* bst) {
	InorderTraverse(bst); //Ascending order
}

void InorderTraverse(BTreeNode* bt) {
	if (bt == NULL) {
		return;
	}
	InorderTraverse(bt->left);
	printf("%d  ", bt->data);
	InorderTraverse(bt->right);
}