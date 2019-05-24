#include <stdio.h>
#include "expressionTree.h"

int main(void) {
	char exp[] = "742*+1-";
	BTreeNode* eTree = MakeExpTree(exp);
	printf("Pre - Fix Expression : ");
	ShowPrefixTypeExp(eTree);
	printf("\n");
	printf("In - Fix Expression : ");
	ShowInfixTypeExp(eTree);
	printf("\n");
	printf("Post - Fix Expression : ");
	ShowPostfixTypeExp(eTree);
	printf("\n");
	printf("Calculate Result : %d \n", EvaluateExpTree(eTree));
	return 0;
}// end of main()