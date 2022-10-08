//
// Created by Simon on 19/04/2021.
//

#ifndef VORLESUNG_RECTFIELD_H
#define VORLESUNG_RECTFIELD_H

#include "includes.h"

class RectField {
private:
    static const unsigned cMaxElements = 100;
    Rectangle *pRectField[cMaxElements]{nullptr};
    unsigned anzElems{0};

public:
    // Constructor configuration
    RectField() = delete; // -> no default constructor
//    RectField(const RectField &) = default; // -> copy-constructor
    RectField(const RectField &orig); // -> copy-constructor
    RectField(RectField &&) = delete; // -> move-constructor --> Move to a new address
//    RectField &operator=(const RectField &) = default; // -> assignment operator
    RectField &operator=(const RectField &orig); // -> assignment operator
    RectField &operator=(RectField &&) = delete; // -> move-assignment
    Rectangle &operator[](unsigned int index) const; // Param is const by default since method is already const

    virtual ~RectField();

    explicit RectField(unsigned anzElems); // explicit: Konstruktor kann nicht automatisch aufgerufen werden in Copy-constructor

    Rectangle &get(unsigned index) const;

    void printOut() const;
};

#endif //VORLESUNG_RECTFIELD_H
