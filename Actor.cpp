#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file (if you wish), Actor.h, StudentWorld.h, and StudentWorld.cpp



Actor::Actor(int i_d, int x, int y)
:GraphObject(i_d, x, y)
{
    setVisible(true);
}

Actor::~Actor()
{
    
}


Player::Player(int i_d, int x, int y, StudentWorld* gw)
:Actor(IID_PLAYER, x, y)
{
    m_getWorld = gw;
}

Player::~Player()
{
    
}

void Player::doSomething()
{
    bool alive = true;
    
    if (!alive)
        return;
    
    int ch;
    if (m_getWorld->getKey(ch))
    {
        // user hit a key this tick!
        switch (ch)
        {
            case KEY_PRESS_LEFT:
                if (m_getWorld->getContent(getX()-1, getY()) == IID_DESTROYABLE_BRICK || m_getWorld->getContent(getX()-1, getY()) == IID_PERMA_BRICK)
                    return;
                else
                    moveTo(getX()-1, getY());
                break;
            case KEY_PRESS_RIGHT:
                if (m_getWorld->getContent(getX()+1, getY()) == IID_DESTROYABLE_BRICK || m_getWorld->getContent(getX()+1, getY()) == IID_PERMA_BRICK)
                    return;
                else
                    moveTo(getX()+1, getY());
                break;
            case KEY_PRESS_DOWN:
                if (m_getWorld->getContent(getX(), getY()-1) == IID_DESTROYABLE_BRICK || m_getWorld->getContent(getX(), getY()-1) == IID_PERMA_BRICK)
                    return;
                else
                    moveTo(getX(), getY()-1);
                break;
            case KEY_PRESS_UP:
                if (m_getWorld->getContent(getX(), getY()+1) == IID_DESTROYABLE_BRICK || m_getWorld->getContent(getX(), getY()+1) == IID_PERMA_BRICK)
                    return;
                else
                    moveTo(getX(), getY()+1);
                break;
            case KEY_PRESS_SPACE:
                //... drop a Bug Sprayer in the current square ...;
                break;
        }
    }
}

destroyableBricks::destroyableBricks(int i_d, int x, int y)
:Actor(IID_DESTROYABLE_BRICK, x, y)
{
    
}

destroyableBricks::~destroyableBricks()
{
    
}

permBricks::permBricks(int i_d, int x, int y)
:Actor(IID_PERMA_BRICK, x, y)
{
    
}

permBricks::~permBricks()
{
    
}















