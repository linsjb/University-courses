#include <iostream>

int main () {
  int arr1 [] = {1,2,3,4};

  int arr2 [] = {1,1,3,4,5};

  for(int a : arr1) {
    for(int b : arr2) {
      if(a == b) {
        std::cout << a << " = " << b << '\n';
      }
    }
  }
  return 0;
}
