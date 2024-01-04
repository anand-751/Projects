#pragma once
#include <vector>
#include "Snake.h"
#include "Ladder.h"
#include "Player.h"

class SLGame{
    private:

        std::vector<int> mSnakes;
        std::vector<int> mLadders;
        std::vector<int> mPlayers;     

    public:
        SLGame(int numSnakes, int numLadders, int numPlayers);

   
};

