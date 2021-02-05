# Lab assignment Meta programming c++ templates
## Overview
The objective of this lab is to investigate the c++ templating mech-
anism and implement an algorithm solved at compile time.

## Deliverables
A complete implementation in c++. A discussion
on the topic of templates and your solution. As well as the output
from the execution provided below.

## Implementation
Choose from one of the following two tasks:

- Implement a template class/struct that delivers code for calculating the pow( ) function, similar to the one found in cmath. The exponent is given as an integer (this is key for a successful implementation).
and the mantissa as a functor argument.
Design the class to accept the power/exponent as a template instantiation argument,

- Implement a templated algorithm that solves the towers of hanoi at compile time. The height of the starting grid, as well as additional parameters required (if any), are passed as template arguments. Use a constructor to print the solution parts or overload an operator << to print the solution.

- Note that the algorithms should be solved at compile time.
Just using templates is not sufficient, it is the template mechanism that should solve the problem. Specifically this means that the pow template should provide an operator/function to plug in the runtime value (the compiler cannot of course provide a number before the input is known). For the hanoi solution this means that all the output statements should exist in the compiled code (not considering compiler optimizations).

You can verify that your hanoi solution is a correct one by trying a
compile with a stack size of about 14-16 disks. This should take a
long time.


## Hints
The templaing used in this lab will differ greatly from the more common type parametrization. You will be using numeric arguments as template parameters, and specialized templates for terminating recursion. You should also investigate inheritance in the context of
templates, e.g. you define a template T with parameter 
(type T) and inherit from base type T, this will provide
r
a recursive inheritance tree.
