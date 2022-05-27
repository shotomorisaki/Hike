//fixed the errors (atakan)

/*
    Team Morisaki
    Claude, Austin // member 1
    Morisaki, Shoto // member 2
    Mustafa Atakan Tan // member 3
    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/

//This is signed by Atakan part
#include "Interface.h"
#include "MemberList.h"
#include <iostream>
#include <algorithm>


using namespace std;

MemberList::MemberList()
{
    ptrToSet = new set<Member>;
}

void MemberList::addMember(const string& firstName, const string& lastName)
{
    Member newMember(firstName, lastName);
    int memberID = MEMBER_ID;
    //could not figure out a way to use std::rbegin() here
    if (ptrToSet->empty())
    {
        newMember.setID(memberID);
    }
    else
    {
        newMember.setID((ptrToSet->rbegin())->getMemberID() + 1);
    }
    ptrToSet->insert(newMember);
}

void MemberList::addMember(string firstName, string lastName, int points)
{
    int id = MEMBER_ID;
    if (!ptrToSet->empty())
        id = ptrToSet->rbegin()->getMemberID() + 1;

    Member newMember(firstName, lastName);
    newMember.setID(id);
    newMember.addPoints(points);
    ptrToSet->insert(newMember);
}

int MemberList::getLastID() {
    auto IDiter = ptrToSet->rbegin();
    return IDiter->getMemberID();
}

int MemberList::getPoints(int memberID) {
    //need an iterator to find our memberID
    auto iter = find_if(ptrToSet->begin(), ptrToSet->end(), [memberID](const Member& elem) {

        return (elem.getMemberID() == memberID);
        });
    return iter->getPoints();
}

void MemberList::printMember(int memberID, string lastName) {
    auto iter = find_if(ptrToSet->begin(), ptrToSet->end(), [memberID](const Member& elem) {
         elem.print();
        return (elem.getMemberID() == memberID);
        });
    
    cout << "\t Membership # " << iter->getMemberID() << endl;
}
void MemberList::clearList() {
    delete ptrToSet;
}

MemberList::~MemberList() {
    clearList();
}
