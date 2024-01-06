#pragma once
#include "Point.h"

class Player {
    private:
        Point mPos; 

    public:
        Player(const Point &pos);
        bool move(int numberOfSteps, int &finalX, int &finalY);

        void setPos(int x,int y);

};

