//This version reads in and prints out the object content 
//through overloaded external operator functions >> and <<
//only



#include <iostream>

using namespace std;

struct person
{
  string name;
  int age;
};
// the operator functions as external functions
ostream& operator<< (ostream&, person&); 
istream& operator>> (istream&, person&);

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
    cout << "Enter person name and age:"; 
    getline(in,p.name); 
    cout << "Enter person age:"; 
    in >> p.age;

  return in; 
}  
