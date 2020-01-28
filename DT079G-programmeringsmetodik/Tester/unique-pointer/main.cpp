#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[]) {
  unique_ptr<int> p;
  auto test = make_unique<int>();
  return 0;
}
