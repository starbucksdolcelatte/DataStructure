#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

void ListInit(struct LinkedList* plist) {
	plist->numOfItems = 0;
	plist->head = NULL; //리스트의 머리를 가리키는 포인터 변수
	plist->tail = NULL; //리스트의 꼬리를 가리키는 포인터 변수
	plist->cur = NULL; //저장된 데이터의 조회에 사용되는 포인터 변수
}

int IsEmpty(struct LinkedList* plist) {
	if (plist->numOfItems == 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

int ListItemsCount(struct LinkedList* plist) {
	return plist->numOfItems;
}

void UnsortedInsert(struct LinkedList* plist, int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;

	if (IsEmpty(plist)) { //첫번째 노드라면!
		plist->head = newNode;
		plist->tail = newNode;
	}
	else { //두번째 이후 노드라면!
		plist->tail->next = newNode;
		plist->tail = newNode;
	}
	(plist->numOfItems)++;
}

int Find(struct LinkedList* plist, int pdata) {
	struct Node* temp;

	if (IsEmpty(plist)) {
		return FALSE;
	}
	else {
		temp = plist->head;
	}

	while (1) {
		if (temp->next != NULL) {
			if (temp->data == pdata) {
				return TRUE;
			}
			else {
				temp = temp->next;
			}
		}
		else { // temp가 마지막 노드
			if (temp->data == pdata) {
				return TRUE;
			}
			else {
				return FALSE;
			}
		}
	}
	return FALSE;
}

int RemoveItem(struct LinkedList* plist, int pdata) {
	struct Node* delNode;
	struct Node* prev;
	if (IsEmpty(plist))
		return FALSE;
	else {
		delNode = plist->head;
		prev = plist->head;
	}
	//첫번째 노드가 삭제할 노드인 경우
	if (delNode->data == pdata) { 
		plist->head = plist->head->next;
		free(delNode);
		(plist->numOfItems)--;
		return TRUE;
	}

	//두번째 이후 노드가 삭제할 노드인 경우
	else {
		delNode = delNode->next;
	}
	while (1) {
		if (delNode->next != NULL) {
			if (delNode->data == pdata) {
				prev->next = delNode->next;
				free(delNode);
				(plist->numOfItems)--;
				return TRUE;
			}
			else {
				prev = delNode;
				delNode = delNode->next;
			}
		}
		//맨 마지막 노드
		else {
			if (delNode->data == pdata) {
				prev->next = NULL;
				plist->tail = prev;
				free(delNode);
				(plist->numOfItems)--;
				return TRUE;
			}
		}
	}
	return FALSE;
}

int getFirstItem(struct LinkedList* plist, int* pdata) {
	if (IsEmpty(plist)) {
		*pdata = -1;
		return FALSE;
	}
	*pdata = plist->head->data;
	plist->cur = plist->head;
	return TRUE;
}

int getNextItem(struct LinkedList* plist, int* pdata) {
	if (plist->cur->next == NULL) {
		*pdata = -1;
		return FALSE;
	}
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}

