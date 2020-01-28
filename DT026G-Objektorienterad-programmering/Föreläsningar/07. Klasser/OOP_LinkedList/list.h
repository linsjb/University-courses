//-----------------------------------------------------------
//  Purpose:    Header file for the List class.
//-----------------------------------------------------------
#ifndef LIST_H
#define LIST_H

#include <ctime>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//-----------------------------------------------------------
// List data node definition
//-----------------------------------------------------------
class LNode
{
 public:
   string Key;
   int Value;
   LNode *Next;
};

//-----------------------------------------------------------
// Define the List class interface
//-----------------------------------------------------------
class List
{
 public:
   // Constructors
   List();
   List(const List & list);
  ~List();

   // Methods
   bool Insert(string key, int value);
   bool Search(string key, int &value);
   bool Delete(string key);
   void Print();
   bool IsEmpty();
   int Count();

 private:
     LNode * Head;
};

#endif
