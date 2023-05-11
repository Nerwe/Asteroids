#include<SFML/Graphics.hpp>
#include<math.h>
#include<time.h>
#include<list>
#include<iostream>
#include "Entity.h"
#include "Explosion.h"
#include "Player.h"
#include "Bullet.h"
#include "Asteroid.h"
#include "Animation.h"
#include "Events.h"
#include "defines.h"

using namespace sf;

bool isCollide(Entity* a, Entity* b)
{
    return
        (b->getX() - a->getX()) * (b->getX() - a->getX()) +
        (b->getY() - a->getY()) * (b->getY() - a->getY()) <
        (a->getRadius() + b->getRadius()) * (a->getRadius() + b->getRadius());
}

int main()
{
    srand((unsigned)time(NULL));

    RenderWindow app(VideoMode(W, H), "Asteroids!");
    app.setFramerateLimit(60);

    Texture t1, t2, t3, t4, t5, t6, t7;
    t1.loadFromFile("images/spaceship.png");
    t2.loadFromFile("images/background.jpg");
    t3.loadFromFile("images/explosions/type_C.png");
    t4.loadFromFile("images/rock.png");
    t5.loadFromFile("images/fire_red.png");
    t6.loadFromFile("images/rock_small.png");
    t7.loadFromFile("images/explosions/type_B.png");

    t1.setSmooth(true);
    t2.setSmooth(true);

    Sprite background(t2);

    Animation sExplosion(t3, 0, 0, 256, 256, 48, 0.5);
    Animation sRock(t4, 0, 0, 64, 64, 16, 0.2);
    Animation sRock_small(t6, 0, 0, 64, 64, 16, 0.2);
    Animation sBullet(t5, 0, 0, 32, 64, 16, 0.8);
    Animation sPlayer(t1, 40, 0, 40, 40, 1, 0);
    Animation sPlayer_go(t1, 40, 40, 40, 40, 1, 0);
    Animation sExplosion_ship(t7, 0, 0, 192, 192, 64, 0.5);


    std::list<Entity*> entities;

    for (int i = 0; i < 5; i++)
    {
        Asteroid* a = new Asteroid();
        a->Settings(sRock, rand() % W, rand() % H, rand() % 360, 25);
        entities.push_back(a);
    }

    Player* p = new Player();
    p->Settings(sPlayer, W / 2, H / 2, 0, 20);
    entities.push_back(p);

    while (app.isOpen())
    {
        Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();

            if (event.type == Event::KeyPressed)
                if (event.key.code == Keyboard::Space)
                {
                    Bullet* b = new Bullet();
                    b->Settings(sBullet, p->getX(), p->getY(), p->getAngle(), 10);
                    entities.push_back(b);
                }
        }

        if (Keyboard::isKeyPressed(Keyboard::Right)) p->setAngle(p->getAngle() + 3);
        if (Keyboard::isKeyPressed(Keyboard::Left)) p->setAngle(p->getAngle() - 3);
        if (Keyboard::isKeyPressed(Keyboard::Up)) p->setThrust(true);
        else p->setThrust(false);

        for (auto& a : entities)
        {
            for (auto& b : entities)
            {
                if (a->getName() == "Asteroid" && b->getName() == "Bullet")
                {
                    if (isCollide(a, b))
                    {
                        a->setLife(false);
                        b->setLife(false);

                        Explosion* e = new Explosion();
                        e->Settings(sExplosion, a->getX(), a->getY(), 0, 1);
                        entities.push_back(e);


                        for (int i = 0; i < 2; i++)
                        {
                            if (a->getRadius() == 15) continue;
                            Entity* e = new Asteroid();
                            e->Settings(sRock_small, a->getX(), a->getY(), rand() % 360, 15);
                            entities.push_back(e);
                        }

                    }
                }

                else if (a->getName() == "Player" && b->getName() == "Asteroid")
                {
                    if (isCollide(a, b))
                    {
                        b->setLife(false);

                        Explosion* e = new Explosion();
                        e->Settings(sExplosion_ship, a->getX(), a->getY(), 0, 1);
                        entities.push_back(e);

                        p->Settings(sPlayer, W / 2, H / 2, 0, 20);
                        p->setDx(0);
                        p->setDy(0);
                    }
                }
            }
        }

        if (p->getThrust())
        {
            p->setAnim(sPlayer_go);
        }
        else
        {
            p->setAnim(sPlayer);
        }


        for (auto& e : entities)
        {
            if (e->getName() == "Explosion")
            {

                if (e->getAnim().isEnd())
                { 
                    e->setLife(0); 
                }
            }
        }

        if (rand() % 150 == 0)
        {
            Asteroid* a = new Asteroid();
            a->Settings(sRock, 0, rand() % H, rand() % 360, 25);
            entities.push_back(a);
        }

        for (auto i = entities.begin(); i != entities.end();)
        {
            Entity* e = *i;

            e->Update();
            e->getAnim().Update();

            if (e->getLife() == false)
            { 
                i = entities.erase(i);
                delete e;
            }
            else i++;
        }

        app.draw(background);
        for (auto& i : entities)
        {
            i->Draw(app);
        }
        app.display();
    }

    return 0;
}