#include "Bullet.h"

Bullet::Bullet()
{
    setName("Bullet");
}

void Bullet::Update()
{
    setDx(cos(getAngle() * DEGTORAD) * 6);
    setDy(sin(getAngle() * DEGTORAD) * 6);
    // angle+=rand()%7-3;  /*try this*/
    setX(getX() + getDx());
    setY(getY() + getDy());

    if (getX() > W || getX() < 0 || getY() > H || getY() < 0) setLife(0);
}