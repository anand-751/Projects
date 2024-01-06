#include <iostream>
#include "SLGame.h"
#include "Snake.h"
#include "Ladder.h"
#include "Player.h"

int main(){

    int numOfPlayers = 0;
    std::cout << std::endl << "Enter number of players:";
    std::cin >> numOfPlayers;
    SLGame game(5, 5, numOfPlayers);
    game.play();


    return 0;
}