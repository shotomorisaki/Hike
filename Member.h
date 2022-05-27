/*
    Team Morisaki
    Claude, Austin // member 1
    Morisaki, Shoto // member 2
    Mustafa Atakan Tan // member 3
    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/

#ifndef MEMBER_H
#define MEMBER_H

#include <string>

class Member
{
public:

    Member(int memberID = 0, int points = 0) {};//default constructor
    Member(const std::string fName, const std::string lName); //overloaded constructor


    void addPoints(int val);
    void setID(int id);

    int getMemberID() const;
    std::string getLastName() const;
    int getPoints() const;

    bool operator<(const Member& rightMember)const;

    void print() const;

    Member();//destructor

private:
    int memberID = 0;
    int points = 0;

    std::string firstName;
    std::string lastName;
    
};
#endif
