#include <iostream>

class test {
public:
  test(int age, int phoneNumber): age(age), phoneNumber(phoneNumber){}

  int getAge () {
    return age;
  }

  void setAge (int newAge) {
    age = newAge;
  }

  int getPhone () {
    return phoneNumber;
  }

private:
  int age;
  int phoneNumber;
};

int main(int argc, char const *argv[]) {

  test app(25,758);
  std::cout << "Age: " <<  app.getAge() << '\n';
  std::cout << "Phone number: " << app.getPhone() << '\n';
  app.setAge(44);
  std::cout << "Age: " <<  app.getAge() << '\n';

  return 0;
}
