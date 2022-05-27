//fixed errors(atakan)

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

#include "Member.h"

#include <string>
#include <set>


const int MEMBER_ID = 111;//global constant storing first ID 

class MemberList
{
public:
    MemberList();

    void addMember(const std::string& firstName, const std::string& lastName);
    void addMember(const std::string firstName, const std::string lastName, int points);

    int getLastID();
    int getPoints(int memberID);

    void printMember(int memberID, const std::string lastName);

    void clearList();
    ~MemberList();

private:
    int members = 0;
    std::set<Member>* ptrToSet;
};
#endif
