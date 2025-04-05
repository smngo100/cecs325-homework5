#include <iostream>
#include "Rational.h"

int main() {

    // Constructs objects
    Rational r1{2, 3};
    Rational r2{5, 4};
    Rational r3{10, 1};

    // Prints objects
    std::cout << r1 << std::endl;
    std::cout << r2 << std::endl;
    std::cout << r3 << std::endl;

    // Prints the results of objects
    Rational a{r1 + r2};
    Rational b{r1 * r2};
    Rational c(5 + r3);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    // Increments r1 by a rational 1/3
    Rational d(1, 3);
    r1 += d;
    std::cout << r1 << std::endl;   // Prints the mutated r1 value

    // Compares r1 < r2
    Rational f{r2};
    if (r1 < f) {
        std::cout << "yes" << std::endl;
    }
    else {
        std::cout << "no" << std::endl;
    }

    return 0;
}