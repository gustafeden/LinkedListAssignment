
#define _CRT_SECURE_NO_WARNINGS
#pragma once
typedef struct Node Node;
struct Node {
	int id;
	char *txt;
	struct Node *next, *prev;
};

typedef struct {
	struct Node *head, *tail;
	int counter;
} LinkedList;

//void AddToLinkedList(LinkedList * linkedlist, int id, const char *txt);
void MoveNodeToHead(LinkedList * linkedlist, Node * node, Node * LastNode);
//char * GetFromId(LinkedList * linkedlist, int id);
void RemoveLast(LinkedList * linkedlist);
Node * NewN