#include <iostream>
#include "DisplayMessageEndpoint.h"
#include "LRUCache.h"
#include <Windows.h>
#include <vector>
#include <sstream>

std::string GetDestinationFrom(int destinationId, LRUCache * cache)
{
	std::string destinationtxt = cache->GetFromCache(destinationId);
	if (destinationtxt.size() != 0) {
		Sleep(100);
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
	std::vector <std::string> messageboard;
	while (true)
	{
		if (messageboard.size() > 10)
			messageboard.erase(messageboard.begin());
		std::stringstream newmessage;
		DisplayMessageEndpoint::DisplayEntry nextDisplayMessage = endPoint->GetDisplayMessage();
		newmessage << nextDisplayMessage.time << "   " << nextDisplayMessage.newTime 
			<< "      " << nextDisplayMessage.track << "  " << GetDestinationFrom(nextDisplayMessage.destinationId, cache)
			<< std::endl;
		messageboard.push_back(newmessage.str());
		system("cls");

		for (auto &message : messageboard) {
			std::cout << message;
		}
		std::cout << std::endl << cache->print_cache().str() << std::endl;
	}
}