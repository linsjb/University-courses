#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ifstream input;

  // Open a file
  input.open("numbers.txt");

  int score;
  int total = 0;

  // Read data
  while (!input.eof()) // Continue to read if not end of file
  {
    input >> score;
    cout << score << endl;
    total += score;
  }

  cout << "Total score is " << total << endl;

  // Close file
  input.close();

  cout << "Done" << endl;
  return 0;
}
