//
// Created by Simon on 19/04/2021.
//
#include "RectField.h"

void rectField() {
    auto *pRect1 = new Rectangle(-4, 9, 6, 5);
    auto *pRect2 = new Rectangle(1, 6, 5, 7);
    auto * pRect3 = new Rectangle(*pRect1 + *pRect2);

//    std::cout << "pRect1: ";
//    pRect1->printOut();
//    std::cout << std::endl;
//
//    std::cout << "pRect2: ";
//    pRect2->printOut();
//    std::cout << std::endl;
//
//    std::cout << "pRect3: ";
//    pRect3->printOut();
//    std::cout << std::endl;

    std::cout << "pRect1: " << *pRect1 << std::endl;
    std::cout << "pRect2: " << *pRect2 << std::endl;
    std::cout << "pRect3: " << *pRect3 << std::endl;

    auto *pOrig = new RectField(5);
    auto *pCopy1 = new RectField(*pOrig);
    auto *pCopy2 = new RectField(5);

    *pCopy2 = *pOrig;

    pOrig->get(2).setPos(1, 1);
    (*pOrig)[3].setPos(1, 1);

    std::cout << "Original" << std::endl;
    pOrig->printOut();

    std::cout << std::endl;
    std::cout << "Copy 1 (constructor)" << std::endl;
    pCopy1->printOut();

    std::cout << std::endl;
    std::cout << "Copy 2 (assignment operator)" << std::endl;
    pCopy2->printOut();

    delete pOrig;
    delete pCopy1;
    delete pCopy2;
}

RectField::RectField(const unsigned int anzElems) {
    for (unsigned int i = 0; i < anzElems; ++i) {
        pRectField[i] = new Rectangle();
    }

    this->anzElems = anzElems;
}

RectField::RectField(const RectField &orig) {
    // Weder Referenz noch Zeiger
    anzElems = orig.anzElems;

    // Zeiger
    for (int i = 0; i < anzElems; ++i) {
        pRectField[i] = new Rectangle(*(orig.pRectField[i]));
    }
}

RectField::~RectField() {
    for (unsigned i = 0; i < anzElems; ++i) {
        delete pRectField[i];
    }
}

RectField &RectField::operator=(const RectField &orig) {
    // Self assignment
    if (this == &orig) {
        return *this;
    }
    // cleanup
    for (unsigned int i = 0; i < anzElems; ++i) {
        delete pRectField[i];
    }

    // Weder Referenz noch Zeiger
    anzElems = orig.anzElems;

    // Zeiger
    for (int i = 0; i < anzElems; ++i) {
        pRectField[i] = new Rectangle(*(orig.pRectField[i]));
    }

    return *this;
}

Rectangle &RectField::operator[](const unsigned int index) const {
    return get(index);
}

Rectangle &RectField::get(unsigned int index) const {
    if (index >= anzElems) {
        throw std::out_of_range("Wrong index");
    }

    return *pRectField[index];
}

void RectField::printOut() const {
    for (unsigned int i = 0; i < anzElems; ++i) {
        pRectField[i]->printOut();
        std::cout << std::endl;
    }
}
