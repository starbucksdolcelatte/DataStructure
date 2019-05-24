#include <stdio.h>
#include "expressionTree.h"

BTreeNode* MakeExpTree(char exp[]) {
	ListStack stack; 
	BTreeNode* pnode; 
	int i; 
	int expLen = strlen(exp);
	StackInit(&stack);
	for (i = 0; i < expLen; i++) {
		pnode = MakeBTreeNode();
		// if exp[i] is operand 
		if(isdigit(exp[i])) { 
			SetData(pnode, exp[i]-'0'); 
		}
		// else if operator 
		else {
			MakeRightSubTree(pnode, SPop(&stack)); 
			MakeLeftSubTree(pnode, SPop(&stack)); 
			SetData(pnode, exp[i]); 
		} 
		SPush(&stack, pnode); 
	} // end of for() 
	return SPop(&stack); 
} // end of MakeExpTree()


int EvaluateExpTree(BTreeNode* bt) {
	int op1, op2;
	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL) { 
		return GetData(bt); 
	}
	op1 = EvaluateExpTree(GetLeftSubTree(bt)); 
	op2 = EvaluateExpTree(GetRightSubTree(bt));
	switch (GetData(bt)) { 
		case '+': return op1 + op2; 
		case '-': return op1 - op2; 
		case '*': return op1 * op2; 
		case '/': return op1 / op2; 
	} 
	return 0;
}// end of EvaluateExpTree()

void ShowNodeData(int data) { 
	if (0 <= data && data <= 9) { 
		printf("%d ", data); 
	} else { 
		printf("%c ", data); 
	} 
}

void ShowPrefixTypeExp(BTreeNode* bt) { 
	PreorderTraverse(bt); 
}

void ShowInfixTypeExp(BTreeNode* bt) { 
	InorderTraverse(bt); 
}

void ShowPostfixTypeExp(BTreeNode* bt) { 
	PostorderTraverse(bt); 
}

