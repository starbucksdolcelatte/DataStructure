#include <stdio.h> 

typedef struct _EmpInfo { 
	int empNum;     
	int age; 
}EmpInfo;

int main(void) {
	EmpInfo empInfoArr[1000];    
	EmpInfo ei;    
	int eNum;

	printf("Input(empNum, age) : ");    
	scanf("%d %d", &(ei.empNum), &(ei.age));
	empInfoArr[ei.empNum] = ei;

	printf("input(empNum for check) : ");    
	scanf("%d", &eNum);

	ei = empInfoArr[eNum];     
	printf("empNum: %d, Age : %d \n", ei.empNum, ei.age);        
	return 0; 
} 