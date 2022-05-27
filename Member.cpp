//fixed the errors

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
#include <iomanip>

using namespace std;

Member::Member()
{
    
    string firstName;
    string lastName;

}

Member::Member(string fName, string lName)
{
    firstName = fName;
    lastName = lName;
    memberID = 0;
    points = 0;
}

void Member::addPoints(int val)
{
    points += val;
}
//Accessor functions
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

bool Member::operator<(const Member& rightMember)const
{
    return memberID < rightMember.memberID;
}

void Member::print() const
{
    cout << firstName << ", " << lastName << endl;
    cout << "\t Points available: " << points << endl;
}
