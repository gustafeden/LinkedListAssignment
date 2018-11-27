#define _CRT_SECURE_NO_WARNINGS
#pragma once
typedef struct Node Node;
struct Node{
	int id;
	char *txt;
	struct Node *next;
};

typedef struct {
	struct Node *head;
	int counter;
} LinkedList;

//void AddToLinkedList(LinkedList * linkedlist, int id, const char *txt);
void MoveNodeToHead(LinkedList * linkedlist, struct Node * node, struct Node * LastNode);
//char * GetFromId(LinkedList * linkedlist, int id);
void RemoveLast(LinkedList * linkedlist);
struct Node * NewNode(int id, char * txt);