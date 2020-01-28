#include "DoubleLinkedList.h"

int main()
{
	DoubleLinkedList list;
	list.insert(2);
	list.insert(3);
	list.insert(4);
	list.insert(23);
	list.insert(70);
	list.insert(7);
	list.print();
	list.reversePrint();
	cout << endl;
	cout <<"The list length is: "<< list.getLength() << endl;

	DoubleLinkedList list1(list);   //call copy constructor
	list1.print();
	list1.reversePrint();
	cout << endl;
	cout << "The list length is: " << list.getLength() << endl;

	list1.insertStart(345);

	list1.print();
	list1.reversePrint();
	cout << endl;
	cout << "The list length is: " << list1.getLength() << endl;

	DoubleLinkedList list2;
	cout << "Here start assignment operator. " << endl;
	list=list1;   //call assignment operator
	list.print();
	cout << "The list length is: " << list.getLength() << endl;
	return 0;
}