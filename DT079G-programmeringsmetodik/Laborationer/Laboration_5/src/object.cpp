#include <stdlib.h>
#include "object.h"

object::object() : model("Unknown"), weight(0) {}

object::object(std::string setModel, double setWeight):
model(setModel), weight(setWeight) {}

bool object::operator==(const object & rhs) {
	return model == rhs.model;
}

double object::getWeight() const {
	return weight;
}
