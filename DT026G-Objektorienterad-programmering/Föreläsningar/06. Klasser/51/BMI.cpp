#include <iostream>
#include "BMI.h"
using namespace std;

BMI::BMI(const string &name, int age, double weight, double height)
{
  this->name = name;
  this->age = age;
  this->weight = weight;
  this->height = height;
}

BMI::BMI(const string &name, double weight, double height)
{
  this->name = name;
  this->age = 20;
  this->weight = weight;
  this->height = height;
}

double BMI::getBMI()
{
  const double KILOGRAMS_PER_POUND = 0.45359237;
  const double METERS_PER_INCH = 0.0254;
  double bmi = weight * KILOGRAMS_PER_POUND /
    ((height * METERS_PER_INCH) * (height * METERS_PER_INCH));
  return bmi;
}

string BMI::getStatus()
{
  double bmi = getBMI();
  if (bmi < 16)
    return "seriously underweight";
  else if (bmi < 18)
    return "underweight";
  else if (bmi < 24)
    return "normal weight";
  else if (bmi < 29)
    return "overweight";
  else if (bmi < 35)
    return "seriously overweight";
  else
    return "gravely overweight";
}

string BMI::getName()
{
  return name;
}

int BMI::getAge()
{
  return age;
}

double BMI::getWeight()
{
  return weight;
}

double BMI::getHeight()
{
  return height;
}


