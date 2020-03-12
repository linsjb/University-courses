#include <iostream>
#include <fstream>

using namespace std;


int main()
{
	int rowCounter = 0;
	string fileName = "names.txt";

	string fname, lnamn;
	string reoderdName;
	string adressRow;
	string gender;

	ifstream readFile;
	readFile.open(fileName);

	for( string line; getline(readFile, line); )
	{
		rowCounter ++;

		if ( rowCounter == 1 )
		{
			int space = line.find(" ");
			string fnamn = line.substr(0, space);
			string lnamn = line.substr(space + 1, line.length());
			reoderdName = lnamn + ", " + fnamn;
		}

		if ( rowCounter == 2 )
		{
			int genderIdentifier = stoi(line.substr(8,1));

			
			if ( genderIdentifier % 2 == 0 )
			{
				gender = "[K]";
			}

				else {
					gender = "[M]";
				}
		}

		if (rowCounter == 3)
		{
			adressRow = line;
			cout << reoderdName << " - " << gender << endl << adressRow << endl << endl;

			rowCounter = 0;
		}
	}

	readFile.close();
	return 0;
}