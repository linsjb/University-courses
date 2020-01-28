#include <iostream>
#include <string>

using namespace std;

int main() {
	string s = "Object-Based Programming";
	int index, len;
	cout << s << endl;
	while (true) {
		cout << "Enter index and length to erase: ";
		cin >> index >> len;
		try {
			s.erase(index, len);
		}
		catch (out_of_range) {
			cout << "Hey, your out of the line, man!"<<endl;
			continue;  //returns TRUE to while-statement==continue
		}
		break; //returns FALSE to while-statement==cancle and go outside while.
	}//end-while
	cout << s << endl;
	return 0;
}
