/**
* Course: DT096G
* Moment: Laboration 3
* Author: Linus Sjöbro
* Created: 2019-03-20
* Description:
*/

#include <iostream>

//Positive exponent
template<int exponent, typename b = void>
struct Pow {
  double operator()(double x) {
    return x * Pow<exponent - 1>()(x);
  }
};

//Negative exponent
template<int exponent>
struct Pow <exponent, typename std::enable_if<(exponent < 0)>::type>{
  double operator()(double x) {
    return 1 / Pow<-exponent>()(x);
  }
};

template<>
struct Pow<0> {
  double operator()(double x) {
    return 1;
  }
};

int main() {
Pow<2> pow;

std::cout << pow(3) << std::endl;
return 0;
}
