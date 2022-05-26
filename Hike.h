/*
	Team Morisaki

	Claude, Austin // member 1
	Morisaki, Shoto // member 2
	Mustafa Atakan Tan // member 3

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#ifndef HIKE_H
#define HIKE_H
#include <string>
class Hike {
public:
	Hike();

	Hike(std::string newLocation, std::string newName, int newDuration, char newDiff);

	friend std::ostream& operator<<(std::ostream& out, const Hike& myHike);

	std::string getLocation()const;

	std::string getName()const;

	bool operator<(const Hike& rightHike) const;


	int getDuration()const;


	char getDifficulty()const;

	~Hike();




private:
	std::string location;
	std::string name;
	int duration = 0;
	char difficulty;

};

#endif