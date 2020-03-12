#include <iostream>
#include <fstream>

#include "sort.h"
#include "merge.h"

using namespace std;

int main()
{
	static string FILE_A = "A.txt";
	static string FILE_B = "B.txt";
	static string FILE_C = "printout.txt";

	//If file a and file b is both sorted
	if ( sorted( FILE_A ) && sorted( FILE_B ) )
	{
		cout << "Filerna \"" << FILE_A << "\" och \"" << FILE_B << "\" är sorterade." << endl;

		//Function file_merge
		file_merge( FILE_A, FILE_B, FILE_C );

		cout << "Resultatet är utskrivet till filen \"" << FILE_C << "\"." << endl;	
	}

	return 0;
}