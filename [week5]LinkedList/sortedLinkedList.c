#pragma once
#include <stdio.h>
#include "sortedLinkedList.h"

/*
#include linkedList.h �� ��� ����ü, ��ũ�帮��Ʈ ����ü,
���� �Լ����� ���� �� ���ǵǾ� �ֱ� ������ �̸� include �Ͽ� ���
���� sortedLinkedList_main.c�� �����Ű�� ���ؼ���
sortedLinkedList.c, sortedLinkedList.h �Ӹ� �ƴ϶�
LinkedList.c, LinkedList.h�� �ʿ��ϴ�.
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
