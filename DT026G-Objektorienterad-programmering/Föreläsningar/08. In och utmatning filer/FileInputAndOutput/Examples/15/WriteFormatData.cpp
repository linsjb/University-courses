#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
	ofstream output;

	// Create a file
	output.open("formattedscores.txt");

	// Write two lines
	// Write two lines
	//The length of "John" is 4, and we use setw(6) , that means it will use the first 2 fields of 6 
	//for blanks and the 4 remaining fields will be used for "John".
	output << setw(6) << "John" << setw(2) << "T" << setw(6) << "Smith"
		<< " " << setw(4) << 90 << endl;
	output << setw(6) << "Eric" << setw(2) << "K" << setw(6) << "Jones"
		<< " " << setw(4) << 85 << endl;

	//To show the above, you can use setfill()
	output << setfill('*') << setw(6) << "John" << setfill('*') << setw(2) << "T" << setfill('*') << setw(6) << "Smith"
		<< " " << setfill('*') << setw(4) << 90 << endl;
	output << setfill('*') << setw(6) << "Eric" << setfill('*') << setw(2) << "K" << setfill('*') << setw(6) << "Jones"
		<< " " << setfill('*') << setw(4) << 85 << endl;

	output.close();

	cout << "Done" << endl;
	return 0;
}
