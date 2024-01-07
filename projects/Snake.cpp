#include "SLGame.h"
#include "Snake.h"

Snake::Snake(const Point&  startingPoint, const Point&  endingPoint) : mStartingPoint(startingPoint), mEndingPoint(endingPoint) {
}

bool Snake::shouldDecend(int &finalX, int &finalY){
    if (mEndingPoint.getX() == finalX && mEndingPoint.getY() == finalY)
    {
        finalX = mStartingPoint.getX();
        finalY = mStartingPoint.getY();

        return true;
    }
    
    return false;
}