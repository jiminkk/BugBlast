#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include <sstream>
#include "GameWorld.h"
#include "GameConstants.h"
#include "Level.h"
#include "Actor.h"
#include <vector>
#include <string>
using namespace std;

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp

class Actor;
class Player;
class permBricks;
class destroyableBricks;



class StudentWorld : public GameWorld
{
public:

	virtual int init();      //load level

	virtual int move();

	virtual void cleanUp();
    
    virtual ~StudentWorld();
    
    int getContent(int x, int y) const
    {
        if (lev.getContentsOf(x, y) == Level::player)
        {
            return IID_PLAYER;
        }
        else if(lev.getContentsOf(x, y) == Level::perma_brick)
        {
            return IID_PERMA_BRICK;
        }
        else if (lev.getContentsOf(x, y) == Level::destroyable_brick)
        {
            return IID_DESTROYABLE_BRICK;
        }
        return -1;
    }

private:
    Player* m_player;
    Actor* pBrick;
    Actor* dBrick;
    vector<Actor*> actors;
    Level lev;
};

#endif // STUDENTWORLD_H_
