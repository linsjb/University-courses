//------------------------------------------------------------------------------
// list.cpp
// Definitionsfil f�r klassen List
// En enkell�nkad lista

//------------------------------------------------------------------------------

#pragma hdrstop
#include "list.h"
//------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;
//------------------------------------------------------------------------------
// Definiera en klass som representerar en nod i en enkell�nkad lista
//------------------------------------------------------------------------------
class Node
{
  friend class List;
  Node *next;
  int data;
  Node(Node *n, int d) : next(n), data(d)
  {}
};
//------------------------------------------------------------------------------
// Funktionsdefinitioner f�r klassen List
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//F�rvald konstruktor. Skapa ett listhuvud
//------------------------------------------------------------------------------
linked_list::List()
{
  first = 0;
}

//------------------------------------------------------------------------------
// Destruktor
// Frig�r allokerat minne
//------------------------------------------------------------------------------
linked_list::~List()
{
  while(first !=0)
  {
    Node *p= first;
    first = p->next;
    delete p;
  }
}

//------------------------------------------------------------------------------
// S�tt in data f�rst i listan
//------------------------------------------------------------------------------
void linked_list::putFirst(int d)
{
  first = new Node(first,d);
}

//------------------------------------------------------------------------------
// S�tt in data sist i listan
//------------------------------------------------------------------------------
void linked_list::putLast( int d)
{
  if(first==0)
    first = new Node(first,d);
  else
  {
     Node *p;
     for(p=first; p->next; p=p->next) ;
     p->next = new Node(0,d);
  }
}
//------------------------------------------------------------------------------
// S�tt in data efter data med v�rdet 'serachItem'
//------------------------------------------------------------------------------
void linked_list::insAfter(int searchItem, int d)
{
  Node *p = search(searchItem);
  if(p!=0)
    p->next = new Node(p->next, d);
}

//------------------------------------------------------------------------------
// Skriv ut listan
//------------------------------------------------------------------------------
void linked_list::showList() const
{
  for( Node *p=first; p  ; p=p->next)
    cout << setw(4) << p->data;
    cout << endl;
}

//------------------------------------------------------------------------------
// S�k i listan efter noden med data = searchItem
//------------------------------------------------------------------------------
Node *linked_list::search(int searchItem) const
{
  Node *p;
  for(p=first; p && p->data != searchItem; p=p->next) ;
  return p;
}
//------------------------------------------------------------------------------
