//File: IntVector.cpp
#include "IntVector.h"

int Vec::count = 0;


Vec::Vec(int size)  // med given storlek, har default = 10
{
	this->size = size;
	data = new int[size];

	for (int i = 0; i < size; i++)
	{
		data[i] = 0;
	}

	cout << "Default Ctor, storlek = " << size << endl;
	cout << "Count: " << ++count << endl;

}

Vec::Vec(const Vec& vector)
{
	size = vector.size;
	data = new int[size];

	for (int i = 0; i < size; i++)
	{
		data[i] = vector.data[i];
	}

	cout << "Copy Ctor, storlek = " << size << endl;

}

Vec::~Vec()
{
	delete[] data;

	cout << "Destruktor, storlek = " << size << endl;
}

/*
int& Vec::operator[] (int index)
{
	if (index<0 || index >= size)
		throw OutOfRange(0, size - 1, index);

	return data[index];
}
*/

int Vec::operator[](int index) const throw(OutOfRange)
{
	if (index<0 || index >= size)
		throw OutOfRange(0, size - 1, index);
	return data[index];

}


// Lägg ihop två vektorer elementvis, typ v1 + v2
// Returvärde är en ny vektor (INTE en referens !)
Vec Vec::operator+ (const Vec& vector)
{
	Vec temp(vector);

	for (int i = 0; i < size; i++)   // Borde kolla storlekarna !
	{
		temp.data[i] = temp.data[i] + this->data[i];
	}

	cout << "operator+ (v1, v2)" << endl;

	return temp;
}



// Addera en skalär till alla element, typ v + 2
// Returvärde är en ny vektor (INTE en referens !)
Vec Vec::operator+ (int scalar) const
{
	Vec temp(*this);                // skapa en kopia av *this

	for (int i = 0; i < size; i++)  // adderar ihop
	{
		temp.data[i] = temp.data[i] + scalar;
	}

	cout << "operator+ (int)" << endl;

	return temp;
}


// Addera en skalär till alla element, typ 2 + v
// Returvärde är en ny vektor (INTE en referens !)
// Obs friend, så inget Vec:: framför.

Vec operator+ (int scalar, const Vec& vector)
{
	cout << "operator+ (int, vec)" << endl;

	return vector + scalar;		// använd en annan operator+
}



// Tilldelningsoperator, returnera en referens
// så att det går att kedja anrop, typ a = b = c

const Vec& Vec::operator= (const Vec& vector)
{
	if (&vector != this)		 // undvik a = a (varför ?)
	{
		delete[] data;		 // ta bort gamla datat
		size = vector.size;
		data = new int[size]; // ny plats för data

		for (int i = 0; i < size; i++)  // kopiera nya datat
			data[i] = vector.data[i];
	}

	cout << "operator=" << endl;

	return *this;
}

int Vec::max() const
{
	int m = data[0];
	for (int i = 1; i<size; i++)
		if (data[i] > m)
			m = data[i];
	return m;
}

void Vec::push_back(const int& val)
{

	Vec temp(*this);
	delete[] data;
	data = new int[size + 1];
	for (int i = 0; i<size; i++)
		data[i] = temp.data[i];
	data[size] = val;
	size++;
}

int& Vec::get(int index) const throw(OutOfRange &)
{
	if (index<0 || index >= size)
		throw OutOfRange(0, size - 1, index);
	
	return data[index];
}



const int Vec::get(long index) const {

	if (index<0 || index >= size)
		throw OutOfRange(0, size - 1, index);

	return data[index];
}


// Utskriftsoperator, returnerar en referens för att tillåta
// kedjade anrop typ cout << vec1 << vec2
// Obs friend-funktion
ostream& operator<< (ostream &os, const Vec& vector)
{
	os << "(";
	if (vector.size > 0)
	{
		os << vector.get(0);
		for (int i = 1; i < vector.size; i++)
		{
			os << ", " << vector.get(i);
		}
	}
	os << ")";

	return os;
}

istream& operator>>(istream& ins, Vec& indata)
{

	cout << "(x x x x x ...)" << endl;
	for (int i = 0; i<indata.size; ++i)
		ins >> indata.data[i];

	return ins;
}

// ++ operator ++v (prefix)

Vec& Vec::operator++()
{
	for (int i = 0; i<size; i++)
		++data[i];

	return *this;

}

// ++ operator v++ (postfix)

Vec& Vec::operator++(int unused)  {

	for (int i = 0; i<size; i++)
		data[i]++;

	return *this;

}



//  == operator

// returns true if the vector sizes are the same and every element is the same

bool Vec::operator== (const Vec& v) const  { // == operator

	if (size != v.size)
		return false;

	for (int i = 0; i< size; i++)
		if (data[i] != v.data[i])
			return false;

	return true;

}

//expand a Vec with antal
const Vec&  Vec::operator &= (const int antal)

{
	int  *q = new int[size + antal];
	for (int i = 0; i<size; ++i)
		q[i] = data[i];

	delete[] data;

	data = q;
	size += antal;

	return *this;
}

//sammanslagning av två Vec
const Vec& Vec::operator &= (const Vec& vector)

{

	int  *q = new int[size + vector.size];
	for (int i = 0; i<size; ++i)
		q[i] = data[i];

	for (int j = 0; j<vector.size; ++j)
		q[j + size] = vector.data[j];

	delete[] data;

	data = q;
	size += vector.size;

	return *this;
}

bool operator!= (const Vec& v1, const Vec& v2)

{
	return !(v1 == v2);
}


/*
void print(ostream& os, const Vec& vector)
{

os << "(";
if (vector.size > 0)
{
os << vector.get(0);
for (int i = 1; i < vector.size; i++)
{
os << ", " << vector.get(i);
}
}
os << ")";


}

*/

