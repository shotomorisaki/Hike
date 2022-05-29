#include "HikeList.h"
#include "MemberList.h"
#include "Reservations.h"
#include <string>
#include <iostream>
using namespace std;
Reservations::Reservations()
{
    int count = 0;
    first = nullptr;
    last = nullptr;
}
int Reservations::addReservation(int memberID, string hikeName)
{
    if (first == nullptr)
    {
        last = new Node(RESERVATION_NUMBER, memberID, hikeName, nullptr, nullptr);
        first = last;
        ++count;
        return RESERVATION_NUMBER;
    }
    else
    {
        Node* newNode = new Node();
        newNode->setData(newNode->getReservationNumber() + RESERVATION_NUMBER + count, memberID, hikeName);
        last->setNext(newNode);
        last = last->getNext();
        last->setPrev(last->getPrev());
        ++count;
        return newNode->getReservationNumber();
    }
}
Node* Reservations::findReservation(int reservNum)
{
    if (first->getReservationNumber() == reservNum)
        return first;
    else if (last->getReservationNumber() == reservNum)
        return last;
    else
    {
        Node* temp = first->getNext();
        for (int i = 0; i < count; i++)
        {
            if (temp->getReservationNumber() == reservNum)
                return temp;
            else
                temp = temp->getNext();
        }
        return temp;
    }
}
void Reservations::cancelReservation(int reservation_number)
{
    if (count == 1) {
        delete first;
        delete last;
        last = nullptr;
        first = nullptr;
    }
    else {
        Node* temp;
        temp = findReservation(reservation_number);
        temp->getPrev()->setNext(temp->getNext());
        temp->getNext()->setPrev(temp->getPrev());
        delete temp;
        temp = nullptr;
    }
}
void Reservations::printReservation(int reservNum, HikeList newHikeList, MemberList newMemberList)
{
    Node* ptr = findReservation(reservNum);
    string hikeName = ptr->getHikeName();
    newHikeList.printByHikeName(hikeName);
    cout << endl;
    int memberID = ptr->getMemberID();
    int points = newMemberList.getPoints(memberID);
    double price = newHikeList.getPrice(hikeName);
    price = price - (points / 100);
    cout << "\tDiscounted price using points: " << price << endl;
}
