#pragma once
#include <vector>
#include "Snake.h"
#include "Ladder.h"
#include "Player.h"

class SLGame{
    private:

        std::vector<Snake> mSnakes;
        std::vector<Ladder> mLadders;
        std::vector<Player> mPlayers;     

    public:

        SLGame(int numSnakes, int numLadders, int numPlayers);
        void play();
  
};

