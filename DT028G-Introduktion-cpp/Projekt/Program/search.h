#include <vector>
#include <string>

#include "file_handling.h"

using namespace std;

vector<int> getIndex(vector<string>& toSearch, string syntax);
static bool stringContains(string syntax, string text);
void printResult(vector<int> indexes, vector<string> search, vector<string> names);
void search(vector<string>& nameVector, vector<string>& socialSecNumberVector, vector<string>& addressVector, vector<string>& zipCodeVector, vector<string>& phoneNumberVector, vector<string>& emailVector, vector<string>& noteVector);