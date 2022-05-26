/*
    Team Morisaki

    Claude, Austin // member 1
    Morisaki, Shoto // member 2
    Mustafa Atakan Tan // member 3

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/

#ifndef MEMBERLIST_H
#define MEMBERLIST_H
#include "Hike.h"
#include "Member.h"
#include <string>
#include <map>
#include <set>
//You were missing global constant 
const int MEMBER_ID = 111;
class MemberList : public Member
{
public:
    MemberList();
    void addMember(const std::string& firstName, const std::string& lastName);
    void addMember(std::string firstName, std::string lastName, int points);
    int getLastID();
    int getPoints(int memberID);
    void printMember(int memberID, std::string lastName);
    void clearList();
    ~MemberList();

private:
    int members = 0;
    std::set<Member>* ptrToSet;
};
#endif

