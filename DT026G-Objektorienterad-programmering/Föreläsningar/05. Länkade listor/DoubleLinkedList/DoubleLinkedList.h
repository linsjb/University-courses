#ifndef _DoubleLinkedList_H_
#define _DoubleLinkedList_H_

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	friend class DoubleLinkedList;
	int getData() { return data; }
	Node(int value) :data(value), next(nullptr), prev(nullptr){ }
private:
	int data;
	Node *next;  // pointer to node after me
	Node *prev;  // pointer to node before me
};

class DoubleLinkedList {

private:
	int length;
	Node *first;
	Node *last;
public:
	
	DoubleLinkedList();
	DoubleLinkedList(DoubleLinkedList const & copy);
	DoubleLinkedList & operator = (const DoubleLinkedList &copy);
    // This operator also needs to use node attributes to walk down a list being printed
	//Not implemented yet!
    friend ostream& operator <<(ostream &destination, const DoubleLinkedList& list);
	
   ~DoubleLinkedList();
    void destroy();
    void print() const;
    void reversePrint() const;
	void insert(const int data);
	void insertStart(const int data);
	int getLength();
	bool isEmpty() const;
	Node *search(int data);
};

#endif