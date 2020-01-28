#include "linked_list.h"
#include <string>
#include <vector>

using namespace std;

void two_randoms();
void print_list(linked_list selectedList, string listName);
linked_list merge(linked_list list1, linked_list list2);
void task(string task);

int main()
{
  //-----------------------------------------------------------------
  //Task 1
  //-----------------------------------------------------------------
    task("Task 1");

    //Create two list's
    linked_list list1 = linked_list();
    linked_list list2 = linked_list();

    //Create 100 node's in them
    for(int i = 0; i < 100; i++)
    {
      list1.push_back( list1.back() + rand()% 20);
      list2.push_back( list2.back() + rand()% 20);
    }

    print_list(list1, "List 1 with 100 random numbers");
    print_list(list2, "List 2 with 100 random numbers");

  //-----------------------------------------------------------------
  //Task 2
  //-----------------------------------------------------------------
    task("Task 2 and 3");

    //Get the 50th element of list one and two
    int fifElemList1 = list1.at(49);
    int fifElemList2 = list2.at(49);

    int biggestElem = 0;
    string biggestList;

    //Control wich list that got the biggest 50th element
    if(fifElemList1 > fifElemList2)
    {
      biggestElem = fifElemList1;
      biggestList = "list 1";
      list1.remove(49);
    }
      else
      {
        biggestElem = fifElemList2;
        biggestList = "list 2";
        list2.remove(49);
      }

    cout
      << endl
      << "The 50th biggest element is "
      << biggestElem
      << " that belongs to "
      << biggestList
      << endl << endl;

  //-----------------------------------------------------------------
  //Task 4
  //-----------------------------------------------------------------
    //Create a new list
    linked_list list3 = linked_list();

    //Deep copy list 1 to list 3;
    list3 = list1;

  //-----------------------------------------------------------------
  //Task 5
  //-----------------------------------------------------------------
    for(int i = 0; i <= list3.size(); i++)
    {
      list3.pop_back();
      list3.push_front( list3.pop_back());
    }

  //-----------------------------------------------------------------
  //Task 6
  //-----------------------------------------------------------------
    task("Task 6");
    print_list(list3, "List 3");

  //-----------------------------------------------------------------
  //Task 7
  //-----------------------------------------------------------------
    task("Task 7");
    linked_list list4 = merge(list1, list2);
    print_list(list4, "List 4");

  //-----------------------------------------------------------------
  //Task 8
  //-----------------------------------------------------------------
    task("Task 8");
    cout << endl << (list4.sort_check() ? "List 4 is sorted!" : "List 4 is not sorted!") << endl;

  return 0;
}

/*====================================================================================================
* Function type: void
* Function name: print_list
* Description: Print out a given list and a given header
* ==================================================================================================*/
void print_list(linked_list selectedList, string listName)
{
  cout << endl << "--------------------" << endl;
  cout << listName;
  cout << endl << "--------------------" << endl;

  selectedList.print();

  cout << endl << endl;
}

/*====================================================================================================
* Function type: linked_list
* Function name: merge
* Description: Merge two list's together and sorting the new one
* Return type: linked_list
* Return: newList
* ==================================================================================================*/
linked_list merge(linked_list list1, linked_list list2)
{
  //Create a new list
  linked_list newList = linked_list();

  //Copy list 1 to the new list
  newList += list1;

  //Copy list 2 to the new list
  newList += list2;

  //Sort the list
  newList.list_sorting();

  return newList;
}

/*====================================================================================================
* Function type: void
* Function name: task
* Description: Function to print out a header tasks
* ==================================================================================================*/
void task(string task)
{
  cout << "====================================";
  cout << "====================================";
  cout << endl << task << endl;
  cout << "====================================";
  cout << "====================================";
}
