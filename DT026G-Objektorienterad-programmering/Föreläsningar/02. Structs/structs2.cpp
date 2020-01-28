//This version reads in and prints out the object content 
//through overloaded external operator functions >> and <<
//to call readin() and print()



#include <iostream>

using namespace std;

struct person
{
  string name;
  int age;
  void readin();
  void print();
 
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

void person::print()
{
 cout << "Name: " <<name<<endl;
 cout << "Age: "<<age<<endl;

}


ostream& operator<<(ostream& out, person& p) 
{ 
      p.print();
   
    return out; 
} 

istream& operator>>(istream& in, person& p) 
{ 
  p.readin();
  return in; 
}  

void person::readin()
{
    cout << "Enter person name and age:"; 
    getline(cin,name); 
    cout << "Enter person age:"; 
    cin >> age;

}