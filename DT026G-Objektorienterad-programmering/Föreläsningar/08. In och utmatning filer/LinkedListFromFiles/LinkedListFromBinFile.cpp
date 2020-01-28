/*

 * LinkedListFromBinFile.cpp
 *
 *  Created on: 8 apr. 2016
 *      Author: naymal
*/


#include <iostream>
#include <cassert>
#include <string>
#include <fstream>
using namespace std;

const int NAME_SIZE = 51, ADDR_SIZE = 51, PHONE_SIZE = 14;
// Declare a structure for the record.
struct Info
{
	char name[NAME_SIZE];
	int age;
	char address1[ADDR_SIZE];
	char address2[ADDR_SIZE];
	char phone[PHONE_SIZE];
};

class Node {
public:
    Info person;
    Node* pnext;
};

class List {
public:
    Node* first;
    int count;
};
//read the content in a file and put it in the list
void readContent(fstream &file,List*);
void showRec(Info record);
// add a new node at the beginning of a list
void insert_front(List* list, Info person);
void print_list(List* list);
void delete_list(List* list);


int main()
{
    List* mylist = new List;
    mylist->count = 0;

    fstream people;	// File stream object

    	// Open the file for input in binary mode.
    people.open("people.dat", ios::in | ios::binary);

    	// Test for errors.
    if (!people)
    {
    	cout << "Error opening file. Program aborting.\n";
    	return 0;
    	}


    cout << "empty list: ";
    print_list(mylist);

    cout << "read from file and insert front: ";
    readContent(people,mylist);

    //insert_front(mylist, "Nayeb");
    print_list(mylist);

    cout << "delete list, then print: ";
    delete_list(mylist);
    print_list(mylist);

    return 0;
}

void readContent(fstream &file,List* list)
{
	Info person;
   while (file.read(reinterpret_cast<char *>(&person), sizeof(person)))
   {
      insert_front(list,person);
   }
}


// add a new node at the beginning of a list
void insert_front(List* list, Info person)
{
    Node* n = new Node;
    n->person = person;
    n->pnext = list->first;
    list->first = n;
    list->count++;
}


// print all the values
void print_list(List* list)
{

    cout << "{";
    Node* n = list->first;
    for(int i = 0; i < list->count; i++)
    {
    	showRec(n->person);
        if(i < (list->count - 1))
        {
            cout << ", ";
        }
        n = n->pnext;
    }
    cout << "}" << endl;
}
 // free up all the memory used by the list
void delete_list(List* list)
{
    Node* n = list->first;
    Node* n2;
    for(int i = 0; i < list->count; i++)
    {
        n2 = n;
        n = n->pnext;
        delete n2;
    }
    list->count = 0;
}
void showRec(Info record)
{
	cout << "Name: ";
	cout << record.name << endl;
	cout << "Age: ";
	cout << record.age << endl;
	cout << "Address line 1: ";
	cout << record.address1 << endl;
	cout << "Address line 2: ";
	cout << record.address2 << endl;
	cout << "Phone: ";
	cout << record.phone << endl;
}


