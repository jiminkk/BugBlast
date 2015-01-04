#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
#include "GameConstants.h"
#include "StudentWorld.h"

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp
class StudentWorld;

class Actor: public GraphObject
{
public:
    Actor(int i_d, int x, int y);
    
    virtual ~Actor();
    
    //StudentWorld* getWorld();
};


class Player: public Actor
{
public:
    Player(int i_d, int x, int y, StudentWorld* gw);
    
    virtual ~Player();
    
    void doSomething();
    
private:
    StudentWorld* m_getWorld;
};


class destroyableBricks : public Actor
{
public:
    destroyableBricks(int i_d, int x, int y);
    
    virtual ~destroyableBricks();
    
};


class permBricks : public Actor
{
public:
    permBricks(int i_d, int x, int y);
    
    virtual ~permBricks();
    
};

/*
class SimpleZumi
{
    
};


class ComplexZumi
{
    
};


class BugSprayers
{
    
};


class BugSpray
{
    
};


class ExtraLife
{
    
};


class WalkThroughWalls
{
    
};


class IncreaseBugSpray
{
    
};
*/


/*
class Exit
{
    
};
*/





















#endif // ACTOR_H_
