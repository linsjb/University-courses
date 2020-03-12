#include <iostream>

int main(int argc, char const *argv[]) {
  int a[5] = {0,1,2,3,4};

  std::cout << a[0] << '\n';
  *a = 10;
  std::cout << a[0] << '\n';
  *(a+0) = 11;
  std::cout << a[0] << '\n';
  *(a+1) = 23;
  std::cout << a[1] << '\n';
  *(a+2) = 55;
  std::cout << a[2] << '\n';
  2[a] = 333;
  std::cout << a[2] << '\n';

  return 0;
}
