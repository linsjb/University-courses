/*
A Queue is an ADT that has a FIFO characteristic.
which means data is inserted at one end and removed from the other end. 
Queues are used to provide "fair service" to people in 
banks, buying tickets, etc.
Queues are also used in many computer systems to 
provide "fair services".
o printer queues
o operating system scheduling queues
o communication buffers
o event simulation 
The Queue ADT normally has the following operations.
create - make a new queue
destroy - delete all data on queue
insert - put data at the end of the queue
remove - get data from the front of the queue
full - check for more room in the queue
empty - checks queue for any data available
•Insert and Remove are also called Enqueue and Dequeue

*/

//-----------------------------------------------------------
// Main program.
//-----------------------------------------------------------
#include "Queue.h"

int main()
{
   Queue q;
   q.Insert(3);
   q.Insert(1);
   q.Insert(4);
   q.Print();
   q.Insert(1);
   q.Insert(5);
   q.Insert(9);
   q.Print();

   int num;
   q.Remove(num);
   q.Remove(num);
   q.Print();
   q.Remove(num);
   q.Remove(num);
   q.Print();
   q.Remove(num);
   q.Remove(num);
   q.Print();
   return 0;
}

