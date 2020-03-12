#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;


void expand(int *&, int);
void sortera(int*, int);
void fill_list(int *&, int, int);
void print_list(int *, int);



int main()

{


	int *list = new int;
	int tal=0;
	int n=0;
	srand(time(0));

	for (n = 0; n<10; n++)
	{
            tal=rand() % 50;
            fill_list(list, n, tal);
	}

	sortera(list, n);
	print_list(list, n);


	delete[] list;
	list = 0;

	return 0;
}



void fill_list(int *&list, int n, int tal)
{


	if (n)
		expand(list, n);
	list[n] = tal;

}





void print_list(int *list, int n)

{

	for (int i = 0; i < n; ++i)

		cout << list[i] << " ";

	cout << endl;

}


void expand(int *&list, int n)

{

	int *new_array; // Pointer to new, bigger array 
	new_array = new int[n + 1];

	for (int i = 0; i<n; i++)
		new_array[i] = list[i];


	delete[] list;
	list = new_array;

}

void sortera(int *list, int n)

{
	for (int i = 0; i<n; i++)
		for (int j = 0; j<i; j++)
			if ((list[j]>list[i]))
			{
                            int temp = list[j];
                            list[j] = list[i];
                            list[i] = temp;
			}
}
