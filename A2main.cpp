//-----------------------------------------
// NAME		: junyi lu
// STUDENT NUMBER	: 7879161
// COURSE		: COMP 2150
// INSTRUCTOR	: Mike Domaratzki
// ASSIGNMENT	: assignment 2
// QUESTION	: question 1
//
// REMARKS: What is the purpose of this program?
// CPU and IO burst
//
//-----------------------------------------
#include "Simulation.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		cout << "Usage: " << argv[0] << " <file name>" << endl;
	}
	else
	{
		cout << "Simulation begins...\n";
		Simulation *sim = new Simulation();
		sim->runSimulation(argv[1]);
		cout << "\n...All Processes complete.  Final Summary:\n\n";
		sim->summary();
		cout << "\nEnd of processing.\n";
		return 0;
	}
} // main
