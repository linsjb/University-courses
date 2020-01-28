//This version reads in and prints out the object content 
//through external functions readin(person&) and  print(person)

#include <iostream>
#include <string>

using namespace std;

struct person
{
  string name;
  int age;
  
};

void print(person p);
void readin(person& p);  

int main()
{

 person p;

 readin(p);

 cout <<"This print is through print member function:"<<endl;

 print(p);

 return 0;
}

void print(person p)
{
 cout << "Name: " <<p.name<<endl;
 cout << "Age: "<<p.age<<endl;

}
void readin(person& p)
{
    cout << "Enter person name and age:"; 
    getline(cin,p.name); 
    cout << "Enter person age:"; 
    cin >> p.age;

}