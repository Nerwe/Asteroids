#include "Player.h"

Player::Player()
{
    setName("Player");
}

bool Player::getThrust() { return this->thrust; }
void Player::setThrust(bool _trust) { this->thrust = _trust; }

void Player::Update()
{
    if (thrust)
    {
        setDx(getDx() + cos(getAngle() * DEGTORAD) * 0.2);
        setDy(getDy() + sin(getAngle() * DEGTORAD) * 0.2);
    }
    else
    {
        setDx(getDx() * 0.99);
        setDy(getDy() * 0.99);
    }

    int maxSpeed = 15;
    float speed = sqrt(getDx() * getDx() + getDy() * getDy());
    if (speed > maxSpeed)
    {
        setDx(getDx() * maxSpeed / speed);
        setDy(getDy() * maxSpeed / speed);
    }

    setX(getX() + getDx());
    setY(getY() + getDy());

    if (getX() > W) setX(0);
    if (getX() < 0) setX(W);

    if (getY() > H) setY(0);
    if (getY() < 0) setY(H);
}