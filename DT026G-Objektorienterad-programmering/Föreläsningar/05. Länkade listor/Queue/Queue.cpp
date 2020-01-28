//-----------------------------------------------------------
//  Purpose:    Implementation of Queue class.
//-----------------------------------------------------------
#include "Queue.h"

//-----------------------------------------------------------
// Constructor function.
//-----------------------------------------------------------
Queue::Queue()
{
   Count = 0;
   for (int i = 0; i < QUEUE_SIZE; i++)
      Data[i] = -1;
}

//-----------------------------------------------------------
// Constructor function.
//-----------------------------------------------------------
Queue::Queue(const Queue & queue)
{
   Count = queue.Count;
   for (int i = 0; i < QUEUE_SIZE; i++)
      Data[i] = queue.Data[i];
}

//-----------------------------------------------------------
// Destructor function.
//-----------------------------------------------------------
Queue::~Queue()
{
}

//-----------------------------------------------------------
// Check if queue is full.
//-----------------------------------------------------------
bool Queue::IsFull()
{
   return (Count >= QUEUE_SIZE);
}

//-----------------------------------------------------------
// Check if queue is empty.
//-----------------------------------------------------------
bool Queue::IsEmpty()
{
   return (Count <= 0);
}

//-----------------------------------------------------------
// Insert data into the queue.
//-----------------------------------------------------------
void Queue::Insert(int item)
{
   // Check if full
   if (IsFull())
      cout << "queue overflow\n";

   // Insert data
   else
      Data[Count++] = item;
}

//-----------------------------------------------------------
// Remove data from the queue.
//-----------------------------------------------------------
void Queue::Remove(int &item)
{
   // Check if empty
   if (IsEmpty())
      cout << "queue underflow\n";

   // Remove data
   else
   {
      item = Data[0];
      Count--;
      for (int i = 0; i < Count; i++)
		Data[i] = Data[i + 1];
		Data[Count] = -1;
   }
}

//-----------------------------------------------------------
// Return the number of elements in queue.
//-----------------------------------------------------------
int Queue::GetCount()
{
   return Count;
}

//-----------------------------------------------------------
// Print all records in queue.
//-----------------------------------------------------------
void Queue::Print()
{
   cout << "count = " << Count << ", data = ";
   for (int i = 0; i < Count; i++)
      cout << Data[i] << " ";
   cout << endl;
}
