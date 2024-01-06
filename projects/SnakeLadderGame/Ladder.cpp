#include "Ladder.h"

Ladder::Ladder(const Point& startingPoint, const Point& endingPoint) : mStartingPoint(startingPoint), mEndingPoint(endingPoint) {
    
}

bool Ladder::shouldAcend(int &finalX, int &finalY){
    if (mStartingPoint.getX() == finalX && mStartingPoint.getY() == finalY)
    {
        finalX = mEndingPoint.getX();
        finalY = mEndingPoint.getY();

        return true;
    }

    return false;
}