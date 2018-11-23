
#include "LRUCache.h"
#include <sstream>
#define ifnnull(a) if(a != NULL)

LRUCache::LRUCache()
{
	linkedlist = new LinkedList();
}


LRUCache::~LRUCache()
{
}
void LRUCache::AddToCache(int id, std::string txt) {
	AddToLinkedList(this->linkedlist, id, txt.c_str());
}

std::string LRUCache::GetFromCache(int id) {
	char * txtFromList = nullptr;
	txtFromList = GetFromId(this->linkedlist, id);
	ifnnull(txtFromList){
		std::string s(txtFromList);
		txtFromList = nullptr;
		return s;
	}
	else {
		return "";
	}
		
}
std::stringstream LRUCache::print_cache() {
	std::stringstream ss;
	Node * temp = linkedlist->head;
	ifnnull (temp)
		ss << temp->id << " " << temp->txt << std::endl;
	while (true) {
		ifnnull (temp->next) {
		ss << temp->next->id << " " << temp->next->txt << std::endl;
		temp = temp->next;
	}
	else
			break;
	}
	return ss;
}