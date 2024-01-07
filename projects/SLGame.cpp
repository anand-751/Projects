#include "SLGame.h"
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <unistd.h>
#include <random>

int generateRandomNumber(int min, int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(min,max);
    int randomNumber = distribution(gen);
    return randomNumber;
}

SLGame::SLGame(int numSnakes, int numLadders, int numPlayers) {

    //Number of Ladders on the board with initialisation 

    Ladder ladder(Point(2, 1), Point(3, 3));
    mLadders.push_back(ladder);

    Ladder ladder1(Point(7, 3), Point(7, 6));
    mLadders.push_back(ladder1);

    Ladder ladder2(Point(4, 5), Point(6, 7));
    mLadders.push_back(ladder2);

    Ladder ladder3(Point(7, 8), Point(9, 10));
    mLadders.push_back(ladder3);

    Ladder ladder4(Point(3, 7), Point(2, 10));
    mLadders.push_back(ladder4);

   // Number of Snakes on the board with initialisation 

    Snake snake(Point(3, 1), Point(6, 5));
    mSnakes.push_back(snake);

    Snake snake1(Point(10, 1), Point(9, 5));
    mSnakes.push_back(snake1);

    Snake snake2(Point(8, 4), Point(6, 7));
    mSnakes.push_back(snake2);

    Snake snake3(Point(8, 7), Point(10, 10));
    mSnakes.push_back(snake3);

    Snake snake4(Point(4, 8), Point(3, 9));
    mSnakes.push_back(snake4);
   
    for (int i = 0;i <  numPlayers; ++i) {    
        Player player(Point(0,1), i+1);
        mPlayers.push_back(player);
    }
}

void SLGame::play()
{
    while(mPlayers.size() > 0){
        

        for (int i = 0; i < mPlayers.size(); i++)
        {
            int dicePos = generateRandomNumber(1,6);
            std::cout << std::endl << "Player " << mPlayers[i].getID() << ", ";
            int finalX = 0 , finalY = 0; 
            bool won = mPlayers[i].move(dicePos,finalX,finalY);

            for (int j = 0; j < mLadders.size(); j++)
            {
                bool temp = mLadders[j].shouldAcend(finalX,finalY);

                if (temp)
                {
                    std::cout << std::endl << "accended" << std::endl;
                    break;
                }
                
            }
            
            for (int j = 0; j < mSnakes.size(); j++)
            {
                bool temp = mSnakes[j].shouldDecend(finalX,finalY);

                if (temp)
                {
                    std::cout << std::endl << "decended" << std::endl;

                    break;
                }
                
            }
            

            mPlayers[i].setPos(finalX, finalY);

            std::cout<<"Dice number = " << dicePos << " ,Final Position = "<< finalX << ", " << finalY; 
    
          

            if (won)
            {
                std::cout << std::endl << "Player " << mPlayers[i].getID() << " won. Remaining number of players=> " << mPlayers.size()-1;
                mPlayers.erase(mPlayers.begin() + i);
            }            
        }
        
    }
}