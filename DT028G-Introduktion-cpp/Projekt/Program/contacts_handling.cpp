#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>

#include "contacts_handling.h"
#include "main_menu.h"

using namespace std;

//Menu choice
char menuChoice;

//Line devider
const string devider = "------------------------";
const string wrongSelection = "This option does not exist in this menu!";

string userInput(string userInput)
{
	string line;

	while (line.empty())
	{
		if(!userInput.empty())
		{
			cout << userInput;
		}

		getline(cin, line);
	}

	return line;
}

void print_contacts(vector<string>& nameVector, vector<string>& socialSecNumberVector, vector<string>& addressVector, vector<string>& zipCodeVector, vector<string>& phoneNumberVector, vector<string>& emailVector, vector<string>& noteVector, bool printMainMenu, bool printId)
{
	//If the name vector is empty
	//Display error message and menu if true
	if ( nameVector.empty() )
	{
		cout << "It seems like there is no contacts in the file!" << endl;
		cout << devider << endl;
		cout << "1. Add contact" << endl << "2. Return to main menu" << endl;
		cout << devider << endl;

		NO_FILE_MENU:
		cout << "Choose option: ";
		cin >> menuChoice;
		cin.ignore();

		switch( menuChoice )
		{	
			//Load add new contact function
			case '1':
				add_contacts(nameVector, socialSecNumberVector, addressVector, zipCodeVector, phoneNumberVector, emailVector, noteVector);
				break;

			//Load main menu function
			case '2':
				main_menu(nameVector, socialSecNumberVector, addressVector, zipCodeVector, phoneNumberVector, emailVector, noteVector);
				break;

			default:
				cout << wrongSelection << endl;
				goto NO_FILE_MENU;
				break;

		} //Switch

	} //if

		//If name vector is not empty
		else
		{	
			//Vector elements length
			//Initalize with the width of the first elements in the vectors
			int idWidth					= 4;
			int nameWidth 				= nameVector[0].size();
			int addressWidth 			= addressVector[0].size();
			int zipCodeWidth 			= zipCodeVector[0].size();
			int phoneNumberWidth 		= phoneNumberVector[0].size();
			int emailWidth 				= emailVector[0].size();
			int noteWidth 				= noteVector[0].size();

			int tableWidth;
			
			const int socialSecNumberWidth	= 18;

			//Column width for each row when vector being printed
			int idColumnWidth 				= idWidth;
			int nameColumnWidth 			= 0;
			int socialSecNumberColumnWidth 	= 9;
			int addressColumnWidth 			= 0;
			int zipCodeColumnWidth 			= 0;
			int phoneNumberColumnWidth 		= 0;
			int emailColumnWidth 			= 0;
			int noteColumnWidth 			= 0;

			//Loop through every element in the name vector to control wich of the element that is the biggest one
			//Why we loop through only one vector here is because if a name element exist, the index exist in the other vectors
			for(int z = 0; z < nameVector.size(); z++)
			{
				//If the current index of the nameVector is smaller than the nameWidth, set the nameWidth as the current index of the vector
				if (nameVector[z].size() > nameWidth)
					nameWidth = nameVector[z].size();

				//If the current index of the addressVector is smaller than the addressWidth, set the addressWidth as the current index of the vector
				if (addressVector[z].size() > addressWidth)
					addressWidth = addressVector[z].size();

				//If the current index of the zipCodeVector is smaller than the zipCodeWidth, set the zipCodeWidth as the current index of the vector
				if (zipCodeVector[z].size() > zipCodeWidth)
					zipCodeWidth = zipCodeVector[z].size();

					//Else put the zipCodeWidth to the size of the table column header
					else
						zipCodeWidth = 10;

				//If the current index of the phoneNumberVector is smaller than the phoneNumberWidth, set the phoneNumberWidth as the current index of the vector
				if (phoneNumberVector[z].size() > phoneNumberWidth)
					phoneNumberWidth = phoneNumberVector[z].size();

					//Else put the zipCodeWidth to the size of the table column header
					else
						phoneNumberWidth = 13;

				//If the current index of the emailVector is smaller than the phoneNumbemailWidtherWidth, set the emailWidth as the current index of the vector
				if (emailVector[z].size() > emailWidth)
					emailWidth = emailVector[z].size();

				//If the current index of the noteVector is smaller than the noteWidth, set the noteWidth as the current index of the vector
				if (noteVector[z].size() > noteWidth)
					noteWidth = noteVector[z].size();

					//Else put the noteWidth to the size of the table column header
					else
						noteWidth = 12;
			} //for

			
			//If the bool printId is true, calculate the idWidth in the tableWidth
			if ( printId )
				//The width of the biggest vectors
				//To define the width of the table
				tableWidth = idWidth + nameWidth + addressWidth + zipCodeWidth + phoneNumberWidth + emailWidth + noteWidth + socialSecNumberWidth + 10;

				else
					tableWidth = nameWidth + addressWidth + zipCodeWidth + phoneNumberWidth + emailWidth + noteWidth + socialSecNumberWidth + 8;

			//Different separators for the table
			const char blankSeparator 		= ' ';
			const char singleSeparator 		= '-';
			const char doubleSeparator 		= '=';

			//Table HEADER printout

			//Vertical devider
			cout << endl << " |";

			//Table horizontal top devider
			cout << setw(tableWidth) << setfill(doubleSeparator) << "|" << endl << " |";

			//If the bool printId it true, print the ID column header
			if ( printId )
				// Table header ID column
				cout << setw(idWidth) << setfill(blankSeparator) << "ID" << "|";

			// Table header name column
			cout << setw(nameWidth) << setfill(blankSeparator) << "Name" << "|";

			//Table header birth date column
			cout << setw(socialSecNumberWidth) << setfill(blankSeparator) << "Social sec. number" << "|";
			
			//Table header address column
			cout << setw(addressWidth) << setfill(blankSeparator) << "Address" << "|";
			
			//Table header zip code column
			cout << setw(zipCodeWidth) << setfill(blankSeparator) << "Zip code" << "|";
			
			//Table header phone number column
			cout << setw(phoneNumberWidth) << setfill(blankSeparator) << "Phone number" << "|";
			
			//Table header email column
			cout << setw(emailWidth) << setfill(blankSeparator) << "Email" << "|";
			
			//Table header note column
			cout << setw(noteWidth) << setfill(blankSeparator) << "Notes" << "|";
			
			//Table header column
			cout << endl << " |";
			
			//Table header horizontal splitter
			cout << setw(tableWidth) << setfill(singleSeparator) << "|";

			//column width variables
			
			//Loop through the file (with the name vector as the lead vector) to print out the lines to the table
			for(int a = 0; a < nameVector.size(); a++)
			{
				//If the current index of nameVector is smaller than the nameWidth.
				//Reduce the nameColumnWidth with the width of the current index
				if (nameVector[a].size() > nameWidth)
					nameColumnWidth = 30;

					//If the current index of nameVector is equal to the nameWidth
					//Put the column width to zero, we do not need any spaces after the string
					else if (nameVector[a].size() == nameWidth )
						nameColumnWidth = 0;

				if (socialSecNumberVector[a].size() < socialSecNumberWidth)
					socialSecNumberColumnWidth = socialSecNumberWidth - socialSecNumberVector[a].size() + 1;

				//If the current index of addressVector is smaller than the addressWidth.
				//Reduce the addressColumnWidth with the width of the current index
				if(addressVector[a].size() < addressWidth)
					addressColumnWidth = addressWidth - addressVector[a].size() + 1;

					//If the current index of addressVector is equal to the addressWidth
					//Put the column width to zero, we do not need any spaces after the string
					else if (addressVector[a].size() == addressWidth)
						addressColumnWidth = 0;

				//If the current index of zipCodeVector if smaller or equal to 10 (the size of the column header)
				//Put the column width to 11 minus the size of the currend vector index
				if(zipCodeVector[a].size() <= 8)
					zipCodeColumnWidth = zipCodeWidth - zipCodeVector[a].size() + 1;


					else if(zipCodeVector[a].size() > 8)
						zipCodeColumnWidth = zipCodeWidth - zipCodeVector[a].size() + 1;

				//If the current index of phoneNumberVector if smaller or equal to 13 (the size of the column header)
				//Reduce the phoneNumberColumnWidth with the width of the current index
				if(phoneNumberVector[a].size() <= 13)
					phoneNumberColumnWidth = phoneNumberWidth - phoneNumberVector[a].size() + 1;

					//If the index of the phoneNumberVector is greater than 13 (The size of the column header)
					//Reduce the phoneNumberColumnWidth with the width of the current index
					else if(phoneNumberVector[a].size() > 13)
						phoneNumberColumnWidth = phoneNumberWidth - phoneNumberVector[a].size() + 1;

				//If the current index of emailVector is smaller than the emailWidth.
				//Reduce the emailColumnWidth with the width of the current index
				if(emailVector[a].size() < emailWidth)
					emailColumnWidth = emailWidth - emailVector[a].size() + 1;


				//If the current index of noteVector is smaller than the noteWidth.
				//Reduce the noteColumnWidth with the width of the current index
				if(noteVector[a].size() < noteWidth)
					noteColumnWidth = noteWidth - noteVector[a].size() + 1;

					//If the current index of noteVector is equal to the noteWidth
					//Put the column width to zero, we do not need any spaces after the string
					else if (noteVector[a].size() == noteWidth )
						noteColumnWidth = 0;

					//If the index of the noteVector is greater than 12 (The size of the column header)
					//Reduce the noteColumnWidth with the width of the current index
					else if(noteVector[a].size() > 12)
						noteColumnWidth = noteWidth - noteVector[a].size() + 1;

				//Table CONTENT printout
				cout << endl << " |";

				//Print out of each of the vectors lines

				if ( printId )
				{
					//If the bool printId is true, print the ID column
					cout << setw(idColumnWidth) << setfill(blankSeparator) << a + 1 << "|";
				}

				cout << setw(nameColumnWidth) << setfill(blankSeparator) << nameVector[a] << "|";
				cout << setw(socialSecNumberColumnWidth) << setfill(blankSeparator) << socialSecNumberVector[a] << "|";
				cout << setw(addressColumnWidth) << setfill(blankSeparator) << addressVector[a] << "|";
				cout << setw(zipCodeColumnWidth) << setfill(blankSeparator) << zipCodeVector[a] << "|";
				cout << setw(phoneNumberColumnWidth) << setfill(blankSeparator) << phoneNumberVector[a] << "|";
				cout << setw(emailColumnWidth) << setfill(blankSeparator) << emailVector[a] << "|";
				cout << setw(noteColumnWidth) << setfill(blankSeparator) << noteVector[a] << "|";

			} //for
				cout << endl << " |";

				//Table horizontal bottom devider
				cout << setw(tableWidth) << setfill(doubleSeparator) << "|" << endl;

				//If bool printMainMenu is true, call the main_menu function after the contacts has been printen out
				if (printMainMenu == true)
					//Call the main menu function
					main_menu(nameVector, socialSecNumberVector, addressVector, zipCodeVector, phoneNumberVector, emailVector, noteVector);

		} //else
}

void add_contacts(vector<string>& nameVector, vector<string>& socialSecNumberVector, vector<string>& addressVector, vector<string>& zipCodeVector, vector<string>& phoneNumberVector, vector<string>& emailVector, vector<string>& noteVector)
{
	//Add contact HEADER
	cout << endl << "Add new contacts" << endl << "x: return to menu" << endl << endl;


	//Bool to control if another contact is going to be added
	bool addMore = true;

	//Bool to control if the main menu is going to be printed after the contacts has been printed out
	bool printMainMenu;

	//Integer to calc. the number of added contacts befor saving
	int numOfAddCont = 0;

	//Loop that runs as long as the statement is true
	//This is to enable multiply new contact inputs
	while ( addMore )
	{
		cout << devider << endl;
		
		//Add name
		ADD_NAME:
		string addNewName = userInput("Name: ");

		if ( addNewName == "x" || addNewName == "X" )
		{
			main_menu(nameVector, socialSecNumberVector, addressVector, zipCodeVector, phoneNumberVector, emailVector, noteVector);
		}
			//If the field is empty
			else if ( addNewName == "" )
			{
				cout << "Name is required!" << endl;
				goto ADD_NAME;
			}

		//Push string to last index of name vector
		nameVector.push_back(addNewName);

		//Devider
		cout << devider << endl;
	
		//Add birth date
		ADD_socialSecNumber:
		string addNewsocialSecNumber = userInput("Day of birth: ");

		//Cancel add contact and return to main menu
		if ( addNewsocialSecNumber == "x" || addNewsocialSecNumber == "X" )
		{
			main_menu(nameVector, socialSecNumberVector, addressVector, zipCodeVector, phoneNumberVector, emailVector, noteVector);
		}

		//If the birth date is under 10 characters, return to the beginning of the add socialSecNumber input
		else if ( addNewsocialSecNumber.length() < 10 )
		{
			cout << "To short!" << endl << endl;
			goto ADD_socialSecNumber;
		}

		//If a 12 digit birth date is enterd, remove the two first digits, return to the beginning of the add socialSecNumber input
		else if ( addNewsocialSecNumber.length() == 12)
		{
			addNewsocialSecNumber.erase(0,2);
		}

		else if ( addNewsocialSecNumber.length() == 11 )
		{
			cout << "To short!" << endl << "10 or 12 numbers" << endl;
			goto ADD_socialSecNumber;
 		}

		//If the birth date if over 12 characters, return to the beginning of the add socialSecNumber input
		else if ( addNewsocialSecNumber.length() > 12 )
		{
			cout << "To long!" << endl << "10 or 12 numbers" << endl;
			goto ADD_socialSecNumber;

		}

		//Push string to last index of birth date vector 
		socialSecNumberVector.push_back(addNewsocialSecNumber);

		cout << devider << endl;
	
		//Add address
		string addNewAddress = userInput("Address: ");

		if ( addNewAddress == "x" || addNewAddress == "X" )
		{
			main_menu(nameVector, socialSecNumberVector, addressVector, zipCodeVector, phoneNumberVector, emailVector, noteVector);
		}

		//Push string to last index of address vector 
		addressVector.push_back(addNewAddress);

		cout << devider << endl;
	
		//Add zip code
		string addNewZipCode = userInput("Zip code: ");

		if ( addNewZipCode == "x" || addNewZipCode == "X" )
		{
			main_menu(nameVector, socialSecNumberVector, addressVector, zipCodeVector, phoneNumberVector, emailVector, noteVector);
		}

		//Push string to last index of zip code vector 
		zipCodeVector.push_back(addNewZipCode);

		cout << devider << endl;
	
		//Add phone number
		string addNewPhoneNumber = userInput("Phone number: ");

		if ( addNewPhoneNumber == "x" || addNewPhoneNumber == "X" )
		{
			main_menu(nameVector, socialSecNumberVector, addressVector, zipCodeVector, phoneNumberVector, emailVector, noteVector);
		}

		//Push string to last index of phone number vector 
		phoneNumberVector.push_back(addNewPhoneNumber);

		cout << devider << endl;
		
		//Add email
		ADD_EMAIL:
		string addNewEmail = userInput("Email: ");

		if ( addNewEmail == "x" || addNewEmail == "X" )
		{
			main_menu(nameVector, socialSecNumberVector, addressVector, zipCodeVector, phoneNumberVector, emailVector, noteVector);
		}

		//Control if the char @ and . exists is the add new email string
		if ( addNewEmail.find("@") == string::npos || addNewEmail.find(".") == string::npos)
		{
			cout << "Not a valid email address!" << endl << endl;
			goto ADD_EMAIL;
		}

		//Push string to last index of email vector 
		emailVector.push_back(addNewEmail);

		//devider
		cout << devider << endl;
		
		//Add note
		string addNewNote = userInput("Note: ");

		if ( addNewNote == "x" || addNewNote == "X" )
		{
			main_menu(nameVector, socialSecNumberVector, addressVector, zipCodeVector, phoneNumberVector, emailVector, noteVector);
		}

		//Push string to last index of note vector 
		noteVector.push_back(addNewNote);

		//devider
		cout << devider << endl;
	
		//Success print
		cout << endl << "Contact added!" << endl;

		//Add one to the variable
		//To control how many contacs that has been added to the vectors.
		numOfAddCont ++;

		//Reloop point, if the default state of the addControl switch kicks in, return to this point
		RELOOP_CHOICE:

		//Add another contact prompt
		cout << endl << "Add another contact? (y/n): ";
		cin >> menuChoice;
		cin.ignore();

		//Control what state the variable "addControl" has after input
		switch( menuChoice )
		{
			case 'y':
			case 'Y':
				break;

			case 'n':
			case 'N':
				cout << devider << endl;
				cout << numOfAddCont << " contact's added sucessfully" << endl;
				
				//This close the while loop and the input is done
				addMore = false;
				break;

			//If the wrong character is written
			default:
				cout << endl << wrongSelection;
				goto RELOOP_CHOICE;
				break;
		} //switch
	} //while

	//Save changes "section"
	SAVE_CHANGES:

	cout << "Do you want to save the changes before exit?: (y/n): ";
	cin >> menuChoice;

	//Control what state the variable "menuChoice" has after input
	switch ( menuChoice )
	{
		case 'y':
		case 'Y':
			cout << endl << "Changes saved!" << endl << devider << endl;

			//Call the write_file function
			write_file(nameVector, socialSecNumberVector, addressVector, zipCodeVector, phoneNumberVector, emailVector, noteVector);

			//Call the main_menu function
			main_menu(nameVector, socialSecNumberVector, addressVector, zipCodeVector, phoneNumberVector, emailVector, noteVector);
			break;

		case 'n':
		case 'N':
			//Erase the n last elements in vectors
			nameVector.erase(nameVector.end(), nameVector.end()+numOfAddCont);

			cout << endl << "Changes not saved!" << endl << "Previously input contacts erased" << endl << devider << endl;

			//Call the main_menu function
			main_menu(nameVector, socialSecNumberVector, addressVector, zipCodeVector, phoneNumberVector, emailVector, noteVector);
			
			break;

		default:
			//If the wrong character is written, return to the section SAVE_CHANGES
			cout << endl << wrongSelection << endl;
			goto SAVE_CHANGES;

	} //switch
}

void delete_contact(vector<string>& nameVector, vector<string>& socialSecNumberVector, vector<string>& addressVector, vector<string>& zipCodeVector, vector<string>& phoneNumberVector, vector<string>& emailVector, vector<string>& noteVector, int choosenContact)
{	
	cout << devider << endl;

	DELETE_CONFIRMATION:
	cout << "Are your sure that you want to delete this contact? (y/n): ";
	cin >> menuChoice;

	switch ( menuChoice )
	{
		case 'y':
		case 'Y':
			//Erase the given index of each vector
			nameVector.erase(nameVector.begin() + choosenContact - 1);


			//Call the write_file function to save the changes
			//write_file(nameVector, socialSecNumberVector, addressVector, zipCodeVector, phoneNumberVector, emailVector, noteVector);

			cout << endl << devider << endl;
			cout << "Contact succesfully deleted!" << endl;

		case 'n':
		case 'N':
			change_contact_menu(nameVector, socialSecNumberVector, addressVector, zipCodeVector, phoneNumberVector, emailVector, noteVector);

		default:
			cout << wrongSelection << endl;
			goto DELETE_CONFIRMATION;

	}
}

void change_contact_menu(vector<string>& nameVector, vector<string>& socialSecNumberVector, vector<string>& addressVector, vector<string>& zipCodeVector, vector<string>& phoneNumberVector, vector<string>& emailVector, vector<string>& noteVector)
{
	//Variable for contact choice
	int contactChoice;

	//Bool to control if the main menu is going to be printed directly after the contacts table
	bool printMainMenu = false;

	//Bool that control if the ID column in the table is going to be printed
	bool printId = true;

	//Header printout
	cout << endl << devider << endl;
	cout << " Change Contact" << endl;

	//Call the print_contacts function
	print_contacts(nameVector, socialSecNumberVector, addressVector, zipCodeVector, phoneNumberVector, emailVector, noteVector, printMainMenu, printId);

	cout << endl << " 0: Return to main menu" << endl;
	cout << " Choose contact via contact ID" << endl << endl;

	CONTACT_CHOICE:
	cout << " Choose contact: ";
	cin >> contactChoice;

	//If zero is choosen, call the main_menu function
	if ( contactChoice == 0 )
		//Call the main_menu function
		main_menu(nameVector, socialSecNumberVector, addressVector, zipCodeVector, phoneNumberVector, emailVector, noteVector);

	//Printout after the contact i choosen
	cout << endl << devider << endl;
	cout << "Contact " << contactChoice << " choosen" << endl;
	cout << "0: Return to main menu" << endl << endl;
	cout << "1: Deleet contact" << endl << endl; 

	CHOOSE_OPTION:
	cout << "Choose option: ";
	cin >> menuChoice;
	cin.ignore();

	switch(menuChoice)
	{
		case '0':
			//Call the main_menu function
			main_menu(nameVector, socialSecNumberVector, addressVector, zipCodeVector, phoneNumberVector, emailVector, noteVector);
			break;

		case '1':
			//Call the delete_contact function
			delete_contact(nameVector, socialSecNumberVector, addressVector, zipCodeVector, phoneNumberVector, emailVector, noteVector, contactChoice);
			break;

		default:
			goto CHOOSE_OPTION;
	}
}