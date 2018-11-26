
#include "DoubleLinkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define CACHE_LIMIT 10

void AddToLinkedList(LinkedList * linkedlist, int id, const char *txt) {
	if (linkedlist->counter >= CACHE_LIMIT)
		RemoveLast(linkedlist);
	Node * newnode = NewNode(id, txt);
	if (linkedlist->counter != 0) {
		newnode->next = linkedlist->head;
		linkedlist->head->prev = newnode;
	}
	if (linkedlist->counter == 0) {
		linkedlist->tail = newnode;
	}
	linkedlist->head = newnode;
	linkedlist->counter += 1;
}

void MoveNodeToHead(LinkedList * linkedlist, Node * FoundNode) {
	Node * temp = linkedlist->head;
	if (FoundNode->next == NULL) {
		FoundNode->prev->next = NULL;
		linkedlist->tail = FoundNode->prev;
	}
	else {
		FoundNode->prev->next = FoundNode->next;
		FoundNode->next->prev = FoundNode->prev;
	}
	
	
	linkedlist->head = FoundNode;
	FoundNode->prev = NULL;
	FoundNode->next = temp;
	temp->prev = FoundNode;

}

char * GetFromId(LinkedList * linkedlist, int id) {
	Node * FoundNode = linkedlist->head;
	if (linkedlist->counter != 0 && FoundNode->id == id)
		return FoundNode->txt;
	int temp_counter = 0;
	while (temp_counter != linkedlist->counter) {
		if (FoundNode->id == id) {
			MoveNodeToHead(linkedlist, FoundNode);
			return FoundNode->txt;
		}
		FoundNode = FoundNode->next;
		temp_counter += 1;
	}
	return NULL;
}

void RemoveLast(LinkedList * linkedlist) {
	Node * newtail = linkedlist->tail->prev;
	free(linkedlist->tail->txt);
	linkedlist->tail->txt = NULL;
	linkedlist->tail->prev = NULL;
	free(linkedlist->tail);
	linkedlist->tail = newtail;
	linkedlist->tail->next = NULL;
	linkedlist->counter -= 1;
}

Node * NewNode(int id, char * txt) {
	Node * newnode = malloc(sizeof(Node));
	newnode->id = id;
	newnode->txt = malloc(sizeof(char) * strlen(txt) + 1);
	strcpy(newnode->txt, txt);
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}




void mainsssss() {
	/*LinkedList * linkedlist = malloc(sizeof(LinkedList));
	linkedlist->counter = 0;
	linkedlist->head = NULL;
	AddToLinkedList(linkedlist, 4, "G�teborg");
	AddToLinkedList(linkedlist, 6, "Falun");
	AddToLinkedList(linkedlist, 8, "Uppsala");
	AddToLinkedList(linkedlist, 9, "V�ster�s");
	AddToLinkedList(linkedlist, 2, "Malm�");
	AddToLinkedList(linkedlist, 13, "linkoping");
	AddToLinkedList(linkedlist, 16, "Hallsberg");

	system("pause");*/
}