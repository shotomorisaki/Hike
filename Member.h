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
    Member();
    Member(std::string fName, std::string lName);
    bool operator<(const Member& rightMember)const;
    void addPoints(int val);
    void setID(int id);
    int getMemberID() const;
    std::string getLastName() const;
    int getPoints() const;
    void print() const;

private:
    int memberID = 0;
    std::string firstName;
    std::string lastName;
    int points = 0;
};

#endif