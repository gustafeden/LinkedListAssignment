#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void AddToLinkedList(LinkedList * linkedlist, int id, char *txt) {
	if (linkedlist->counter >= 6)
		RemoveLast(linkedlist);
	Node * newnode = NewNode(id, txt);
	if(linkedlist->counter != 0)
		newnode->next = linkedlist->head;
	linkedlist->head = newnode;
	linkedlist->counter += 1;
}

void MoveNodeToHead(LinkedList * linkedlist, Node * FoundNode, Node * LastNode) {

}

Node * GetFromId(LinkedList * linkedlist, int id) {
	Node * FoundNode = linkedlist->head;
	Node * LastNode = NULL;
	int temp_counter = 0;
	while (1){
		if (FoundNode->id == id) {
			MoveNodeToHead(linkedlist, FoundNode);
			return FoundNode;
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




void main() {
	LinkedList * linkedlist = malloc(sizeof(LinkedList));
	linkedlist->counter = 0;
	linkedlist->head = NULL;
	AddToLinkedList(linkedlist, 4, "Göteborg");
	AddToLinkedList(linkedlist, 6, "Falun");
	AddToLinkedList(linkedlist, 8, "Uppsala");
	AddToLinkedList(linkedlist, 9, "Västerås");
	AddToLinkedList(linkedlist, 2, "Malmö");
	AddToLinkedList(linkedlist, 16, "Hallsberg");

	AddToLinkedList(linkedlist, 13, "linkoping");
}