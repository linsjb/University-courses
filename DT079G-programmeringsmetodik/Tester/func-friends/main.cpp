#include <iostream>
#include "house.h"

void door(house &h) {
  std::cout << "Enter roof size: ";
  std::cin >> h.roofSize;

  std::cout << "Enter floor size: ";
  std::cin >> h.floorSize;
}

int main(int argc, char const *argv[]) {
  house house;
  door(house);

  std::cout << "Roof size: " << house.getRoof() << '\n';
  std::cout << "Floor size: " << house.getFloor() << '\n';
  return 0;
}
