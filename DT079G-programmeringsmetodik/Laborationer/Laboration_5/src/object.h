#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "myPrint.h"

class object {
public:
	object();
	object(std::string setModel, double setWeight);

	bool operator==(const object& rhs); //Compares the value of the string object

	double getWeight() const;

	friend class MyPrint;

	friend std::ostream& operator<<(std::ostream &output, const object &obj) {
		output << obj.model << " " << obj.weight;
		return output;
	}

private:
	std::string model;
	double weight;
};
