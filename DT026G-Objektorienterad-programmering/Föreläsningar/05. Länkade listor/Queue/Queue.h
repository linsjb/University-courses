//-----------------------------------------------------------
//  Purpose:    Header file for the Queue class.
//-----------------------------------------------------------

#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;
const int QUEUE_SIZE = 100;

//-----------------------------------------------------------
// Define the Queue class interface. 
//-----------------------------------------------------------
class Queue
{
 public:
   // Constructors
   Queue();
   Queue(const Queue & queue);
   ~Queue();

   // Methods 
   bool IsFull();
   bool IsEmpty();
   void Insert(int Number);
   void Remove(int &Number);
   int GetCount();
   void Print();

 private:
   int Data[QUEUE_SIZE];
   int Count;
};
