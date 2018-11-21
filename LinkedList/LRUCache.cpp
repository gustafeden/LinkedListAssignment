#include "LRUCache.h"


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
	if (txtFromList != NULL) {
		std::string s(txtFromList);
		txtFromList = nullptr;
		return s;
	}
	else {
		return "";
	}
		
}