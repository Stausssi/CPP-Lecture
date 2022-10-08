//
// Created by Simon on 29/03/2021.
//
#include "Rectangle.h"

void rectangle() {
    // stack instance
    Rectangle rect(1, 1, 3, 4);
    rect.printOut();
    std::cout << std::endl << std::endl;

    // heap instances
    const int capacity = 10;
    Rectangle *rectArray[capacity];

    for (int i = 0; i < capacity; ++i) {
        rectArray[i] = new Rectangle(0, 0, i,
                                     i * 2); // new creates an instance on the heap and returns a pointer to the element
    }

    for (auto &i : rectArray) {
        i->printOut();
        std::cout << std::endl;
    }

    // manual garbage collection
    for (auto &i : rectArray) {
        delete i;
    }
}

// Streaming-Operator kann nicht als Methode überladen werden, sondern als Funktion
std::ostream &operator<<(std::ostream &os, const Rectangle &rect) {
    os << rect.toString();
    return os;
}

Rectangle::Rectangle(double x, double y, double width, double height) : x(x), y(y) {
    if (width < 0 || height < 0) {
        throw std::invalid_argument("Width and height must be a positive value!");
    }

    this->width = width;
    this->height = height;
}

Rectangle Rectangle::operator+(const Rectangle &rhs) const {
    // Kleinst mögliche Ausdehnung, die beide Rechtecke enthält
    const auto newX = std::min(this->x, rhs.x);
    const auto newY = std::max(this->y, rhs.y);

    const auto newWidth = std::abs(std::max(this->x + this->width, rhs.x + rhs.width) - newX);
    const auto newHeight = std::abs(std::min(this->y - this->height, rhs.y - rhs.height) - newY);

    return {newX, newY, newWidth, newHeight}; // identisch: Rectangle(newX, newY, newWidth, newHeight)
}

void Rectangle::setPos(double xPos, double yPos) {
    this->x = xPos;    // "this" is a pointer - therefore use "->"
    this->y = yPos;
}

void Rectangle::setDim(double widthDim, double heightDim) {
    this->width = widthDim;
    this->height = heightDim;
}

double Rectangle::getArea() const {
    return width * height;
}

void Rectangle::printOut() const {
    std::cout << toString();
}

std::string Rectangle::toString() const {
    return "(" + std::to_string(x) + "|" + std::to_string(y) + ") - (" + std::to_string(width) + "|" +
           std::to_string(height) + ") - Area: " + std::to_string(getArea());
}
