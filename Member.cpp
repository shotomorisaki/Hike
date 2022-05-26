/*
    Team Morisaki

    Claude, Austin // member 1
    Morisaki, Shoto // member 2
    Mustafa Atakan Tan // member 3

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/

//This is signed by Shoto part
#include "Member.h"
#include <string>
#include <iostream>
using namespace std;

Member::Member()
{
    int memberID = 0;
    string firstName;
    string lastName;
    int points = 0;
}

Member::Member(string fName, string lName)
{
    firstName = fName;
    lastName = lName;
}

bool Member::operator<(const Member& rightMember)const
{
    return memberID < rightMember.memberID;
}

void Member::addPoints(int val)
{
    points += val;
}

void Member::setID(int id)
{
    memberID = id;
}

int Member::getMemberID() const
{
    return memberID;
}
string Member::getLastName() const
{
    return lastName;
}

int Member::getPoints() const
{
    return points;
}

void Member::print() const
{
    cout << firstName << ", " << lastName << endl;
    cout << "\t Points available: " << points << endl;
}