#include "position.h"
position::position()
{
    mX = 0;
    mY = 0;
}

position::position(int x, int y)
{
    mX = x;
    mY = y;
}

position::~position()
{
    //dtor
}

void position::afficher()
{
    cout << "X:" << mX << " Y:" << mY << endl;
}

void position::setX(int x)
{
    mX = x;
}

void position::setY(int y)
{
    mY = y;
}

void position::setCoords(int x, int y)
{
    setX(x); // ou mX = x;
    mY = y;
}

int position::getX()
{
    return mX;
}

int position::getY()
{
    return mY;
}
