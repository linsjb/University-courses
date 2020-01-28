
//Kan du skriva en funktion som sorterar vektorn my_array,utan att ändra innehållet?!

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;


void display(int *my_array[], int antal);
void get_input(int *my_array[], int antal);

int main()
{
	int antal;
	cout << "Hur många tal tänker du skriva in? " << endl;
	cin >> antal;
	int** my_array;
	int **o_array;
	my_array = new int*[antal];
	o_array = new int *[antal];

	get_input(my_array, antal);
	display(my_array, antal);
	return 0;
}

void get_input(int *my_array[], int antal)
{
	//cout << "Mata in talen:" << endl;
	for (int i = 0; i<antal; i++)
	{
		my_array[i] = new int;
		//cin >> *my_array[i];
		*my_array[i] = rand() % 50;
	}

}

void display(int *my_array[], int antal)
{

	for (int i = 0; i<antal; i++)
		cout << *my_array[i] << setw(4);
	cout << endl;
}
