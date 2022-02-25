#include "CSnake.hpp"

int main()
{
    std::unique_ptr<CSnake> s = std::make_unique<CSnake>(30, 50);
    s->vInitialize();

    while (!s->bIsGameEnd())
    {
        s->vBoundary();
        s->vControl();
        s->vMovement();
        s->vDrawDataPoints();
        usleep(100000);
        // s->vtest();
    }

    return 0;
}