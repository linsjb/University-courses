//This version reads in and prints out the object content 
//through memberfunctions readin() and  print()

#include <iostream>

using namespace std;

struct person
{
  //Datamedlemmar
  string name;
  int age;
  //medlemsfunktioner
  void readin();
  void print();
  //string getName();
 void setName(string n);

};

int main()
{

 person p;

 p.readin();

 cout <<"This print is through print member function:"<<endl;
 p.setName("Kalle");
 p.print();

 return 0;
}

void person::print()
{
 cout << "Name: " <<name<<endl;
 cout << "Age: "<<age<<endl;

}
void person::readin()
{
    cout << "Enter person name and age:"; 
    getline(cin,name); 
    cout << "Enter person age:"; 
    cin >> age;

}

void person::setName(string namn)
{
  name=namn;
}