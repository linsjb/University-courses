//----------------------------------------------
// Purpose: Implement simple List class.
//----------------------------------------------

#include "list.h"


//----------------------------------------------
// Constructor function.
//----------------------------------------------
linked_list::List()
{
   Head = NULL;
}

//----------------------------------------------
// Constructor function.
//----------------------------------------------
linked_list::List(const List & list)
{
   // Create first node
   LNode *copy = new LNode();
   Head = copy;

   // Walk list to copy nodes
   LNode *ptr = list.Head;
   while (ptr != NULL)
   {
      copy->Next = new LNode();
      copy = copy->Next;
      copy->Key = ptr->Key;
      copy->Value = ptr->Value;
      copy->Next = NULL;
      ptr = ptr->Next;
   }

   // Tidy first node
   copy = Head;
   Head = copy->Next;
   delete copy;
}

//----------------------------------------------
// Destructor function.
//----------------------------------------------
linked_list::~List()
{
   // Walk list to delete nodes
   while (Head != NULL)
   {
      LNode *ptr = Head;
      Head = Head->Next;
      delete ptr;
   }
}

//----------------------------------------------
// Insert data into linked list.
//----------------------------------------------
bool linked_list::Insert(string key, int value)
{
   // Walk list to find node
   LNode *ptr = Head;
   while ((ptr != NULL) && (ptr->Key != key))
      ptr = ptr->Next;

   // Update node value if key found
   if (ptr != NULL)
   {
      ptr->Value = value;
      return true;
   }

   // Insert new node if key not found
   ptr = new LNode();
   ptr->Key = key;
   ptr->Value = value;
   ptr->Next = Head;
   Head = ptr;
   return true;
}

//----------------------------------------------
// Search for data in linked list.
//----------------------------------------------
bool linked_list::Search(string key, int &value)
{
   // Walk list to find node
   LNode *ptr = Head;
   while ((ptr != NULL) && (ptr->Key != key))
      ptr = ptr->Next;

   // Return value if key found
   if (ptr != NULL)
   {
      value = ptr->Value;
      return true;
   }
   value = 0;
   return false;
}

//----------------------------------------------
// Delete data from linked list.
//----------------------------------------------
bool linked_list::Delete(string key)
{
   // Walk list to find node
   LNode *ptr = Head;
   while ((ptr != NULL) && (ptr->Key != key))
      ptr = ptr->Next;

   // Swap data with head node
   if (ptr == NULL)
      return false;
   ptr->Key = Head->Key;
   ptr->Value = Head->Value;

   // Delete head node
   ptr = Head;
   Head = Head->Next;
   delete ptr;
   return true;
}

//----------------------------------------------
// Print all records in linked list.
//----------------------------------------------
void linked_list::Print()
{
   LNode *ptr = Head;
   while (ptr != NULL)
   {
      cout << ptr->Value << " " << ptr->Key << endl;
      ptr = ptr->Next;
   }
}

//----------------------------------------------
// Check to see if list is empty.
//----------------------------------------------
bool linked_list::IsEmpty()
{
   return (Head == NULL);
}

//----------------------------------------------
// Count number of nodes in a list.
//----------------------------------------------
int linked_list::Count()
{
   int count = 0;
   LNode *ptr = Head;
   while (ptr != NULL)
   {
      count++;
      ptr = ptr->Next;
   }
   return count;
}

