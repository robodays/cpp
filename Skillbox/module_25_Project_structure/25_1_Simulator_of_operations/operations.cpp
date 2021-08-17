#include "operations.h"
#include <iostream>
#include <tuple>

void Scalpel(XYPoint xyBegin, XYPoint xyEnd) {
    std::cout << "Operation scalpel from {" << xyBegin.x << ";" << xyBegin.y << "} to {"
    << xyEnd.x << ";" << xyEnd.y << "}" << std::endl;
}

void Hemostat(XYPoint xy) {
    std::cout << "Operation hemostat {" << xy.x << ";" << xy.y << "}" << std::endl;
}

void Tweezers(XYPoint xy) {
    std::cout << "Operation tweezers {" << xy.x << ";" << xy.y << "}" << std::endl;
}

void Suture(XYPoint xyBegin, XYPoint xyEnd) {
    std::cout << "Operation suture from {" << xyBegin.x << ";" << xyBegin.y << "} to {"
    << xyEnd.x << ";" << xyEnd.y << "}" << std::endl;
}

bool Compare(XYPoint &xyPoint1,XYPoint &xyPoint2) {
    return std::tie(xyPoint1.x,xyPoint1.y) == std::tie(xyPoint2.x,xyPoint2.y);
}
