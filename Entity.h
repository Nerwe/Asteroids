#pragma once
#include <string>
#include "Animation.h"
#include "defines.h"

class Entity
{
private:
    float x, y, dx, dy, radius, angle;
    bool life;
    std::string name;
public:
    Animation anim;
    Entity();
    virtual ~Entity();

    float getX();
    float getY();
    float getDx();
    float getDy();
    float getRadius();
    float getAngle();
    bool getLife();
    std::string getName();
    Animation& getAnim();

    void setX(float _x);
    void setY(float _y);
    void setDx(float _dx);
    void setDy(float _dy);
    void setRadius(float _radius);
    void setAngle(float _angle);
    void setLife(bool _life);
    void setName(std::string _name);
    void setAnim(Animation _anim);

    void Settings(Animation& _anim, int _x, int _y, float _angle, int _radius);
    virtual void Update();
    void Draw(sf::RenderWindow& app);
};