#pragma once
//Döp om denna till DoubleLinkedList eller Linkedlist
//och se till att bara en av dem är inkluderad i projectet
#include "DoubleLinkedList.h"

#include <string>

extern "C" void AddToLinkedList(LinkedList * linkedlist, int id, const char *txt);
extern "C" char * GetFromId(LinkedList * linkedlist, int id);
class LRUCache
{
private:
	LinkedList * linkedlist;
public:
	LRUCache();
	~LRUCache();
	void AddToCache(int id, std::string txt);
	std::string GetFromCache(int id);
	std::stringstream print_cache();
};

