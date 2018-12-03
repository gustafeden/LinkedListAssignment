#include "LRUCache.h"
#include <sstream>

LRUCache::LRUCache(size_t size)
{
	linkedlist = new LinkedList();
	this->linkedlist->maxsize = size;
}


LRUCache::~LRUCache()
{
}
void LRUCache::AddToCache(int id, std::string txt) {
	AddToLinkedList(this->linkedlist, id, txt.c_str());
	
}

std::string LRUCache::GetFromCache(int id) {
	char * txtFromList = nullptr;
	std::string s;
	txtFromList = GetFromId(this->linkedlist, id);
	if(txtFromList != NULL){
		s = std::string(txtFromList);
		txtFromList = nullptr;
		return s;
	}
	else {
		return s;
	}
		
}
std::stringstream LRUCache::print_cache() {
	std::stringstream ss;
	Node * temp = linkedlist->head;
	if (temp != NULL)
		ss << temp->id << " " << temp->txt << std::endl;
	while (true) {
		if (temp->next != NULL) {
		ss << temp->next->id << " " << temp->next->txt << std::endl;
		temp = temp->next;
	}
	else
			break;
	}
	return ss;
}

void LRUCache::setMaxSize(size_t size) {
	this->linkedlist->maxsize = size;
}