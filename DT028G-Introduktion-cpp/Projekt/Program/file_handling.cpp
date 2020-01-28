#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "file_handling.h"

using namespace std;

void read_file(vector<string>& nameVector, vector<string>& socialSecNumberVector, vector<string>& addressVector, vector<string>& zipCodeVector, vector<string>& phoneNumberVector, vector<string>& emailVector, vector<string>& noteVector)
{
	//File stream
	ifstream readFile("contacts.txt");

	if(readFile.fail())
	{
		cout << " ---------------------------" << endl;
		cout << " It seems like the file is missing or something went wrong" << endl;
		cout << " Create a new contact to automatically create a new file" << endl;
	}


	//Open file
	

	//Variable that count wich row the pointer stands in
	int rowCounter = 0;
	
	//Loop through lines in file and put  the current readed line in string line
	for( string line; getline( readFile, line ); )
	{
		switch ( rowCounter )
		{
			//Insert name to nameVector
			case 0:
			{
				nameVector.push_back(line);
				rowCounter++;
				break;
			}

			//Insert birth date to birthDateVector
			case 1:
			{
				socialSecNumberVector.push_back(line);
				rowCounter++;
				break;
			}

			//Insert address to addressVector 
			case 2:
			{
				addressVector.push_back(line);
				rowCounter++;
				break;
			}

			//Insert zip code to zipCodeVector
			case 3:
			{
				zipCodeVector.push_back(line);
				rowCounter++;
				break;
			}

			//Insert phone number to phoneNumberVector
			case 4:
			{
				phoneNumberVector.push_back(line);
				rowCounter++;
				break;
			}

			//Insert email to emailVector
			case 5:
			{
				emailVector.push_back(line);
				rowCounter++;
				break;
			}

			//Insert note to noteVector
			case 6:
			{
				noteVector.push_back(line);

				//Reset's the counter so the input to the vectors "restart".
				rowCounter = 0;
				break;
			}

		}//Switch
		
	}//For-loop

	//Close file stream
	readFile.close();
}

void write_file(vector<string>& nameVector, vector<string>& socialSecNumberVector, vector<string>& addressVector, vector<string>& zipCodeVector, vector<string>& phoneNumberVector, vector<string>& emailVector, vector<string>& noteVector)
{
	ofstream writeFile;
	writeFile.open("contacts.txt");

	for(int i = 0; i<nameVector.size(); i++)
	{
		writeFile << nameVector[i] << endl;
		writeFile << socialSecNumberVector[i] << endl;
		writeFile << addressVector[i] << endl;
		writeFile << zipCodeVector[i] << endl;
		writeFile << phoneNumberVector[i] << endl;
		writeFile << emailVector[i] << endl;
		writeFile << noteVector[i] << endl;
	}
}
