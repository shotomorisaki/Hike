#include "Reservations.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const string RESERVATIONS_FILE = "reservations_database.txt";

void createReservation(ifstream& infile, Reservations& reservationList)
{
	int memberID;
	string hikeName;

	while (!infile.eof())
	{
		infile >> memberID >> hikeName;
		reservationList.addReservation(memberID, hikeName);
	}
}

void getReservationData(Reservations& reservationList)
{
	ifstream infile;

	infile.open(RESERVATIONS_FILE);

	if (!infile)
	{
		cerr << RESERVATIONS_FILE << " does not exist." << endl;
		exit(1); // terminates program
	}

	createReservation(infile, reservationList);

	infile.close();
}