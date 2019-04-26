#pragma once

#define TRUE	1
#define FALSE	0

struct Node {
	int data;
	struct Node* next;
};

struct LinkedList {
	int numOfItems;  
	struct Node* head;  
	struct Node* last;  
	struct Node* cur;
};

void ListInit(struct LinkedList* plist);
int IsEmpty(struct LinkedList* plist);
int ListItemsCount(struct LinkedList* plist);
void UnsortedInsert(struct LinkedList* plist, int data);
int Find(struct LinkedList* plist, int pdata);
int RemoveItem(struct LinkedList* plist, int pdata);
int getFirstItem(struct LinkedList* plist, int* pdata);
int getNextItem(struct LinkedList* plist, int* pdata);
