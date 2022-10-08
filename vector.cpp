//
// Created by Simon on 29/03/2021.
//
#include "includes.h"

void vector() {
    std::vector<double> cost(12);

    // fill
    for (size_t i = 0; i < cost.size(); ++i) {    // size_t adjusts automatically to the system architecture(32/64 Bit)
        cost[i] = static_cast<double>(150 - i * i) / 10.0;
    }

    // print
    for (size_t i = 0; i < cost.size(); ++i) {
        std::cout << i << ": " << cost[i] << std::endl;
    }
    std::cout << std::endl;

    // sum
    double sum = 0.0;
    for (double i : cost) {
        sum += i;
    }
    std::cout << "Sum: " << sum << std::endl;

    // average
    std::cout << "Average: " << sum / cost.size() << std::endl;

    // maximum
    double max{cost[0]};
    for (double i : cost) {
        if (max < i)
            max = i;
    }
    std::cout << "Maximum: " << max << std::endl;

    // Second table
    std::vector<double> sortedCosts{cost};

    // sort ascending
    std::sort(sortedCosts.begin(), sortedCosts.end());

    // print with numbers
    for (size_t i = 0; i < sortedCosts.size(); ++i) {
        std::cout << i << ": " << sortedCosts[i] << std::endl;
    }
    std::cout << std::endl;

    // print without numbers
    for (auto item : sortedCosts) {       // "auto" -> Compiler soll Inhalt erraten/bestimmen, ":" -> sozusagen forEach (range-based loop)
        std::cout << item << std::endl;
    }
}
