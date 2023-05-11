#pragma once
#include "Events.h"
bool Events::isCollide(Entity* a, Entity* b)
{
    return 
        (b->getX() - a->getX()) * (b->getX() - a->getX()) +
        (b->getY() - a->getY()) * (b->getY() - a->getY()) <
        (a->getRadius() + b->getRadius()) * (a->getRadius() + b->getRadius());
}