#include <iostream>
#include <vector>
#include <typeinfo>

#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "cylinder.h"
#include "roundedRectangle.h"
#include "parallelepiped.h"

void getData(std::vector<std::unique_ptr<Shape>>& ptrs) {
    for(int i = 0; i < ptrs.size(); i++) {
      auto &pointerIndex = *ptrs[i];
      std::cout << "Area of " << typeid(pointerIndex).name() << " is "
      << ptrs[i]->getArea() << " cm, and has the colour " << ptrs[i]->getColour() << '\n';
    }
}

int main() {
  std::vector<std::unique_ptr<Shape>> pointers;

  pointers.push_back(std::make_unique<Rectangle>(5,7,"Green"));
  pointers.push_back(std::make_unique<Circle>(7,"Yellow"));
  pointers.push_back(std::make_unique<Cylinder>(7,12,"Brown"));
  pointers.push_back(std::make_unique<RoundedRectangle>(8,6,2,"Blue"));
  pointers.push_back(std::make_unique<Parallelepiped>(2,4,6,"red"));

  getData(pointers);

  return 0;
}
