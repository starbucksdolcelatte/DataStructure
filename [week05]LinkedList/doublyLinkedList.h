#pragma once

#define TRUE	1
#define FALSE	0

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

struct DB_LinkedList {
	struct Node* head;
	struct Node* tail;
	struct Node* cur;
	int numOfData;
};

void ListInit(struct DB_LinkedList *plist);
int ListItemCount(struct DB_LinkedList* plist);
int IsEmpty(struct DB_LinkedList* plist);
void InsertItem(struct DB_LinkedList* plist, int data);
int Find(struct DB_LinkedList* plist, int pdata);
int RemoveItem(struct DB_LinkedList *plist, int pdata);
int getFirstItem(struct DB_LinkedList* plist, int* pdata);
int getNextItem(struct DB_LinkedList* plist, int* pdata);
int getPrevItem(struct DB_LinkedList * plist, int* pdata);
