#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LIMIT 10
void AddToLinkedList(LinkedList * linkedlist, int id, const char *txt) {
	if (linkedlist->counter >= LIMIT)
		RemoveLast(linkedlist);
	Node * newnode = NewNode(id, txt);
	if(linkedlist->counter != 0)
		newnode->next = linkedlist->head;
	linkedlist->head = newnode;
	linkedlist->counter += 1;
}

void MoveNodeToHead(LinkedList * linkedlist, Node * FoundNode, Node * LastNode) {
	if (FoundNode->next == NULL) 
		LastNode->next = NULL;
	else
		LastNode->next = FoundNode->next;

	FoundNode->next = linkedlist->head;
	linkedlist->head = FoundNode;
}

char * GetFromId(LinkedList * linkedlist, int id) {
	Node * FoundNode = linkedlist->head;
	Node * LastNode = NULL;
	if (linkedlist->counter != 0 && FoundNode->id == id)
		return FoundNode->txt;
	int temp_counter = 0;
	while (temp_counter != linkedlist->counter){
		if (FoundNode->id == id) {
			MoveNodeToHead(linkedlist, FoundNode, LastNode);
			LastNode = NULL;
			return FoundNode->txt;
		}
		LastNode = FoundNode;
		FoundNode = FoundNode->next;
		temp_counter += 1;
	}

	return NULL;
}

void RemoveLast(LinkedList * linkedlist) {
	Node * temp = NULL;
	Node * NewLast = NULL;
	int temp_counter = 0;
	while (temp_counter != linkedlist->counter - 1) {
		if (temp_counter == 0)
			NewLast = linkedlist->head;
		else 
			NewLast = NewLast->next;
		temp_counter += 1;
	}
	temp = NewLast->next;
	free(temp->txt);
	temp->txt = NULL;
	free(temp);
	NewLast->next = NULL;
	NewLast = NULL;
	temp = NULL;
	linkedlist->counter -= 1;

}

Node * NewNode(int id, char * txt) {
	Node * newnode = malloc(sizeof(Node));
	newnode->id = id;
	newnode->txt = malloc(sizeof(char) * strlen(txt) + 1);
	strcpy(newnode->txt, txt);
	newnode->next = NULL;
	return newnode;
}




void mainsssss() {
	/*LinkedList * linkedlist = malloc(sizeof(LinkedList));
	linkedlist->counter = 0;
	linkedlist->head = NULL;
	AddToLinkedList(linkedlist, 4, "Göteborg");
	AddToLinkedList(linkedlist, 6, "Falun");
	AddToLinkedList(linkedlist, 8, "Uppsala");
	AddToLinkedList(linkedlist, 9, "Västerås");
	AddToLinkedList(linkedlist, 2, "Malmö");
	AddToLinkedList(linkedlist, 13, "linkoping");
	AddToLinkedList(linkedlist, 16, "Hallsberg");
	
	system("pause");*/
}