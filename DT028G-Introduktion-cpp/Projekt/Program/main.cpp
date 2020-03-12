#include <vector>
#include <string>

#include "file_handling.h"
#include "main_menu.h"

int main()
{
	//Section vectors
	vector<string> nameVector;
	vector<string> socialSecNumber;
	vector<string> addressVector;
	vector<string> zipCodeVector;
	vector<string> phoneNumberVector;
	vector<string> emailVector;
	vector<string> noteVector;

	//Read the file
	read_file(nameVector, socialSecNumber, addressVector, zipCodeVector, phoneNumberVector, emailVector, noteVector);

	//Display the main menu 
	main_menu(nameVector, socialSecNumber, addressVector, zipCodeVector, phoneNumberVector, emailVector, noteVector);

	return 0;
}