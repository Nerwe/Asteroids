#include "Entity.h"

Entity::Entity()
{
    this->life = true;
}

float Entity::getX() { return this->x; }
float Entity::getY() { return this->y; }
float Entity::getDx() { return this->dx; }
float Entity::getDy() { return this->dy; }
float Entity::getRadius() { return this->radius; }
float Entity::getAngle() { return this->angle; }
bool Entity::getLife() { return this->life; }
std::string Entity::getName() { return this->name; }
Animation& Entity::getAnim() { return this->anim; }

void Entity::setX(float _x) { this->x = _x; }
void Entity::setY(float _y) { this->y = _y; }
void Entity::setDx(float _dx) { this->dx = _dx; }
void Entity::setDy(float _dy) { this->dy = _dy; }
void Entity::setRadius(float _radius) { this->radius = _radius; }
void Entity::setAngle(float _angle) { this->angle = _angle; }
void Entity::setLife(bool _life) { this->life = _life; }
void Entity::setName(std::string _name) { this->name = _name; }
void Entity::setAnim(Animation _anim) { this->anim = _anim; }

void Entity::Settings(Animation& _anim, int _x, int _y, float _angle, int _radius)
{
    this->anim = _anim;
    this->x = _x;
    this->y = _y;
    this->angle = _angle;
    this->radius = _radius;
}

void Entity::Update() {};

void Entity::Draw(sf::RenderWindow& app)
{
    anim.setSpritePos(this->x, this->y);
    anim.setSpriteRot(this->angle + 90);
    app.draw(this->anim.getSprite());

    sf::CircleShape circle(this->radius);
    circle.setFillColor(sf::Color(255, 0, 0, 170));
    circle.setPosition(this->x, this->y);
    circle.setOrigin(this->radius, this->radius);
    //app.draw(circle);
}

Entity::~Entity() {};