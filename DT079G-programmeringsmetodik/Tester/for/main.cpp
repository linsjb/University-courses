#include <iostream>
int main () {
  char a[3] = {'a', 'b', 'c'};

  for (auto e: a) {
    std::cout << e << ",";
  }
  return 0;
}
