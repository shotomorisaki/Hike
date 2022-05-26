/*
	Team Morisaki

	Claude, Austin // member 1
	Morisaki, Shoto // member 2
	Mustafa Atakan Tan // member 3

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#include <iostream>
#include "HikeList.h"
#include "Member.h"
#include "MemberList.h"
#include "Reservations.h"
#include "Interface.h"
#include "HikeReader.h"
#include "ReservationsReader.h"
#include "memberReader.h"
using namespace std;
int main() {
    HikeList HList;
    getHikeData(HList);

    Reservations reservationSet;
    getReservationData(reservationSet);

    MemberList MList;
    getMemberListData(MList);

    Interface newObj;
    newObj.displayMenu();
    newObj.processReservation(HList, MList, reservationSet);

    return 0;
    system("pause");
}