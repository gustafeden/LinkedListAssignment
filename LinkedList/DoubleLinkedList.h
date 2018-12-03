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
	int maxsize;
} LinkedList;

void MoveNodeToHead(LinkedList * linkedlist, Node * node);
void RemoveLast(LinkedList * linkedlist);
Node * NewNode(int id, char * txt);
