#pragma once
#include "Point.h"

class Ladder {
    private:

        Point mStartingPoint;
        Point mEndingPoint;
    public:

        Ladder(const Point &startingPoint, const Point &endingPoint);

        bool shouldAcend(int &finalX, int &finalY);

};

