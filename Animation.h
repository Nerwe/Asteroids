#pragma once
#include<SFML/Graphics.hpp>

class Animation
{
private:
    float frame, speed;
    sf::Sprite sprite;
    std::vector<sf::IntRect> frames;
public:
    Animation();
    Animation(sf::Texture& t, int x, int y, int w, int h, int count, float speed);

    float getFrame();
    float getSpeed();
    sf::Sprite getSprite();
    std::vector<sf::IntRect> getFrames();

    void setFrame(float _frame);
    void setSpeed(float _speed);
    void setSprite(sf::Sprite _sprite);
    void setSpritePos(float _x, float _y);
    void setSpriteRot(float _angle);
    void setFrames(std::vector<sf::IntRect>& _frames);

    void Update();
    bool isEnd();
};