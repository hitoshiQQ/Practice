#pragma once
#include "Coordinate.h"
class Windows;

class Coordinate;

class Display {
    int w = 80;
    int h = 50;
    Coordinate size;
    bool display[50][80];


public:
    const Coordinate* getSize() { 
        return &size;
    }
    const int getWidth() {
        return w; 
    }
    const int getHeight() {
        return h;
    }


    void clear() {
        size.setXY(w, h);
        for (int j = 0; j < 50; ++j)
            for (int i = 0; i < 80; ++i) {
                display[j][i] = false;
            }
    }
    void windowsLocation(Coordinate* c1, Coordinate* c2) {
        clear();
        Coordinate current;
        current.setXY(0, 0);
        for (int j = 0; j < 50; ++j) {
            current.setY(j);
            for (int i = 0; i < 80; ++i) {
                current.setX(i);
                display[j][i] = Coordinate::coordinateInRectangle(c1, c2, &current);
            }
        }
    }
    void show() {

        for (int j = 0; j < 50; ++j) {
            for (int i = 0; i < 80; ++i) {
                std::cout << (display[j][i] ? "1" : "0");
            }
            std::cout << std::endl;
        }
    }
};