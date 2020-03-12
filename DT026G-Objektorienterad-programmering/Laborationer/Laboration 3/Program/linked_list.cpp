#include "linked_list.h"

using namespace std;

//Constructor
linked_list::linked_list()
{
  head = nullptr;
  tail = nullptr;
}

//Copy constructor
linked_list::linked_list(const linked_list& src)
{
  linked_list& this_ = *this;
  this_ += src;
}

//Deconstructor
linked_list::~linked_list()
{
  clear();
}

//Deep copy
linked_list& linked_list::operator=(const linked_list& rhs)
{
  //Make sure that we do not try to copy ourselves
  if(this != &rhs)
  {
    //If the list that we are going to copy to aren't empty, empty it
    if(!is_empty())
    {
      clear();
    }

    //Copy our right hans side list to our list, that is the left hand side one
    *this += rhs;

    return *this;
  }
    else
    {
      return *this;
    }
}

//Merge two list's
linked_list& linked_list::operator+=(const linked_list& rhs)
{
  //Create a temporary node that's a copy of rhs head
  node *temp = rhs.head;

  while(temp != nullptr)
  {
    //Push back the values of the temp node into to list
    push_back(temp->value);

    //Set temporary node to next node
    temp = temp->next;
  }

  return *this;
}

/*====================================================================================================
* Function type: void
* Function name: clear
* Description: Delete's list node's and set the head and tail pointers to NULL
* ==================================================================================================*/
void linked_list::clear()
{
  while(head != nullptr)
  {
    //Create a temporary node that is a copy of head
    node *temp = head;

    //Point head to next node in list.
    head = head->next;

    //Delete temp node
    delete temp;
  }

  head = nullptr;
  tail = nullptr;
}

/*====================================================================================================
* Function type: void
* Function name: list_sorting
* Description: Sort the list
* ==================================================================================================*/
void linked_list::list_sorting()
{
  //Create a temporary node that is a copy of head
  node *temp = head;
  vector<double> vectorList;

  //Step throught the list
  while(temp != nullptr)
  {
    //Insert current list value in back of vector
    vectorList.push_back(temp->value);

    //Set temp to the next node in list
    temp = temp->next;
  }

  //Clear the list
  clear();

  //Sort the vector
  sort(vectorList.begin(), vectorList.end());

  //Insert the vector element's back to the list
  for(double value : vectorList)
  {
      push_back(value);
  }
}

/*====================================================================================================
* Function type: bool
* Function name: sort_check
* Description: Control if the list is sorted
* Return type: bool
* Return: true/false
* ==================================================================================================*/
bool linked_list::sort_check()
{
  node *curr = head;
  double prev = 0;

  //Step throught the list
  while(curr != nullptr)
  {
    //If the previos node's value is bigger than the next's value
    //This means that the list is NOT sorted
    if(prev > curr->value)
    {
      return false;
    }

    prev = curr->value;
    curr = curr->next;
  }

  return true;
}

/*====================================================================================================
* Function type: void
* Function name: insert
* Description: Insert a node in the list with a given value at a given position
* ==================================================================================================*/
void linked_list::insert(double value , size_t pos)
{
  //If the given position is zero
  if(pos == 0)
  {
    push_front(value);
  }
    //Else if the given position is larget than the list
    else if(pos >= size()-1)
    {
      push_back(value);
    }
      //If the given position is in the span of the node
      else
      {
        //Create a new node that is a copy of head
        node *temp = head;

        size_t counter = 0;

        //Create a new node that will get the given value
        node *newNode = new node(value);

        //As long as the temporary node's next pointer is NOT equal to null pointer
        while(temp->next != nullptr)
        {
          if(counter == pos)
          {
            //Point the new node's next pointer to the temporary node
            newNode->next = temp;

            //Point the new node's previous pointer to the temporary node's previous pointer
            newNode->prev = temp->prev;

            //Point the node BEFORE the temporary node to the new node.
            temp->prev->next = newNode;

            //Point the temporary's previous poiner to the newly created node
            temp->prev = newNode;

            //break the while loop
            break;
          }
          counter++;

          //Set the temporary pointer to the next temporary's pointer
          temp = temp->next;
        }
      }
}

/*====================================================================================================
* Function type: void
* Function name: push_front
* Description: Create a new node in front of the list, and insert the value
* ==================================================================================================*/
void linked_list::push_front(double value)
{
  //Create a new node
  node *newNode = new node(value);

  //If the head of the list is poiting to null pointer, wich means the list has no nodes
  if(head == nullptr)
  {
    head = newNode;
    tail = newNode;
  }
    else
    {
      //Point the head previous node to the newly created node
      head->prev = newNode;

      //Point the newly creted node next pointer to the head
      newNode->next = head;

      //Point the head to the newly created node
      head = newNode;
    }
}

/*====================================================================================================
* Function type: void
* Function name: push_back
* Description: Create a new node in the back of the list, and insert the value
* ==================================================================================================*/
void linked_list::push_back(double value)
{
  //Create a new node
  node *currentNode = new node(value);

  //If the tail of the list pointing to null pointer
  if(tail == nullptr)
  {
    head = currentNode;
    tail = currentNode;
  }

    else
    {
      //Point my tail next to the current node
      tail->next = currentNode;

      //Point my current node previous to the tail
      currentNode->prev = tail;

      //Point the tail to the newly created node
      tail = currentNode;
    }
}

/*====================================================================================================
* Function type: double
* Function name: front
* Description: Get the first node's value in the list
* Return type: double
* Return: head->value
* ==================================================================================================*/
double linked_list::front() const
{
  if(head != NULL)
  {
    return head->value;
  }

  return 0;
}

/*====================================================================================================
* Function type: double
* Function name: back
* Description: Get the last node's value in the list
* Return type: double
* Return: tail->value
* ==================================================================================================*/
double linked_list::back() const
{
  if(tail != NULL)
  {
    return tail->value;
  }

  return 0;
}

/*====================================================================================================
* Function type: double
* Function name: at
* Description: Get the value from a given node in the list
* Return type: size_t
* Return: counter
* ==================================================================================================*/
double linked_list::at(size_t pos) const
{
  node *currentNode = head;
  size_t counter = 0;

  while(currentNode != NULL)
  {
    if(counter == pos)
    {
      //Return the value of the node
      return currentNode->value;

      //Break the while loop
      break;
    }

    counter ++;

    //Set the current node to the next node in the list
    currentNode = currentNode->next;
  }

  return 0;
}

/*====================================================================================================
* Function type: void
* Function name: remove
* Description: Delete a node at a given position
* ==================================================================================================*/
void linked_list::remove(size_t pos)
{
  //Ig given position is zero, remove the first node
  if(pos == 0)
  {
    pop_front();
  }

    //Else if the given position is larger than the list, remove the last node
    else if(pos >= size()-1)
    {
      pop_back();
    }

      //Else, if the given position is in the list's range
      else
      {
        //Create a temporary node that is a copy of that list's head
        node *temp = head;

        int counter = 0;
        while(temp != nullptr)
        {
          if(counter == pos)
          {
            //Set the temporary's previous node next pointer equal to temporary's next node
            temp->prev->next = temp->next;

            //Set the temporary's next node previous pointer equals to the temporary previous node
            temp->next->prev = temp->prev;

            //Delete the temporary node
            delete temp;

            //Break the while loop
            break;
          }// end if

          counter++;

          //Set the temporary node to the next node
          temp = temp->next;
        }//end while
      }//end else
}

/*====================================================================================================
* Function type: double
* Function name: pop_front
* Description: Delete the first node in the list
* Return type: double
* Return: value
* ==================================================================================================*/
double linked_list::pop_front()
{
  double value = 0;

  //Do the list contains node's?
  if(head != nullptr)
  {
    //Get the head value
    value = head->value;

    //Do the list contains more than one node?
    if(head->next != nullptr)
    {
      //Create a temporary node that is head
      node *temp = head;

      //Point head to next node
      head = head->next;

      //Set head previous pointer to null
      head->prev = nullptr;

      //Delete temporary node
      delete temp;
    }

    //If the list does not contains any node's
    else
    {
      head = nullptr;
      tail = nullptr;
    }
  }

  return value;
}

/*====================================================================================================
* Function type: double
* Function name: pop_back
* Description: Delete the last node in the list
* Return type: double
* Return: value
* ==================================================================================================*/
double linked_list::pop_back()
{
  double value = 0;

  //Do the list contains node's?
  if(tail != nullptr)
  {
    //Get the head value
    value = tail->value;

    //Do the list contains more than one node?
    if(tail->prev != nullptr)
    {
      //Create a temporary node that is head
      node *temp = tail;

      //Point head to next node
      tail = tail->prev;

      //Set head previous pointer to null
      tail->next = nullptr;

      //Delete temporary node
      delete temp;
    }

    //If the list does not contains any node's
    else
    {
      head = nullptr;
      tail = nullptr;
    }
  }

  return value;
}

/*====================================================================================================
* Function type: size_t
* Function name: size
* Description: Return listsize
* Return type: size_t
* Return: counter
* ==================================================================================================*/
size_t linked_list::size() const
{
  node *currentNode = head;
  size_t counter = 1;

  while(currentNode != NULL)
  {
    currentNode = currentNode->next;
    counter ++;
  }

  return counter;
}

/*====================================================================================================
* Function type: bool
* Function name: is_empty
* Description: Control if the list is empty
* Return type: bool
* Return: true/false
* ==================================================================================================*/
bool linked_list::is_empty() const
{
  //Return true if head is null
  return head == NULL;
}

/*====================================================================================================
* Function type: void
* Function name: print
* Description: Print the values of the list
* ==================================================================================================*/
void linked_list::print() const
{
  //Create a new node that is a copy of the list's head
  node *currentNode = head;

  //Step throught the list
  while(currentNode != nullptr)
  {
    //Print the value of the current node
    cout << currentNode->value << " ";

    //Set the current node to the next node
    currentNode = currentNode->next;
  }
}

/*====================================================================================================
* Function type: void
* Function name: print_reverse
* Description: Print the values of the list the reverse way
* ==================================================================================================*/
void linked_list::print_reverse() const
{
  //Create a new node that is a copy of the list's tail
  node *currentNode = tail;

  //Step throught the list
  while(currentNode != NULL)
  {
    //Print the value of the current npde
    cout << currentNode->value << endl;

    //Set the current node to the previous node
    currentNode = currentNode->prev;
  }
}

//Node's struct constructor
linked_list::node::node(double value, node *next, node *prev)
{
  //Set this instance value as value
  this->value = value;

  //Set this instance next pointer as next pointer
  this->next = next;

  //Set this instance previous pointer as previous pointer
  this->prev = prev;
}
