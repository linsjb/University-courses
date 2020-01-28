#include <iostream>
#include <string>

using namespace std;


void f(int x);
int main() {
	int test;
	cout << " Type a digit:";
	while (cin >> test) {
		try {
			cout << "1 ";
			f(test);
			cout << "2 ";
		}
		catch (out_of_range e) {
			cout << "3 ";
			cout << e.what();
			cout << "4 ";
		}
		cout << "5 " << endl;
		cout << " Type a digit:";
	}
	return 0;
}//end main


void f(int x) {
	cout << "6 ";
	if (x < 0) {
		throw out_of_range("7 ");
	}
	else if (x > 100) {
		throw length_error("8 ");
	}
	cout << "9 ";
}//end f
