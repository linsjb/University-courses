#include <array>
#include <numeric>
#include <functional>
#include <iostream>
#include <algorithm>

#include "object.h"
struct MyBinOp {
	double operator()(double& sum, object& o) {
		return sum + o.getWeight();
	}
};

struct MyUnOp {
	double operator()(object& obj) {
		return (double)obj.getWeight();
	}
};

class Pred {
public:
	Pred(double n):
	elem(n) {};

	bool operator()(object& obj) {
		return elem < obj.getWeight();
	}

private:
	double elem;
};

class MyFunc {
public:
	MyFunc(double n):
	elem(n){}

	double operator()(int mean) const {
		return elem - mean;
	}

private:
	double elem;
};

int main() {
	object objArray[] {
		object("Volvo", 1200),
		object("Saab", 1100),
		object("BMW 320", 2000),
		object("BMW 320", 2000),
		object("BMW 520", 2500)
	};

	std::vector<object> objVector(objArray, objArray + 5); // objVector

	std::cout << "myPrint only" << '\n';
	MyPrint mp;

	std::cout << '\n' << "First element of vector" << "\n";
	mp(objVector[0]);	//Print's the first element of the vector

	std::cout << '\n' << "All elements of vector" << "\n";
	mp(objVector.begin(), objVector.end()); //Print's the whole vector

	std::cout << '\n' << "All elements of array" << "\n";
	mp(objArray, objArray+5);	//Print's the whole array


	//  Tasks
	// ----------------------
	// ----------------------
	// ----------------------

	// Task 1
	// -------
	// -------
	// -------
	std::cout << '\n' << "Task 1" << '\n';
	auto write = [](object& n) {
		std::cout << n << '\n';
	};

	for_each(objVector.begin(), objVector.end(), write);

	// Task 2
	// -------
	// -------
	// -------
	std::cout << '\n' << "Task 2" << '\n';
	// found returnerar en pekare som pekar på värdet.
	auto found = find_if(objVector.begin(), objVector.end(), Pred(500));
	std::cout << *found << '\n';

	// Task 3
	// -------
	// -------
	// -------
	std::cout << '\n' << "Task 3" << '\n';
	// Om af når slutet så betyder det att det inte finns några värden.
	// men om den inte når slutet betyder det att det finns dubletter
	auto af = std::adjacent_find(objVector.begin(), objVector.end());
	if (af == objVector.end()) {
		std::cout << "Inga dubbletter funna" << '\n';
	} else {
		std::cout << "Dublett funnen" << '\n';
		std::cout << *af << '\n';
	}

	// Task 4
	// -------
	// -------
	// -------
	std::cout << '\n' << "Task 4" << '\n';
	//Kontrollerar ifall arrayen och vektorn är likadana
	if (equal(objArray, objArray + 4, objVector.begin())) {
		std::cout << "Lika" << '\n';
	} else {
		std::cout << "Inte lika" << '\n';
	}

	// Task 5
	// -------
	// -------
	// -------
	std::cout << '\n' << "Task 5" << '\n';
	//Returnerar en iterator som pekar på det första elementet i delsekvensen hos arrayen
	auto iter = search(objVector.begin(), objVector.end(), objArray + 2, objArray + 4);
	for ( ; iter <= objVector.begin() + 4; iter++) {
	std::cout << *iter << '\n';
	}

	// Task 6
	// -------
	// -------
	// -------
	std::cout << '\n' << "Task 6" << '\n';
	//Accumulate
	double meanValue = accumulate(objVector.begin(), objVector.end(), 0.0, MyBinOp()) / objVector.size();

	std::cout << "The mean value is: " << meanValue << '\n';


	// Task 7
	// -------
	// -------
	// -------
	std::vector<double> v2(objVector.size());
	std::cout << '\n' << "Task 7" << '\n';
	transform(objVector.begin(), objVector.end(), v2.begin(), MyUnOp());

	for (auto e : v2) {
		std::cout << e << '\n';
	}

	// Task 8
	// -------
	// -------
	// -------
	std::cout << '\n' << "Task 8" << '\n';
	//Transform V2
	transform(v2.begin(), v2.end(), v2.begin(), MyFunc(meanValue));

	for (auto &e : v2) {
		std::cout << e << '\n';
	}

	// Task 9
	// -------
	// -------
	// -------
	std::cout << '\n' << "Task 9" << '\n';

	std::sort(v2.begin(), v2.end());

	std::cout << "V2 sorted" << '\n';
	for (auto &e : v2)
		std::cout << e << '\n';

	return 0;
}
