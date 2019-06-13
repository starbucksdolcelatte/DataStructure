#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

void ListInit(struct LinkedList* plist) {
	plist->numOfItems = 0;
	plist->head = NULL; //����Ʈ�� �Ӹ��� ����Ű�� ������ ����
	plist->tail = NULL; //����Ʈ�� ������ ����Ű�� ������ ����
	plist->cur = NULL; //����� �������� ��ȸ�� ���Ǵ� ������ ����
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

	if (IsEmpty(plist)) { //ù��° �����!
		plist->head = newNode;
		plist->tail = newNode;
	}
	else { //�ι�° ���� �����!
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
		else { // temp�� ������ ���
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
	//ù��° ��尡 ������ ����� ���
	if (delNode->data == pdata) { 
		plist->head = plist->head->next;
		free(delNode);
		(plist->numOfItems)--;
		return TRUE;
	}

	//�ι�° ���� ��尡 ������ ����� ���
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
		//�� ������ ���
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

