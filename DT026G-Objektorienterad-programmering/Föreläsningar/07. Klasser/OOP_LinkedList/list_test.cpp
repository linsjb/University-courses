/*
 * list_test.cpp
 *
 *  Created on: 27 apr. 2016
 *      Author: naymal
 */

#include "list.h"
//-----------------------------------------------------------
// Testing function
//-----------------------------------------------------------
int main()
{
   const int size = 10;
   string str[size] = {
      "this", "is", "a", "simple", "test",
      "of", "my", "linked", "list", "class"
   };

   srand(time(0));

   List list;

   // Test insert method
   for (int count = 0; count < size; count++)
   {
      int num = rand() % size;
      if (list.Insert(str[num], num))
	 cout << "Insert " << str[num] << " " << num << " ok\n";
      else
	 cout << "Insert " << str[num] << " " << num << " failed\n";
   }
   list.Print();

   // Test copy
   cout << "Copy\n";
   List copy(list);
   copy.Print();

   // Test search method
   for (int count = 0; count < size; count++)
   {
      int num = rand() % size;
      if (list.Search(str[num], num))
	 cout << "Search " << str[num] << " found\n";
      else
	 cout << "Search " << str[num] << " not found\n";
   }

   // Test delete method
   for (int count = 0; count < size; count++)
   {
      int num = rand() % size;
      if (list.Delete(str[num]))
	 cout << "Delete " << str[num] << " ok\n";
      else
	 cout << "Delete " << str[num] << " failed\n";
   }
   list.Print();
}




