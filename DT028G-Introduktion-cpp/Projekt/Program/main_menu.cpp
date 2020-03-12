#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include "main_menu.h"

using namespace std;

void main_menu(vector<string>& nameVector, vector<string>& socialSecNumberVector, vector<string>& addressVector, vector<string>& zipCodeVector, vector<string>& phoneNumberVector, vector<string>& emailVector, vector<string>& noteVector)
{
	char choosenOption;

	//Option variables
	const string option_1 = "1: Print contacts";
	const string option_2 = "2: Add new contact";
	const string option_3 = "3: Change contact";
	const string option_4 = "4: Search";

	//Bool to control if the main menu is going to be printed when the contact list is printed
	bool printMainMenu;
	bool printId;

	//The length of the first option
	int opt1Length = option_1.length();
	
	string option_6 = "0: Exit";


	cout << endl << " | ------ Main menu ------ |" << endl;
	cout << " | ======================= |" << endl;


	//Option 1
	cout << " |" << setw(opt1Length + 9) << setfill(' ') << "|" << endl;
	cout << " | " << option_1 << setw(8) << setfill(' ') << "|" << endl;

	//Option 2
	cout << " |" << setw(opt1Length + 9) << setfill(' ') << "|" << endl;
	cout << " | " << option_2 << setw(7) << setfill(' ') << "|" << endl;

	//Option 3
	cout << " |" << setw(opt1Length + 9) << setfill(' ') << "|" << endl;
	cout << " | " << option_3 << setw(8) << setfill(' ') << "|" << endl;

	//Option 4
	cout << " |" << setw(opt1Length + 9) << setfill(' ') << "|" << endl;
	cout << " | " << option_4 << setw(16) << setfill(' ') << "|" << endl;


	cout << " | ======================= |" << endl;


	MENU_OPTION:
	cout << endl << " Choose option: ";
	cin >> choosenOption;
	cin.ignore();

	
	//Switch that call the right function depending on the choice
	switch (choosenOption)
	{
		case '1':
			printMainMenu = true;
			printId = false;
			print_contacts(nameVector, socialSecNumberVector, addressVector, zipCodeVector, phoneNumberVector, emailVector, noteVector, printMainMenu, printId);
			break;

		case '2':
			add_contacts(nameVector, socialSecNumberVector, addressVector, zipCodeVector, phoneNumberVector, emailVector, noteVector);
			break;

		case '3':
			change_contact_menu(nameVector, socialSecNumberVector, addressVector, zipCodeVector, phoneNumberVector, emailVector, noteVector);
			break;

		case '4':
			search(nameVector, socialSecNumberVector, addressVector, zipCodeVector, phoneNumberVector, emailVector, noteVector);
			break;

		default:
			cout << endl << " This option does not exist in this menu!";
			goto MENU_OPTION;
			break;
	}
}
