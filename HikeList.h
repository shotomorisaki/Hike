/*
	Team Morisaki

	Claude, Austin // member 1
	Morisaki, Shoto // member 2
	Mustafa Atakan Tan // member 3

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#ifndef HIKELIST_H
#define HIKELIST_H
#include "Hike.h"
#include <string>
#include <map>
class HikeList :public Hike {
public:
	HikeList();

	void printByDuration(int findDays);

	void addHike(Hike newHike, double newPrice);

	void addHike(std::string newLocation, std::string newName, int newDuration, char newDifficulty, double newPrice);

	double getPrice(std::string hikeName)const;

	void printAllLocations();

	void printByLocation(std::string hikeLocation);

	void printByDuration();

	void printByDifficulty(char hikeDifficulty);

	void printByPrice();

	void printByHikeName(std::string hikeName);

	void clearList();





private:
	std::multimap<Hike, double>mapList;
	double price = 0;
};

#endif
