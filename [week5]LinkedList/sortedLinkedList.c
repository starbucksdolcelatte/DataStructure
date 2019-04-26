#pragma once
#include <stdio.h>
#include "sortedLinkedList.h"

/*
#include linkedList.h 에 노드 구조체, 링크드리스트 구조체,
각종 함수들이 선언 및 정의되어 있기 때문에 이를 include 하여 사용
따라서 sortedLinkedList_main.c를 실행시키기 위해서는
sortedLinkedList.c, sortedLinkedList.h 뿐만 아니라
LinkedList.c, LinkedList.h도 필요하다.
*/

/***Sorted***/
void SortedInsert(struct LinkedList* plist, int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	struct Node* cur, *prev;
	newNode->data = data;
	newNode->next = NULL;

	if (IsEmpty(plist)) {
		plist->head = newNode;
		plist->cur = newNode;
	}
	else {
		cur = plist->head;  prev = cur;

		if (cur->data >= data) {
			plist->head = newNode;
			newNode->next = cur;
		}
		else {
			while (cur->next != NULL) {
				cur = cur->next;

				if (cur->data <= data) {
					prev = cur;
				}
				else {
					break;
				}
			} // end of while()

			if (prev == cur) {
				prev->next = newNode;
				newNode->next = NULL;
			}
			else {
				prev->next = newNode;
				newNode->next = cur;
			}
		}
	}
	(plist->numOfItems)++;
} // end of SortedInsertItem()
