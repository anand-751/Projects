#pragma once
#include "Point.h"

class Player {
    private:
        Point mPos;
        int mID;

    public:
        Player(const Point &pos, int id);
        int getID() const;
        bool move(int numberOfSteps, int &finalX, int &finalY);

        void setPos(int x,int y);

};

