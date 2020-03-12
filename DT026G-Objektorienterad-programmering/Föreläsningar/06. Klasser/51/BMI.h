#ifndef BMI_H
#define BMI_H

#include <string>
using namespace std;

class BMI
{
public:
  BMI(const string &name, int age, double weight, double height);
  BMI(const string &name, double weight, double height);
  double getBMI();
  string getStatus();
  string getName();
  int getAge();
  double getWeight();
  double getHeight();

private:
  string name;
  int age;
  double weight;
  double height;
};

#endif
