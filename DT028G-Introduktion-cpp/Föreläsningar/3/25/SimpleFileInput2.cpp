#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// this program contains an error

int main()
{
	ifstream ifs("data.txt");
	string line;
	getline(ifs, line);
	cout << "[ " << line << " ]" << endl;
	
	return 0;
}
