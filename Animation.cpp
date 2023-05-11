#include "Animation.h"

Animation::Animation() {}

Animation::Animation(sf::Texture& t, int x, int y, int w, int h, int count, float speed)
{
    this->frame = 0;
    this->speed = speed;

    for (int i = 0; i < count; i++)
    {
        this->frames.push_back(sf::IntRect(x + i * w, y, w, h));
    }

    this->sprite.setTexture(t);
    this->sprite.setOrigin(w / 2, h / 2);
    this->sprite.setTextureRect(this->frames[0]);
}

float Animation::getFrame() { return this->frame; }
float Animation::getSpeed() { return this->speed; }
sf::Sprite Animation::getSprite() { return this->sprite; }
std::vector<sf::IntRect> Animation::getFrames() { return this->frames; }

void Animation::setFrame(float _frame) { this->frame = _frame; }
void Animation::setSpeed(float _speed) { this->speed = _speed; }
void Animation::setSprite(sf::Sprite _sprite) { this->sprite = _sprite; }
void Animation::setSpritePos(float _x, float _y) { this->sprite.setPosition(_x, _y); }
void Animation::setSpriteRot(float angle) { this->sprite.setRotation(angle); }
void Animation::setFrames(std::vector<sf::IntRect>& _frames) { this->frames = _frames; }

void Animation::Update()
{
    this->frame += this->speed;
    int n = this->frames.size();
    if (this->frame >= n)
    {
        this->frame -= n;
    }
    if (n > 0)
    {
        this->sprite.setTextureRect(this->frames[int(this->frame)]);
    }
}

bool Animation::isEnd()
{
    return this->frame + this->speed >= this->frames.size();
}