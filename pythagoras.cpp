//
// Created by Simon on 29/03/2021.
//
#include "includes.h"

double hypotenuse(double arg1, double arg2) {
    return sqrt(arg1 * arg1 + arg2 * arg2);
}

void pythagoras() {
    double k1, k2;
    std::cout << "Kathete 1:";
    std::cin >> k1;
    std::cout << "Kathete 2:";
    std::cin >> k2;

    std::cout << "The hypotenuse equals " << hypotenuse(k1, k2) << std::endl;
}