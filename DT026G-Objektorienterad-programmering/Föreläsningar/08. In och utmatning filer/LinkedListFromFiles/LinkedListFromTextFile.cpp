
#include <iostream>
#include <cassert>
#include <string>
#include <fstream>
using namespace std;

class Node {
public:
    string str;
    Node* pnext;
};

class List {
public:
    Node* first;
    int count;
};
//read the content in a file and put it in the list
void readContent(fstream &file,List*);
bool openFileIn(fstream&, string);
// add a new node at the beginning of a list
void insert_front(List* list, string s);        
void print_list(List* list);
void delete_list(List* list);


int main()
{
    List* mylist = new List;
    mylist->count = 0;
    
    fstream dataFile;
    if (!openFileIn(dataFile, "demofile.txt"))
	{
            cout << "File open error!" << endl;   
	}
    
    cout << "empty list: ";
    print_list(mylist);
   
    cout << "read from file and insert front: ";
    readContent(dataFile,mylist);
    
    //insert_front(mylist, "Nayeb");
    print_list(mylist);
    
    cout << "delete list, then print: ";
    delete_list(mylist);
    print_list(mylist);
    
    return 0; 
}
    
void readContent(fstream &file,List* list)
{
   string word;
   while (file >> word)
   {
      insert_front(list,word);
   }
}


// add a new node at the beginning of a list
void insert_front(List* list, string s)
{
    Node* n = new Node;
    n->str = s;
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
        cout << n->str;
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
bool openFileIn(fstream &file, string name)
{
   file.open(name.c_str(), ios::in);
   if (file.fail())
      return false;
   else
      return true;
}

