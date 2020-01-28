#include <iostream>
#include <ctime>
int main(int argc, char const *argv[]) {
  srand (time(NULL));
  int random = std::rand()%3;
  std::cout << random << '\n';
  return 0;
}
