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
#include "Hike.h"
#include <iostream>
using namespace std;

Hike::Hike() {
	duration = 0;
	difficulty = 'c';
}

bool Hike::operator<(const Hike& rightHike)const {
	return location < rightHike.getLocation();
}

Hike::Hike(string newLocation, string newName, int newDuration, char newDiff) {
	location = newLocation;
	name = newName;
	duration = newDuration;
	difficulty = newDiff;
}

ostream& operator<<(ostream& out, const Hike& myHike) {
	out << myHike.name << " (" << myHike.location << ") \t";
	out << "Difficulty: " << myHike.difficulty << "\t";
	out << "Duration: " << myHike.duration << "\t";
	return out;
}

string Hike::getLocation()const {
	return location;
}

string Hike::getName()const {
	return name;
}

int Hike::getDuration()const {
	return duration;

}

char Hike::getDifficulty()const {
	return difficulty;
}

Hike::~Hike() {

}


