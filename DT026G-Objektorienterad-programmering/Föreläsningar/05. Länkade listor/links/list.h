//------------------------------------------------------------------------------
// list.h
// Headerfil till klassen List
// En enkellänkad lista
//------------------------------------------------------------------------------
#ifndef listH
#define listH
//------------------------------------------------------------------------------
class Node;   // Forward deklaration

class List
{
  public:
    List();
    ~List();
    void putFirst(int d);
    void putLast(int d);
    void insAfter(int searchItem, int d);
    void showList() const;
    Node *search(int searchItem) const;
  private:
    Node *first;
};
#endif
