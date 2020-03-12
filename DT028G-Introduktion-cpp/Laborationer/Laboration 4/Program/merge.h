#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
using std::vector;

void file_merge(string FILEPATH_A, string FILEPATH_B, string FILEPATH_C)
{
	int a;
	int b;
	int sum;

	//Vectors
	vector<int> file1;
	vector<int> file2;
	vector<int> printout;

	//File streams
	ifstream readFile1;
	ifstream readFile2;
	ofstream writeFile;

	//Open file streams
	readFile1.open( FILEPATH_A );
	readFile2.open( FILEPATH_B );
	writeFile.open( FILEPATH_C );

	readFile1 >> a;
	readFile2 >> b;

	//While File 1 and file 2 has not reach the end
	while( !readFile1.eof() && !readFile2.eof() )
	{
		//If value in file 1 is smaller than value in file 2
		if( a < b )
		{	
			//Push the value from file 1 to the vector
			printout.push_back(a);

			//Read the next value from file to variable a
			readFile1 >> a;
		}

		else
		{	
			//Push the value from file 2 to the vector
			printout.push_back(b);
			readFile2 >> b;
		}
	}

	//While file 1 has not reach the end
	while( !readFile1.eof() )
	{
		//Push the value from file 1 to the vector
		printout.push_back(a);
		readFile1 >> a;
	}

	//Whiile file 2 has not reach the end
	while( !readFile2.eof() )
	{
		//Push the value from file 2 to the vector
		printout.push_back( b );
		readFile2 >> b;
	}

	//Push all the values from the vector to the file
	for(int i = 0; i < printout.size(); i++)
	{
		writeFile << printout[i] << " ";
	}

	readFile1.close();
	readFile2.close();
	writeFile.close();
}

