#pragma once

struct XYPoint {
    int x = 0;
    int y = 0;
};

void Scalpel(XYPoint xyBegin, XYPoint xyEnd);
void Hemostat(XYPoint xy);
void Tweezers(XYPoint xy);
void Suture(XYPoint xyBegin, XYPoint xyEnd);
bool Compare(XYPoint &xyPoint1,XYPoint &xyPoint2);