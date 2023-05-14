#pragma once
#include <iostream>
#include "Coordinate.h"
#include "Display.h"


class Window {
    int h = 0;
    int w = 0;
    Coordinate crd[2];
    Display display;
    Coordinate size;
public:
    void init() {
        crd[0].setXY(10, 10);
        setHeight(20);
        setWidth(30);
        display.windowsLocation(&crd[0], &crd[1]);
    }
    const Coordinate* getSize() {
        return &size; 
    }

    void setHeight(int _h) {
        size.setY((_h < 0 ? 0 : _h));
        completeCoords();
    }
    void setWidth(int _w) {
        size.setX((_w < 0 ? 0 : _w));
        completeCoords();
    }

    enum Command {
        MOVE,
        RESIZE,
        DISPLAY,
        CLOSE,
        NONE
    };
    enum Command command = NONE;

    void getCommand() {
        std::string enter;
        std::cout << "Enter command[move,resize,display,close]: ";
        std::cin >> enter;
        if (enter == "move") {
            command = MOVE;
        }else if (enter == "resize") {
            command = RESIZE;
        }else if (enter == "display") {
            command = DISPLAY;
        }else if (enter == "close") {
            command = CLOSE;
        }
    }

    bool move(Coordinate* vector) {
        Coordinate _crd[2];
        _crd[0].copy(&crd[0]);
        _crd[1].copy(&crd[1]);
        for (int j = 0; j < 2; ++j) {
            _crd[j].copy(&crd[j]);
            _crd[j].move(vector);
            if (!Coordinate::coordinateOnDisplay(&_crd[j], display.getSize())) {
                return false;
            }
               
        }
        for (int j = 0; j < 2; ++j)
            crd[j].copy(&_crd[j]);
        return true;
    }
   
    bool resize() {
        Coordinate _size;
        Coordinate _cr;
        _size.setXY(Coordinate::enterInt("Input Width:"),
            Coordinate::enterInt("Input Height:"));
        _cr.copy(&crd[0]);
        _cr.move(&_size);
        if (Coordinate::coordinateOnDisplay(&_cr, display.getSize())) {
            size.copy(&_size);
            completeCoords();
            return true;
        }
        return false;
    }

    void show() {
        display.windowsLocation(&crd[0], &crd[1]);
        display.show();
    }
    void completeCoords() {
        crd[1].copy(&crd[0]);
        crd[1].move(&size);
    }

    void processWindow() {
        while (command == NONE) {
            getCommand();
            switch (command) {
            case MOVE: {
                Coordinate vector;
                vector.enterCoordinate();
                std::cout << (move(&vector) ? "" : "\t\t!Can't move out of screen!\n"); }
                break;
    
            case RESIZE: {
                std::cout << (resize() ? "" : "\t\t!Can't move out of screen!\n");
                break;
            }   
            case DISPLAY: {
                show();
                break;
            }     
            case CLOSE: {
                return;
            }
            case NONE: {
                continue;
            }
            default:
                break;
            }
            command = NONE;
        };   
    }
};