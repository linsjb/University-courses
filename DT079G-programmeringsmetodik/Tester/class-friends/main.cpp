#include <iostream>
class aClass {
  public:
    friend class bClass;
  private:
    int aVar;
};

class bClass {
  public:
    void printer(aClass &test) {
      test.aVar = 23;
    }

    int returner (const aClass &test) {
      return test.aVar;
    }
};

int main(int argc, char const *argv[]) {
  aClass A;
  bClass B;

  B.printer(A);
  std::cout << "Returner: " << B.returner(A) << '\n';
  return 0;
}
