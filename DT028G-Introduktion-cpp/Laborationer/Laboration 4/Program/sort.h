#include <iostream>
#include <fstream>

using namespace std;

static bool sorted(string filePath)
{
	int currentNumber;
	int previousNumber = 0;

	//File stream
	ifstream readFile;
	readFile.open(filePath);

	readFile >> previousNumber;

	bool sorted = true;

	//While current file has not reach the end
	while(!readFile.eof())
	{
		readFile >> currentNumber;
		
		//If the current number is smaller than the previous readed number
		if (currentNumber < previousNumber)
		{
			cout << "Filen \" " << filePath << "\" är inte sorterad!"  << endl;
			sorted = false;
			break;
		}

		previousNumber = currentNumber;
	}

	readFile.close();

	return sorted;
}