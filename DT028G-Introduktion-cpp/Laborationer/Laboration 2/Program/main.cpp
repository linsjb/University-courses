#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
using std::vector;

int main()
{
	//Variables
	double mean;

	int number;
	int numberSum = 0;
	int max = 0;
	int min = 0;

	//Int vector
	vector<int> numberVector;

	//Read file stream
	ifstream readFile;

	//Open filestrem from file "values.txt"
	readFile.open("values.txt");

	//While the reading hasn't reach the end of the file
	while (!readFile.eof())
	{
		readFile >> number;
		numberSum += number;
		numberVector.push_back(number);
	}

	//Calculate the mean value from the "numberSum" with the size of the "numberVector" vector
	mean = (double)numberSum / numberVector.size();

	//The smalest value of the vector
	int maxValue = *max_element(numberVector.begin(), numberVector.end());

	//The largest value of the vector
	int minValue = *min_element(numberVector.begin(), numberVector.end());

	//Printout's
	cout << "Mean: " << mean << endl;
	cout << "Min: " << minValue << endl;
	cout << "Max: " << maxValue << endl;

	//Close filestream
	readFile.close();

	return 0;
}
