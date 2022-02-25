#ifndef CSNAKE_HPP
#define CSNAKE_HPP

#include <iostream>
#include <stdlib.h>
#include "kbhit.hpp"
#include <memory>
#include <unistd.h>
#include "IData.hpp"
#include <vector>

class CSnake
{
private:
    int m_iHeight, m_iWidth, m_iScore = 0;
    std::pair<int, int> m_pairFoodLocation, m_pairCurrentLocation;
    int m_iPrevPosX, m_iPrevPosY;
    bool m_bGameEnded;

    std::vector<std::pair<int, int>> m_vecSnake;
    std::vector<std::vector<char>> m_vecDrawingPoints2D;

    std::unique_ptr<keyboard> m_uniquePtrKeyboard;
    eDIRECTION m_eCurrentDir;

public:
    CSnake(int, int);
    ~CSnake();

    bool bIsGameEnd();
    void vInitialize();
    void vControl();
    void vBoundary();
    void vMovement();
    void vIsGameOver();
    void vGetFood();
    void vNoBoundary();
    void vTail();
    void vDrawDataPoints();
};

#endif
