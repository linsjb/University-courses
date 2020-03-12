#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

#include <iostream>
#include <stddef.h>
#include <vector>
#include <algorithm>

class linked_list
{
  public:
    linked_list();
    linked_list(const linked_list& src);
    ~linked_list();

    linked_list& operator=(const linked_list& rhs);

    // adds elements to the back.
    linked_list& operator+=(const linked_list& rhs);

    //Clear list
    void clear();

    //Sort list
    void list_sorting();

    //Control if list is sorted
    bool sort_check();

    // inserting values in node at given position
    void insert(double value , size_t pos);

    // in front
    void push_front(double value);

    // in back
    void push_back(double value);

    //Access head node's value
    double front() const;

    //Access tail node's vaule
    double back() const;

    //Access given position's value
    double at(size_t pos) const;

    // remove node
    void remove(size_t pos);

    // remove node from front
    double pop_front();

    // remove node from back
    double pop_back();

    // size of list
    size_t size() const;

    //Control if the list is empty
    bool is_empty() const;

    //Print the list
    void print() const;

    //Print the list in reverse order
    void print_reverse() const;

  private:
    struct node
    {
      node(double value, node *next=0, node *prev=0);
      double value;
      node *next;
      node *prev;
    };

    node *head;
    node *tail;
};
#endif
