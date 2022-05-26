#include "MemberList.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const string MEMBER_FILE = "members_database.txt";

void createMemberList(ifstream& infile, MemberList& memberInfo)
{
	string firstName;
	string lastName;
	int points = 0;

	while (!infile.eof())
	{
		infile >> firstName >> lastName >> points;
		memberInfo.addMember(firstName, lastName, points);
	}
}

void getMemberListData(MemberList& memberinfo)
{
	ifstream infile;

	infile.open(MEMBER_FILE);

	if (!infile)
	{
		cerr << MEMBER_FILE << " does not exist." << endl;
		exit(1); // terminates program
	}

	createMemberList(infile, memberinfo);

	infile.close();
}
