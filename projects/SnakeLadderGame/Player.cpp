#include "Player.h"

Player::Player() : mPos(1) { 
}

int Player::getPosition() const {
    return mPos;
}

void Player::setPosition(int position) {
    mPos = position;
}


