#pragma once
#include "Point.h"

class Snake {
private:
    Point  mStartingPoint;
    Point  mEndingPoint;

public:
    Snake(const Point &startingPoint, const Point &endingPoint);

    bool shouldDecend(int &finalX, int &finalY);

};


