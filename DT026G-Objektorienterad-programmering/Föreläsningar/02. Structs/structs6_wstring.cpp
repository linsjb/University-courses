//This version reads in and prints out the object content 
//through overloaded external operator functions >> and <<
//friend functions only

#include <iostream>
#include <vector>
#include <algorithm>
#include <locale>
#include <string>

using namespace std;

struct person
{
  wstring name;
  int age;
  void print();
  // the operator functions as friends
  //friend wostream& operator<< (wostream&, person&); 
 // friend wistream& operator>> (wistream&, person&); 
  
};

// the operator functions as external functions
wostream& operator<< (wostream&, person&); 
wistream& operator>> (wistream&, person&);

bool operator==(const person& lhs, const person& rhs)
{
  return lhs.name == rhs.name;
}

bool compareByAge(const person &a, const person &b)
{
    return a.age < b.age;
}


int main()
{


//system("chcp 1252");
//testing Swedish characters
/*
wstring a=L"Nayeb Mäleki";
 wcout <<a <<endl;
*/
setlocale(LC_ALL, "sv");  // Svensk locale

 person p;
 
 vector<person> personer;
 for(int i=0;i<3;i++)
 {
    wcin >> p;
    personer.push_back(p);
 }

sort(personer.begin(),personer.end(),compareByAge);
   

for( auto& elem:personer)
  wcout <<elem;

//Find the first person i vector!
person p1=personer[0];
//vector<person>::iterator it;

auto it=std::find(personer.begin(), personer.end(), p1);
if ( it != personer.end())
{
   std::cout << "The person found"<<std::endl;
}

auto it1=std::count(personer.begin(), personer.end(), p1);
   std::cout << "The person found"<<it1 << std::endl;



 //cout << p;

 return 0;

}



wostream& operator<<(wostream& out, person& p) 
{ 
      out << "Name: " <<p.name<<endl;
      out << "Age: "<<p.age<<endl;
   
    return out; 
} 

wistream& operator>>(wistream& in, person& p) 
{ 
  cout << "Enter person name and age:"; 
  getline(in,p.name); 
  transform(p.name.begin(), p.name.end(),p.name.begin(),towlower); // towlower for lower case

  cout << "Enter person age:"; 
  in >> p.age;
  in.ignore();
  return in; 
}  