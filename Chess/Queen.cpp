//
// Created by rasyt on 12/22/2021.
//

#include "Queen.h"


//correct
std::vector<std::pair<int,int>>& Chess::Queen::getpossiblemoves() {
    return possiblemoves;
}


//correct
std::vector<std::pair<int, int>> Chess::Queen::getpossiblemovescpy() {
    return possiblemovescpy;
}


//correct
bool Chess::Queen::GenerateMoves(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {
    Rook rookmethod(startposx, startposy, endposx, endposy);
    Bishop bishopmethod(startposx, startposy, endposx, endposy);
    bishopmethod.GenerateMoves(underboard, thepieces, color);
    rookmethod.GenerateMoves(underboard, thepieces, color);
    if (bishopmethod.getstaredown() or rookmethod.getstaredown())
    {
        starekingdown = true;
    }
    for (auto moves : rookmethod.getpossiblemoves())
    {
        bishopmethod.getpossiblemoves().push_back(moves);
    }
    possiblemoves = bishopmethod.getpossiblemoves();
}


bool Chess::Queen::getstaredown() {
    return starekingdown;
}
