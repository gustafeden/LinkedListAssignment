
#define _CRT_SECURE_NO_WARNINGS
#pragma once
//#include "LinkedList.c"
typedef struct {
	int id;
	char *txt;
	struct Node *next;
}Node;

typedef struct {
	struct Node *head;
	int counter;
} LinkedList;

void AddToLinkedList(LinkedList * linkedlist, int id, char *txt);
void MoveNodeToHead(LinkedList * linkedlist, Node * node, Node * LastNode);
char * GetFromId(LinkedList * linkedlist, int id);
void RemoveLast(LinkedList * linkedlist);
Node * NewNode(int id, char * txt);