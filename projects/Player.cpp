#include "Player.h"
#include <cstdlib>
#include <iostream>


Player::Player(const Point &pos, int id) : mPos(pos), mID(id)
{
}

int Player::getID() const { return mID; }

void Player::setPos(int x,int y){
    mPos.setX(x);
    mPos.setY(y);
}


bool Player::move(int numberOfSteps,int &finalX,int &finalY)
{
    bool won = false;
    int initialX = mPos.getX();
    int initialY = mPos.getY();
    finalX = initialX;
    finalY = initialY;

    if (initialY % 2 == 1) // odd...
    {
        if ((initialX + numberOfSteps) > 10)
        {
            finalX = 11 - ((initialX + numberOfSteps) % 10);
            finalY++;
        }
        else {
            finalX = initialX + numberOfSteps;
        }
    }
    else // even...
    {
        if (finalY == 10)
        {
            if ((initialX - numberOfSteps) >=1) {
                finalX = initialX - numberOfSteps;
            }
        }
        else
        {
            
            if ((initialX - numberOfSteps) < 0)
            {
                finalX = abs(initialX - numberOfSteps)+1;
                finalY++;
            }
            else {
                finalX = abs(initialX - numberOfSteps);

            }
        }
    }

    if (finalX == 1 && finalY == 10)
    {
        won = true;
    }

    return won;
}
