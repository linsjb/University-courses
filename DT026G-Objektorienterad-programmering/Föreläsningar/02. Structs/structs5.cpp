//This version reads in and prints out the object content 
//through overloaded external operator functions >> and <<
//friend functions only

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct person
{
  string name;
  int age;
  void print();
  // the operator functions as friends
  friend ostream& operator<< (ostream&, person&); 
  friend istream& operator>> (istream&, person&); 
};

bool compareByAge(const person &a, const person &b)
{
    return a.age < b.age;
}

int main()
{

 person p;
 vector<person> personer;
 for(int i=0;i<3;i++)
 {
    cin >> p;
    personer.push_back(p);
 }

sort(personer.begin(),personer.end(),compareByAge);


for( auto& elem:personer)
  cout <<elem;


 //cout << p;

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
  in.ignore();
  return in; 
}  

