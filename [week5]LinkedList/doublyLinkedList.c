#pragma once
/***Doubly linked list***/
#include <stdio.h>
#include "doublyLinkedList.h"

void ListInit(struct DB_LinkedList *plist) {
	plist->head = NULL;
	plist->cur = NULL;
	plist->numOfData = 0;
}

int ListItemCount(struct DB_LinkedList* plist) {
	return plist->numOfData;
}

int IsEmpty(struct DB_LinkedList* plist) {
	if (plist->head == NULL) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

void InsertItem(struct DB_LinkedList* plist, int data) {
	struct Node * newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;

	if (plist->head == NULL) {
		newNode->prev = NULL;
		plist->head = newNode;
		plist->cur = newNode;
	}
	else {
		plist->cur->next = newNode;
		newNode->prev = plist->cur;
		plist->cur = plist->cur->next;
	}
	(plist->numOfData)++;
} // end of InsertItem()

int Find(struct DB_LinkedList* plist, int pdata) {
	struct Node* temp;
	if (IsEmpty(plist)) {
		return FALSE;
	}
	temp = plist->head;
	while (temp->next != NULL) {
		if (temp->data == pdata) {
			return TRUE;
		}
		else {
			temp = temp->next;
		}
	}
	if (temp->data == pdata) {
		return TRUE;
	}
	return FALSE;
}

int RemoveItem(struct DB_LinkedList *plist, int pdata) {
	struct Node* delNode;
	struct Node* temp;

	if (IsEmpty(plist)) {
		return FALSE;
	}

	delNode = plist->head;  temp = plist->head;

	while (temp->next != NULL) {
		if (delNode->data == pdata) {
			temp->next = delNode->next;
			delNode->next->prev = temp;
			free(delNode);
			return TRUE;
		}
		else {
			temp = delNode;
			delNode = delNode->next;
		}
	}
	if (delNode->data == pdata) {
		delNode->prev = NULL;
		free(delNode);
		return TRUE;
	}
	return FALSE;
} // end of RemoveItem()

int getFirstItem(struct DB_LinkedList* plist, int* pdata) {
	if (plist->head == NULL) {
		return FALSE;
	}
	plist->last = plist->head;
	*pdata = plist->last->data;

	return TRUE;
}

int getNextItem(struct DB_LinkedList* plist, int* pdata) {
	if (plist->last->next == NULL) {
		return FALSE;
	}

	plist->last = plist->last->next;
	*pdata = plist->last->data;

	return TRUE;
}


int getPrevItem(struct DB_LinkedList * plist, int* pdata) {
	if (plist->last->prev == NULL) {
		return FALSE;
	}
	plist->last = plist->last->prev;
	*pdata = plist->last->data;
	return TRUE;
}
