#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

#include "search.h"
#include "main_menu.h"

using namespace std;

static bool stringContains(string syntax, string text)
{
	//Transform the string to lower case
	transform(syntax.begin(), syntax.end(), syntax.begin(), ::tolower);
	transform(text.begin(), text.end(), text.begin(), ::tolower);

	//return the string
	return (text.find(syntax) != string::npos);
}

//Calculate the index for the vector
vector<int> getIndex(vector<string>& toSearch, string syntax)
{
	vector<int> indexes;
	int index = 0;

	for(string s : toSearch) 
	{	
		if (stringContains (syntax, s))
		{
			indexes.push_back(index);
		}

		index++;
	}

	return indexes;
}

//Print the result from the vector
void printResult(vector<int> indexes, vector<string> search, vector<string> names)
{
	for(int index : indexes)
	{	
		//Print the result
		cout << "Found: " << search[index] << " in contact " << names[index] << endl;
	}
}

//Main search function
void search(vector<string>& nameVector, vector<string>& socialSecNumberVector, vector<string>& addressVector, vector<string>& zipCodeVector, vector<string>& phoneNumberVector, vector<string>& emailVector, vector<string>& noteVector)
{
	cout << " Search after contact" << endl;
	cout << " ---------------------------" << endl;
	string search;
	cout << " Search: ";
	getline(cin, search);

	//Calculated index of the vectors
	vector<int> namnResultat 			= getIndex(nameVector, search);
	vector<int> socialSecNumberResultat = getIndex(socialSecNumberVector, search);
	vector<int> adressResultat 			= getIndex(addressVector, search);
	vector<int> zipcodeResultat 		= getIndex(zipCodeVector, search);
	vector<int> phoneNumberResultat 	= getIndex(phoneNumberVector, search);
	vector<int> emailResultat 			= getIndex(emailVector, search);
	vector<int> noteResultat 			= getIndex(noteVector, search);


	//Search result
	cout << endl << " Search result(s) with the keyword(s) \"" << search << "\"" << endl;
	cout << " ---------------------------" << endl;	

	//Print the result of the search
	printResult(namnResultat, 				nameVector, nameVector);
	printResult(socialSecNumberResultat, 	socialSecNumberVector, nameVector);
	printResult(adressResultat, 			addressVector, nameVector);
	printResult(zipcodeResultat, 			zipCodeVector, nameVector);
	printResult(phoneNumberResultat, 		phoneNumberVector, nameVector);
	printResult(emailResultat, 				emailVector, nameVector);
	printResult(noteResultat, 				noteVector, nameVector);

	//Call the main_menu function
	main_menu(nameVector, socialSecNumberVector, addressVector, zipCodeVector, phoneNumberVector, emailVector, noteVector);	
}