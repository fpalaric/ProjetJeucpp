#pragma once
#include <iostream>
using namespace std;

class position
{
public:
    position();
    position(int x, int y);
    ~position();
    void afficher();
    //setters
    void setX(int x);
    void setY(int y);
    void setCoords(int x, int y);
    //getters
    int getX();
    int getY();

protected:

private:
    int mX;
    int mY;
};

