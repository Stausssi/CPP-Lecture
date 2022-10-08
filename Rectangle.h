//
// Created by Simon on 29/03/2021.
//

#ifndef VORLESUNG_RECTANGLE_H
#define VORLESUNG_RECTANGLE_H

#include "includes.h"

class Rectangle {
private:
    double x{0};        // -> Init variables with specified default value (0)
    double y{0};

    double width{0};
    double height{0};

public:
    Rectangle() = default;  // -> create default constructor, opposite: delete
    Rectangle(double x, double y, double width,
              double height); /* : x(x), y(y), width(width), height(height) {};*/   // No code needed, init is done by x(x). Cant be used in regular methods

    Rectangle operator+(const Rectangle &rhs) const; // rhs = "right hand side", also rechts vom Operator;
    void setPos(double x, double y);

    void setDim(double widthDim, double heightDim);

    double getArea() const;     // const: Darf nicht auf den Attributbereich schreiben
    void printOut() const;

    friend std::ostream& operator<<(std::ostream& os, const Rectangle& rect); // friend darf auf private zugreifen

    std::string toString() const;
};

#endif //VORLESUNG_RECTANGLE_H
