#pragma once
#include "binary_tree.h"
#include "DataTraverse.h"
#include "stack_linkedlist.h"

BTreeNode* MakeExpTree(char exp[]);
int EvaluateExpTree(BTreeNode* bt);
void ShowNodeData(int data);
void ShowPrefixTypeExp(BTreeNode* bt);
void ShowInfixTypeExp(BTreeNode* bt);
void ShowPostfixTypeExp(BTreeNode* bt);