#include "tools.h"

int myRand(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}
