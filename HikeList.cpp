/*
	Team Morisaki

	Claude, Austin // member 1
	Morisaki, Shoto // member 2
	Mustafa Atakan Tan // member 3

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

//This is signed by Austin part
#include "HikeList.h"
#include "Hike.h"
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
HikeList::HikeList() {

}



void HikeList::addHike(Hike newHike, double newPrice) {
	mapList.insert(make_pair(newHike, newPrice));
}

void HikeList::addHike(string newLocation, std::string newName, int newDuration, char newDifficulty, double newPrice) {
	Hike newHike(newLocation, newName, newDuration, newDifficulty);
	this->addHike(newHike, newPrice);
}

double HikeList::getPrice(string hikeName)const {
	auto iter = find_if(mapList.begin(), mapList.end(), [&hikeName](const pair<Hike, double>& elem) {
		return elem.first.getName() == hikeName;
		});
	return iter->second;
}

void HikeList::printAllLocations() {
	auto iter = mapList.begin();
	iter++;
	for (auto it = mapList.begin(); iter != mapList.end(); ++it) {
		if (iter->first.getLocation() != it->first.getLocation()) {
			cout << it->first.getLocation() << endl;
			iter++;
		}
		else {
			iter++;
		}
	}
}

void HikeList::printByLocation(string hikeLocation) {
	for (auto findLocation = mapList.begin(); findLocation != mapList.end();) {

		findLocation = find_if(findLocation, mapList.end(), [hikeLocation](const pair<Hike, double>& elem) {
			return elem.first.getLocation() == hikeLocation;
			});

		if (findLocation != mapList.end()) {
			cout << "\t" << findLocation->first.getName() << " (" << findLocation->first.getLocation() << ")" << endl;
			cout << "\t  Difficulty: " << findLocation->first.getDifficulty() << endl;
			cout << "\t  Duration: " << findLocation->first.getDuration() << endl;
			cout << "\t  $" << findLocation->second << endl << endl;
			findLocation++;
		}
	}

}

void HikeList::printByDuration() {
	multimap<int, string>tempHike;
	for (auto iter = mapList.begin(); iter != mapList.end(); iter++) {
		tempHike.insert(make_pair(iter->first.getDuration(), iter->first.getLocation()));

	}
	for_each(tempHike.begin(), tempHike.end(), [](const auto& elem) {
		cout << "\t(" << elem.first << ") " << elem.second << endl;
		});
}

void HikeList::printByDuration(int findDays) {
	for (auto iter : mapList) {
		if (iter.first.getDuration() == findDays) {
			cout << "\t " << iter.first.getName() << " (" << iter.first.getLocation() << ") " << endl;
			cout << "\t Difficulty: " << iter.first.getDifficulty() << endl;
			cout << "\t Duration: " << iter.first.getDifficulty() << " Day(s) " << endl;
		}
	}
}

void HikeList::printByDifficulty(char hikeDifficulty) {
	for (auto iter : mapList) {
		if (iter.first.getDifficulty() == hikeDifficulty) {
			cout << "\t(" << iter.first.getDifficulty() << ") " << iter.first.getName() << ", " << iter.first.getLocation() << endl;
		}
	}
}

void HikeList::printByPrice() {
	multimap<double, pair<string, string>> byPrice;
	for (auto iter = mapList.begin(); iter != mapList.end(); iter++) {
		pair<string, string>newPair(iter->first.getLocation(), iter->first.getName());
		byPrice.emplace(iter->second, newPair);
	}

	for (auto iter : byPrice) {

		cout << "\t$ " << fixed << showpoint << setprecision(2) << iter.first << " - ";
		cout << iter.second.first << " (" << iter.second.first << ")" << endl;

	}
}

void HikeList::printByHikeName(string hikeName) {
	auto iter = find_if(mapList.begin(), mapList.end(), [hikeName](const pair<Hike, double>& elem) {
		return elem.first.getName() == hikeName;
		});
	cout << "\t" << iter->first.getName() << " (" << iter->first.getLocation() << ") " << endl;
	cout << "\t  Difficulty: " << iter->first.getDifficulty() << endl;
	cout << "\t  Duration: " << iter->first.getDuration() << " Day(s) " << endl;
	cout << "\t  $" << fixed << showpoint << setprecision(2) << iter->second << endl << endl;


}

void HikeList::clearList() {
	mapList.clear();
}






