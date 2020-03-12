//This version reads in and prints out the object content
//through overloaded external operator functions >> and <<
//friend functions only

#include <iostream>

using namespace std;

struct person
{
  string name;
  int age;

  // the operator functions as friends
  friend ostream& operator<< (ostream&, person&);
  friend istream& operator>> (istream&, person&);
};

int main()
{

 person p;
 cin >> p;
 cout << p;

 return 0;
}


ostream& operator<<(ostream& out, person& p)
{
  out << "Name: " <<p.name<<endl;
  out << "Age: "<<p.age<<endl;

  return out;
}

istream& operator>>(istream& in, person& p)
{
  cout << "Enter person name:";
  getline(in,p.name);

  cout << "Enter person age:";
  in >> p.age;

  return in;
}
