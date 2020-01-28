//File: IntVector.h


#ifndef VEC_H
#define VEC_H

#include <iostream>
#include "Except.h"
#include <exception> 
using namespace std;

class Vec
{
private:
	int *data;
	int size;
	static int count;
public:

	explicit Vec(int size = 10); // med given storlek, har default = 10

	Vec(const Vec&);     // initieringskonstruktor

	const Vec& operator=(const Vec&);

	~Vec();

	int max() const;
	void push_back(const int& val) throw(bad_alloc);
	void pop_back(){ size--; }
	int Size() const { return size; }
	const int get(long index) const throw(OutOfRange); // get a value
	int &get(int index) const throw(OutOfRange);  // get a value
	//void print(ostream&, const Vec&);

	int operator[](int pos) const throw(OutOfRange);  //for int dd=b[8];

	int& operator[](int i) throw(OutOfRange);  //for a[8] =b[8];

	Vec operator+ (const Vec&); //v1+v2

	Vec operator+ (int)  const;  //v1+1

	Vec& operator++();		//++ operator prefix
	Vec& operator++(int unused);	//++ operator postfix

	bool operator== (const Vec&) const;

	const Vec& operator &= (const int);
	const Vec& operator &= (const Vec&);


	friend Vec operator+ (int, const Vec&); //1+v1

	friend ostream& operator<< (ostream&, const Vec&);
	friend istream& operator>>(istream&, Vec&);

};

bool operator!= (const Vec& v1, const Vec& v2);
#endif
