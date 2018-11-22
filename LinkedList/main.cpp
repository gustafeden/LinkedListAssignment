#include <iostream>
#include "DisplayMessageEndpoint.h"
#include "LRUCache.h"
#include <Windows.h>

std::string GetDestinationFrom(int destinationId, LRUCache * cache)
{
	std::string destinationtxt = cache->GetFromCache(destinationId);
	if (destinationtxt.size() != 0) {
		Sleep(500);
		return destinationtxt;
	}
	else {
		DisplayMessageDestinationService service;
		destinationtxt = service.GetDestinationName(destinationId);
		cache->AddToCache(destinationId, destinationtxt);
		return destinationtxt;
	}
}

void main()
{
	SetConsoleOutputCP(1252);
	LRUCache * cache = new LRUCache();
	DisplayMessageEndpoint *endPoint = new DisplayMessageEndpoint();
	while (true)
	{
		DisplayMessageEndpoint::DisplayEntry nextDisplayMessage = endPoint->GetDisplayMessage();
		std::cout << nextDisplayMessage.time << "   " << nextDisplayMessage.newTime 
			<< "      " << nextDisplayMessage.track << "  " << GetDestinationFrom(nextDisplayMessage.destinationId, cache)
			<< std::endl;
	}
}