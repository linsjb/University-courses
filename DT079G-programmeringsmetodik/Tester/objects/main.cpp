#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

  struct element {
    int priority;
    string payload;
  };

  vector<element> vec;
  

  for (size_t i = 0; i < vec.size(); i++) {
    std::cout << "Priority: " << vec[i].priority << '\n';
    std::cout << "Payload: " << vec[i].payload << '\n';
    std::cout << '\n';
  }
  return 0;
}
