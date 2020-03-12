/*=======================================
* Project: Laboration 2 DT026G
* Filename: main.cpp
* Last changed: 2017-xx-xx
* Version: 1.0
* Author: Linus Sjöbro
* Author mail: lisj1502@student.miun.se
* =====================================*/
#include <iostream>
#include <unistd.h>
#include <new>

using namespace std;

void memory_allocation(string allocationType);
void menu();

int main()
{
  menu();
  return 0;
}

void menu()
{
  cout << "Dynamic allocation of system memory" << endl;
  cout << "1. Allocate memmory in 1 KiB sizes" << endl;
  cout << "2. Allocate memory in 1 GiB sizes" << endl;
  cout << "Choose: ";

  int menuChoice;
  cin >> menuChoice;

  switch(menuChoice)
  {
    case 1:
      memory_allocation("KiB");
      break;

    case 2:
      memory_allocation("GiB");
      break;
  }
}

void memory_allocation(string allocationType)
{

  try
  {
    int KiB = 1024;
    int MiB = (KiB * 1024);
    int GiB = (MiB * 1024);

    int allocationSize = 0;
    int allocationCounter = 0;

    if(allocationType == "KiB")
    {
      allocationSize = KiB;
    }

      else if(allocationType == "GiB")
      {
        allocationSize = GiB;
      }

    while(true)
    {
      //Create a new allocation of int8_t
      int *allocate = new int[allocationSize/4];

      //Print out allocation type and how much memory that got allocated
      cout << "Allocation size: " << allocationType << " - Total memory allocated: " << allocationCounter << " " << allocationType << endl;
      allocationCounter++;
    }
  }// end try

  catch(bad_alloc e)
  {
    //Error message
    cerr << e.what() << endl;
  }


}
