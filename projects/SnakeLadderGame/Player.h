#pragma once
#include "Point.h"

class Player {
    private:
        int mPos; 

    public:
        Player();

        int getPosition() const;

        void setPosition(int position);

};

