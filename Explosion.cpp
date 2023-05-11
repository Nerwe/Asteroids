#include "Explosion.h"

Explosion::Explosion()
{
    setName("Explosion");
}

void Explosion::Update()
{
    setX(getX() + getDx());
    setY(getY() + getDy());

    if (getX() > W) setX(0);
    if (getX() < 0) setX(W);

    if (getY() > H) setY(0);
    if (getY() < 0) setY(H);
}