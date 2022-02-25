#include "CSnake.hpp"

CSnake::CSnake(int Height, int Width)
{
    m_iHeight = Height;
    m_iWidth = Width;

    m_uniquePtrKeyboard = std::make_unique<keyboard>();
}

CSnake::~CSnake()
{
}

bool CSnake::bIsGameEnd()
{
    return m_bGameEnded;
}

void CSnake::vGetFood()
{
    m_pairFoodLocation.first = rand() % m_iHeight;
    m_pairFoodLocation.second = rand() % m_iWidth;

    if (m_pairFoodLocation.first == 0 || m_pairFoodLocation.second == 0 || m_pairFoodLocation.first >= m_iHeight - 1 || m_pairFoodLocation.second >= m_iWidth - 1)
        vGetFood();
}

void CSnake::vInitialize()
{
    m_bGameEnded = false;

    m_pairCurrentLocation.first = m_iHeight / 2;
    m_pairCurrentLocation.second = m_iWidth / 2;

    m_vecSnake.push_back({m_pairCurrentLocation.first, m_pairCurrentLocation.second});

    vGetFood();
}

void CSnake::vControl()
{
    char cmd;
    if (m_uniquePtrKeyboard->kbhit())
    {
        cmd = static_cast<char>(m_uniquePtrKeyboard->getch());
        switch (cmd)
        {
        case Control::UP:
            m_eCurrentDir = eDIRECTION::UP;
            // std::cout << "UP" << std::endl;
            break;

        case Control::DOWN:
            m_eCurrentDir = eDIRECTION::DOWN;
            // std::cout << "DOWN" << std::endl;
            break;

        case Control::LEFT:
            m_eCurrentDir = eDIRECTION::LEFT;
            // std::cout << "LEFT" << std::endl;
            break;

        case Control::RIGHT:
            m_eCurrentDir = eDIRECTION::RIGHT;
            // std::cout << "RIGHT" << std::endl;
            break;

        case Control::QUIT:
            m_eCurrentDir = eDIRECTION::QUIT;
            // std::cout << "QUIT" << std::endl;
            break;

        default:
            break;
        }
    }
}

void CSnake::vIsGameOver()
{
    if (m_pairCurrentLocation.first <= 0 || m_pairCurrentLocation.second <= 0 || m_pairCurrentLocation.first >= m_iHeight || m_pairCurrentLocation.second >= m_iWidth)
        m_bGameEnded = true;
}

void CSnake::vNoBoundary()
{
    for (int i = 1; i < m_vecSnake.size(); i++)
        if (m_vecSnake[i].first == m_pairCurrentLocation.first && m_vecSnake[i].second == m_pairCurrentLocation.second)
            m_bGameEnded = true;

    if (m_pairCurrentLocation.first <= 0)
        m_pairCurrentLocation.first = m_iHeight - 1;

    if (m_pairCurrentLocation.first >= m_iHeight)
        m_pairCurrentLocation.first = 0;

    if (m_pairCurrentLocation.second <= 0)
        m_pairCurrentLocation.second = m_iWidth - 1;

    if (m_pairCurrentLocation.second >= m_iWidth)
        m_pairCurrentLocation.second = 0;
}

void CSnake::vTail()
{
    int prevX = m_vecSnake[0].first;
    int prevY = m_vecSnake[0].second;
    int tempX, tempY;

    for (int i = 1; i <= m_vecSnake.size(); i++)
    {
        tempX = m_vecSnake[i].first;
        tempY = m_vecSnake[i].second;
        m_vecSnake[i].first = prevX;
        m_vecSnake[i].second = prevY;
        prevX = tempX;
        prevY = tempY;
    }
    m_vecSnake[0].first = m_pairCurrentLocation.first;
    m_vecSnake[0].second = m_pairCurrentLocation.second;
}

void CSnake::vMovement()
{
    switch (m_eCurrentDir)
    {
    case eDIRECTION::UP:
        m_pairCurrentLocation.first--;
        break;

    case eDIRECTION::DOWN:
        m_pairCurrentLocation.first++;
        break;

    case eDIRECTION::RIGHT:
        m_pairCurrentLocation.second++;
        break;

    case eDIRECTION::LEFT:
        m_pairCurrentLocation.second--;
        break;

    case eDIRECTION::QUIT:
        m_bGameEnded = true;
        break;

    default:
        break;
    }

    // vIsGameOver();
    vNoBoundary();

    if (!m_bGameEnded)
    {
        if (m_pairCurrentLocation.first == m_pairFoodLocation.first && m_pairCurrentLocation.second == m_pairFoodLocation.second)
        {
            m_vecSnake.push_back({m_pairCurrentLocation.first, m_pairCurrentLocation.second});

            m_iScore++;
            vGetFood();
        }
        if (m_vecSnake.size() > 0)
            vTail();
    }
}

void CSnake::vDrawDataPoints()
{
    for (auto vect1D : m_vecDrawingPoints2D)
    {
        for (char x : vect1D)
        {
            std::cout << x;
        }
    }

    std::cout << "Score : " << m_iScore * 10 << std::endl;
    std::cout << "To Quit --> Press q" << std::endl;

    m_vecDrawingPoints2D.clear();
}

void CSnake::vBoundary()
{
    system("clear");

    std::vector<char> temp;

    for (int i = 0; i < m_iHeight; i++)
    {
        for (int j = 0; j < m_iWidth; j++)
        {
            if (i == 0 || i == m_iHeight - 1 || j == m_iWidth - 1 || j == 0)
            {
                temp.push_back('H');
            }
            else if (i == m_pairCurrentLocation.first && j == m_pairCurrentLocation.second)
            {
                temp.push_back('O');
            }
            else if (i == m_pairFoodLocation.first && j == m_pairFoodLocation.second)
            {
                temp.push_back('F');
            }
            else
            {
                bool tailAdded = false;
                for (int k = 0; k < m_vecSnake.size(); k++)
                {
                    if (m_vecSnake[k].first == i && m_vecSnake[k].second == j)
                    {
                        tailAdded = true;
                        temp.push_back('o');
                    }
                }

                if (!tailAdded)
                {
                    temp.push_back(' ');
                }
            }
        }
        temp.push_back('\n');

        m_vecDrawingPoints2D.push_back(temp);
        temp.clear();
    }
}
