/*
    Team Morisaki

    Claude, Austin // member 1
    Morisaki, Shoto // member 2
    Mustafa Atakan Tan // member 3

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/

#include "Interface.h"
#include <string>
#include <iostream>
using namespace std;
// Shoto : chooseByDifficulty(), chooseByPrice(), askIfMember(), addNewMember(), 
// Austin : displayMenu(), processReservation(), chooseByLocation(), chooseByDuration(),
//  Atakan : makeReservation(), viewReservation(), cancelReservation(), askToReserve(), 
void Interface::displayMenu() {
    cout << "***************************************************" << endl;
    cout << "\t \t HIKING IN THE US" << endl;
    cout << "***************************************************" << endl << endl;
    cout << "\t 1. Browse by location" << endl;
    cout << "\t 2. Browse by duration" << endl;
    cout << "\t 3. Browse by difficulty" << endl;
    cout << "\t 4. Browse by price" << endl;
    cout << "\t 5. Make a reservation " << endl;
    cout << "\t 6. View reservation" << endl;
    cout << "\t 7. Cancel reservation" << endl;
    cout << "\t 8. Exit" << endl << endl;
}
//This is signed by Austin part
void Interface::processReservation(HikeList& Hlist, MemberList& MList, Reservations& reservations) {
    cout << "Please make a selection: ";
    cin >> userSelection;
    if (userSelection == 1)
        chooseByLocation(Hlist, MList, reservations);
    else if (userSelection == 2)
        chooseByDuration(Hlist, MList, reservations);
    else if (userSelection == 3)
        chooseByDifficulty(Hlist, MList, reservations);
    else if (userSelection == 4)
        chooseByPrice(Hlist, MList, reservations);
    else if (userSelection == 5)
        makeReservation(Hlist, MList, reservations);
    else if (userSelection == 6)
        viewReservation(Hlist, MList, reservations);
    else if (userSelection == 7)
        cancelReservation(Hlist, MList, reservations);
    else if (userSelection == 8) 
        cout << "Thank you for visiting!";
}
//This is signed by Austin part
void Interface::chooseByLocation(HikeList& Hlist, MemberList& MList, Reservations& reservations) {
    //you cant call a function using HikeList::printbyprice() need a HikeList obj like so..
    Hlist.printAllLocations();
    cout << endl;
    cout << "Choose a location: ";
    cin >> chooseLocation;
    //you cant call a function using HikeList::printbyprice() need a HikeList obj like so..
    Hlist.printByLocation(chooseLocation);
    askToReserve(Hlist, MList, reservations);
}
//This is signed by Austin part
void Interface::chooseByDuration(HikeList& Hlist, MemberList& MList, Reservations& reservations) {
    Hlist.printByDuration();
    //you cant call a function using HikeList::printbyprice() need a HikeList obj like so..
    cout << "How many days are you considering: ";
    cin >> numOfDays;
    Hlist.printByDuration(numOfDays);
    askToReserve(Hlist, MList, reservations);
}

void Interface::chooseByDifficulty(HikeList& HList, MemberList& MList, Reservations& reservations)
{
    cout << "Choose difficulty level:" <<
        "\te. easy" << "\tm. moderate" << "\ts. strenuous" << endl;
    cin >> difficultyLevel;
    cout << "Your choice: " << difficultyLevel << endl;
    //you cant call a function using HikeList::printbyprice() need a HikeList obj like so..
    HList.printByDifficulty(difficultyLevel);
    cout << "Would you like to reserve? (y/n)" << endl;
    cin >> reservationsOrNot;
    if (reservationsOrNot == 'y')
        askToReserve(HList, MList, reservations);
}

void Interface::chooseByPrice(HikeList& HList, MemberList& MList, Reservations& reservations)
{
    //you cant call a function using HikeList::printbyprice() need a HikeList obj like so..
    HList.printByPrice();
    cout << "Would you like to reserve? (y/n)" << endl;
    //you cant cin an obj of type reservation the compiler does not know how to do this.
    cin >> userSelection;
    askToReserve(HList, MList, reservations);
}

int Interface::addNewMember(MemberList& MList)
{

    cout << "Let's add you to the member lsit!" << endl;
    cout << "\tWhat is your first name? " << endl;
    cin >> fName;
    cout << "\tWhat is your last name? " << endl;
    cin >> lName;

    MList.addMember(fName, lName);
    cout << "Welcome to the Club!" << endl;
    cout << "Your member ID number is : " << MList.getLastID() << endl;

    return MList.getLastID();
}

void Interface::viewReservation(HikeList& HList, MemberList& MList, Reservations& Reserve)
{
    int reservationNumber = 0;
    cout << "Enter reservation #: ";
    cin >> reservationNumber;

    Reserve.printReservation(reservationNumber, HList, MList);

}

void Interface::cancelReservation(HikeList& HList, MemberList& MList, Reservations& Reserve)
{
    int res = 0;
    cout << "Enter reservation #: ";
    cin >> res;
    Reserve.printReservation(res, HList, MList);

    char sure;
    cout << "Are you sure you want to cancel this reservation? (y/n)" << endl;
    cin >> sure;

    if (sure == 'y')
    {
        Reserve.cancelReservation(res);
        cout << "Reservation #" << res << "has been canceled." << endl;
    }

}

void Interface::makeReservation(HikeList& HList, MemberList& MList, Reservations& Reserve)
{
    askIfMember(MList);
    cout << "Which hike would you like to reserve (hike name)? ";
    string n;
    cin >> n;

    HList.printByHikeName(n);
    HList.getPrice(n);
    MList.getPoints(MList.getMemberID());
    // cout << "\tDiscounted price using points: " << price << endl;
    // Reserve.printReservation(MList.getMemberID(), HList, MList);
    cout << endl;
    
    Reserve.addReservation(MList.getMemberID(), n);
    cout << "\tBefore processing, please make a note of your reservation number. " << endl;
    cout << "\t Reservation #: " << MList.getMemberID() << endl;
}

/*
Ask user which hike to reserve.
Call function HikeList::printByHikeName() to print the hike chosen by the user.
Call function HikeList::getPrice() and MemberList::getPoints() to print the discounted price, formatted with two decimal places.
Call function Reservations::addReservation() to add the reservation to the list.
*/

void Interface::askToReserve(HikeList& HList, MemberList& MList, Reservations& Reserve)
{
    char c;
    cout << "Would you like to make a reservation? (y/n) ";
    cin >> c;
    cout << endl;
    
    if (c == 'y')
    {
        makeReservation(HList, MList, Reserve);
    }
}

int Interface::askIfMember(MemberList& MList)
{
    cout << "Are you a member? (y/n) ";
    cin >> memberOrNot;
    cout << endl;
    
    cout << "What is your Member ID number? ";
    cin >> memberID;
    cout << endl;
    
    cout << "What is your last name? ";
    cin >> lName;

    if (memberOrNot == 'y')
        MList.printMember(memberID, lName);
    else
        addNewMember(MList);
    return memberID;
}



