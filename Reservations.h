/*
    Team Morisaki

    Claude, Austin // member 1
    Morisaki, Shoto // member 2
    Mustafa Atakan Tan // member 3

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/

#ifndef RESERVATIONS_H
#define RESERVATIONS_H
#include <string>
#include <iostream>
const int RESERVATION_NUMBER = 50001;
//This is signed by Austin part
class Node
{
public:
    Node() : reservationNumber(0), memberID(0), prev(nullptr), next(nullptr) {}
    Node(int theReservationNumber, int theMemberID, std::string theHikeName, Node* prevLink, Node* nextLink)
        : reservationNumber(theReservationNumber), memberID(theMemberID), HikeName(theHikeName), prev(prevLink), next(nextLink) {}
    int getReservationNumber() const { return reservationNumber; }
    int getMemberID() const { return memberID; }
    std::string getHikeName()const { return HikeName; }
    Node* getPrev() const { return prev; }
    Node* getNext() const { return next; }
    void setData(int theReservationNumber, int theMemberID, std::string hikeName) {
        reservationNumber = theReservationNumber; memberID = theMemberID; HikeName = hikeName;
    }
    void setPrev(Node* prevLink) { prev = prevLink; }
    void setNext(Node* nextLink) { next = nextLink; }
    ~Node() {}
private:
    int reservationNumber;
    int memberID;
    std::string HikeName;
    Node* prev;
    Node* next;

};

//This is signed by Shoto part
class Reservations {
public:
    Reservations();
    int addReservation(int memberID, std::string namHike);
    void cancelReservation(int reservation_number);
    void printReservation(int reservNum, HikeList newHikeList, MemberList newMemberList);

private:
    Node* findReservation(int reservNum);
    Node* first;
    Node* last;
    int count = 0;
};
#endif

