#include <vector>
#include <iostream>
int main(int argc, char const *argv[]) {
  struct Struct{
    int a;
    int b;
  };

  std::vector<Struct> vec;
  vec.push_back({1,2});
  vec.push_back({3,4});
  vec.push_back({5,6});

  std::cout << vec[2].a << '\n';
  return 0;
}
