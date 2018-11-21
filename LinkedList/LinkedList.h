#define _CRT_SECURE_NO_WARNINGS
#pragma once
//#include "LinkedList.c"
//#ifndef LINKEDLIST_H
//#define LINKEDLIST_H
typedef struct Node Node;
struct Node{
	int id;
	char *txt;
	struct Node *next;
};

//#endif // !LINKEDLIST_H


typedef struct {
	struct Node *head;
	int counter;
} LinkedList;

//void AddToLinkedList(LinkedList * linkedlist, int id, const char *txt);
void MoveNodeToHead(LinkedList * linkedlist, Node * node, Node * LastNode);
//char * GetFromId(LinkedList * linkedlist, int id);
void RemoveLast(LinkedList * linkedlist);
Node * NewNode(int id, char * txt);