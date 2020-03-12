/*
 * A C++ simple linked list
 */
 
 //Remember to break it into header and source files!!!
#include <iostream>
#include <fstream>
using namespace std;

// One node in a list
class Node {
private:
    int data; // the number in this node
    Node *next; // pointer to next node
public:
     
    // creates a new node holding a specified integer value
    Node(int i): data(i), next(nullptr) {}
    // Copy constructor: A deep copy.  Copies the parameter node
    // as well as the chain of nodes it points to.
    Node(const Node& other) {
		data = other.data;
		if (other.next == nullptr)
			next = nullptr;
		else
			next = new Node(*other.next);
	} // end copy constructor

	
    // cleans up storage this node points at
    ~Node() {delete next;}
	
    // The LinkedList class can use a node's private member variables
    friend class LinkedList;
    
	// This operator also needs to use node attributes to walk down a list being printed
    friend ostream& operator <<(ostream &destination, const LinkedList& list);
};

// An entire list
class LinkedList {
private:
    Node *first; // pointer to first node in list
public:
    LinkedList(); // initializes empty list
    LinkedList(const LinkedList &other); // copy constructor -- deep copy
    ~LinkedList(); // destructor: cleans up all the nodes
    bool isEmpty() const; // returns true if list is empty
    void addToBeginning(int value); // adds value to start of list
    void deleteFirst(); // removes first node from list, no-op if list is empty
    friend ostream& operator <<(ostream &destination, const LinkedList& list); // writes list to a stream
    LinkedList& operator =(const LinkedList& rightHandSide); // assignment -- deep copy and no memory leak
}; // end class LinkedList

/*
 * A trivial function: creates a list, adds some integers to it, then exits, so the list object
 * is deleted from the call stack.  If the list destructor isn't doing what it should, this function
 * will create a lot of garbage.
 */
void useList() {
    LinkedList newList;
    for (int i = 1; i <= 10; i++)
        newList.addToBeginning(i);
} // end useList

// Main method: Correctness testing, then stress tests to detect memory leaks.
int main() {
    LinkedList myList;
    for (int i = 1; i <= 5; i++) 
        myList.addToBeginning(i);
    cout << myList << endl;

    while (!myList.isEmpty()) {
        myList.deleteFirst();
        cout << myList << endl;
    } // end while

    for (int i = 1; i <= 3; i++)
        useList();
    cout << endl;

    // The following sections test the copy constructor and assignment operator.
    // They will produce bad results or crash the program if the constructor or operator
    // does a shallow copy, producing aliasing between lists.
    LinkedList list1;
    list1.addToBeginning(42);
    list1.addToBeginning(37); // now list1 = [37,42]
    LinkedList list2(list1); // using copy constructor
    cout << list2 << endl; // [ 37 42 ]
    list2.deleteFirst(); // list2 = [ 42 ]
    list1.addToBeginning(5); // list1 = [ 5 37 42 ]
    cout << list2 << endl; // [ 42 ]
    cout << list1 << endl; // [ 5 37 42 ]
    cout << endl;

    // "=" with a declaration invokes copy constructor
    LinkedList list3;
    list3.addToBeginning(1);
    list3.addToBeginning(2); // list3 = [ 2 1 ]
    LinkedList list4 = list3; // uses copy constructor
    list4.addToBeginning(3); // list4 = [ 3 2 1 ]
    cout << list3 << endl;  // [ 2 1 ]
    cout << list4 << endl; // [ 3 2 1 ]
    cout << endl;

    // "=" separate from a declaration uses the assignment operator,
    // not the copy constructor
    LinkedList list5;
    list5 = list3; // list5 = [ 2 1 ]
    list5.addToBeginning(4); // list5 = [ 4 2 1 ]
    list3.deleteFirst(); // list3 = [ 1 ]
    cout << list3 << endl; // [ 1 ]
    cout << list5 << endl; // [ 4 2 1 ]
    cout << endl;
   
    /*
    cout << "stress test #1:\n"; // test destructor
    for (int i = 0; i < 1000; i++) {
        if (i % 100 == 0)
            cout << i << endl;
        useList();
    }
    cout << "completed stress test #1\n";
    */
    
    /*
    cout << "stress test #2: \n"; // test deleteFirst
    LinkedList bigList;
    for (int count = 0; count < 1000; count++) {
        if (count % 100 == 0)
            cout << count << endl;
        for (int i = 0; i < 10000; i++)
            bigList.addToBeginning(i);
        while (!bigList.isEmpty())
            bigList.deleteFirst();
    } // end for
    cout << "completed stress test #2\n";
    */
    
    /*
    cout << "stress test #3: \n"; // use "=" operator
    LinkedList bigList;
    for (int count = 0; count < 1000; count++) {
        if (count % 100 == 0)
            cout << count << endl;
        for (int i = 0; i < 10000; i++)
            bigList.addToBeginning(i);
        bigList = LinkedList(); // assign a new empty list to bigList
    } // end for
    cout << "completed stress test #3\n";
    */
    
} // end main


 
// Copy constructor: A deep copy.  Copies the parameter node
// as well as the chain of nodes it points to.
Node::
 
// Constructor: creates a new empty linked list
Linkedlinked_list::LinkedList() {
    first = nullptr;
} // end constructor


// Destructor: cleans up the heap space used by a list.
// Will be called just before the list is deleted from
// the call stack.
Linkedlinked_list::~LinkedList() {
    //cout << "list destructor called\n";
    if (first != nullptr)
        delete first;
} // end destructor


// Returns true if the list is empty
bool Linkedlinked_list::isEmpty() const {
    return (first == nullptr);
} // end isEmpty


// Adds the parameter value to the beginning of the list
void Linkedlinked_list::addToBeginning(int value) {
    Node *nodePtr = new Node(value);
    nodePtr->next = first;
    first = nodePtr;
} // end addToBeginning


// Deletes the first element of the list.
// Does nothing if the list is empty (not an error).
void Linkedlinked_list::deleteFirst() {
    if (first == nullptr)
        return;
    Node *second = first->next;
    first->next = nullptr;
    delete first;
    first = second;
} // end deleteFirst


// Writes a representation of a list to an output stream.
// Parameters: the output stream and the list
// Return result: the output stream (for chained output)
ostream& operator <<(ostream &destination, const LinkedList& list) {
    if (list.first == nullptr)
        destination << "[Empty List]";
    else {
        destination << "[ ";
        Node *ptr = list.first;
        while (ptr != nullptr) {
            destination << ptr->data << " ";
            ptr = ptr->next;
        } // end while
        destination << "]";
    } // end if
    return destination;
} // end <<


// copy constructor -- makes a deep copy of another list
Linkedlinked_list::LinkedList(const LinkedList &other) {
    first = new Node(*other.first);
} // end copy constructor


// override = operator to make a deep copy
// If code is "lhs = rhs",
// implicit parameter is lhs and explicit parameter is rhs,
// kind of like lhs.assign(rhs).
LinkedList& Linkedlinked_list::operator =(const LinkedList& rightHandSide) {
    //cout << "overridden assignment operator called\n";

    // We're about to overwrite the list on the left hand side.
    // Free up the memory it is using
    delete first;
    
    if (rightHandSide.first == nullptr)
        first = nullptr;
    else
        // Use the Node copy constructor to make a full copy of the right hand side
        first = new Node(*rightHandSide.first);
   
    return *this;
} // end operator =
