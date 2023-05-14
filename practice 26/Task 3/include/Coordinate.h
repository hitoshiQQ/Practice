#pragma once
#include <iostream>
#include "Validator.h"


class Coordinate {
    int x = 0, y = 0;

public:
    void setX(int _x) { 
        x = _x; 
    }
    void setY(int _y) {
        y = _y; 
    }
    const int X() const {
        return x; 
    }
    const int Y() const {
        return y;
    }
    void setXY(int _x, int _y) {
        setX(_x);
        setY(_y);
    }

    void copy(Coordinate* _crd) {
        setXY(_crd->X(), _crd->Y());
    }
    void move(Coordinate* vec) {
        x += vec->x;
        y += vec->y;
    }

    static int enterInt(std::string str) {
        std::string enter = " ";
        bool notNumber = true;
        while (notNumber) {
            std::cout << str;
            std::cin >> enter;
            notNumber = !Validator::checkNumInt(enter);
            if (notNumber)std::cout << "Incorrect input.Try again\n" << std::endl;
            else break;
        }
        return std::stoi(enter);
    }
    void enterCoordinate() {
        x = enterInt("Enter X:");
        y = enterInt("Enter Y:");
    }
    static bool coordinateOnDisplay(const Coordinate* coord, const Coordinate* size) {
        if (coord->x < 0 || coord->y < 0) {
            return false;
        }
        if (size->X() < coord->x && size->Y() < coord->y) {
            return false;
        }
        return true;
    }
    static bool coordinateInRectangle(Coordinate* c1, Coordinate* c2, Coordinate* crd) {
        int maxX, minX, maxY, minY, X, Y;
        X = crd->X();
        Y = crd->Y();
        if (c1->X() > c2->X()) {
            maxX = c1->X(); 
            minX = c2->X();
        }
        else {
            maxX = c2->X();
            minX = c1->X();
        }

        if (c1->Y() > c2->Y()) {
            maxY = c1->Y();
            minY = c2->Y();
        }
        else {
            maxY = c2->Y(); minY = c1->Y();
        }
        return (X <= maxX && X >= minX) && (Y <= maxY && Y >= minY);
    }
};