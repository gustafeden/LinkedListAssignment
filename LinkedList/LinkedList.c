
#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define CACHE_LIMIT 10

void AddToLinkedList(LinkedList * linkedlist, int id, const char *txt) {
	if (linkedlist->counter >= CACHE_LIMIT)
		RemoveLast(linkedlist);
	struct Node * newnode = NewNode(id, txt);
	if(linkedlist->counter != 0)
		newnode->next = linkedlist->head;
	linkedlist->head = newnode;
	linkedlist->counter += 1;
}

void MoveNodeToHead(LinkedList * linkedlist, struct Node * FoundNode, struct Node * LastNode) {
	if (FoundNode->next == NULL) 
		LastNode->next = NULL;
	else
		LastNode->next = FoundNode->next;

	FoundNode->next = linkedlist->head;
	linkedlist->head = FoundNode;
}

char * GetFromId(LinkedList * linkedlist, int id) {
	struct Node * FoundNode = linkedlist->head;
	struct Node * LastNode = NULL;
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
	struct Node * temp = NULL;
	struct Node * NewLast = NULL;
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

struct Node * NewNode(int id, char * txt) {
	struct Node * newnode = (struct Node*) malloc(sizeof(struct Node));
	newnode->id = id;
	newnode->txt = (char *) malloc(sizeof(char) * strlen(txt) + 1);
	strcpy(newnode->txt, txt);
	newnode->next = NULL;
	return newnode;
}

//måste vi malloca hela tiden när vi vet cache limit?