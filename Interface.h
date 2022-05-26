/*
    Team Morisaki

    Claude, Austin // member 1
    Morisaki, Shoto // member 2
    Mustafa Atakan Tan // member 3

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/

#ifndef INTERFACE_H
#define INTERFACE_H
#include "Hike.h"
#include "HikeList.h"
#include "MemberList.h"
#include "Reservations.h"
#include <string>
#include <map>
class Interface :public Hike {
public:
    void processReservation(HikeList& Hlist, MemberList& MList, Reservations& reservations);
    void displayMenu();
    void chooseByDifficulty(HikeList& HList, MemberList& MList, Reservations& reservations);
    void chooseByPrice(HikeList& HList, MemberList& MList, Reservations& reservations);
    int askIfMember(MemberList& MList);
    int addNewMember(MemberList& MList);
    void chooseByLocation(HikeList& Hlist, MemberList& MList, Reservations& reservations);
    void chooseByDuration(HikeList& Hlist, MemberList& MList, Reservations& reservations);
    void makeReservation(HikeList& HList, MemberList& MList, Reservations& reservations);
    void viewReservation(HikeList& HList, MemberList& MList, Reservations& reservations);
    void cancelReservation(HikeList& HList, MemberList& MList, Reservations& reservations);
    void askToReserve(HikeList& HList, MemberList& MList, Reservations& reservations);

private:
    int userSelection = 8;
    int numOfDays = 0;
    int reservationNumber = 0;
    char memberOrNot;
    int memberID = 0;
    char difficultyLevel;
    char reservationsOrNot;
    std::string lName;
    std::string fName;
    std::string chooseLocation;
};
#endif