#include "StudentWorld.h"
#include "Level.h"
#include <vector>


using namespace std;

GameWorld* createStudentWorld()
{
	return new StudentWorld();
}


// Students:  Add code to this file (if you wish), StudentWorld.h, Actor.h and Actor.cpp

int StudentWorld::init()
{
    
    int level = getLevel();             // load level
    string curLevel = "";
    stringstream ss;
    Level::LoadResult result;
    
    
    switch (level)
    {
        case 0:
            result = lev.loadLevel("level00.dat");
            if	(result	==	Level::load_fail_file_not_found)
                return	GWSTATUS_NO_FIRST_LEVEL;
            else if	(result	==	Level::load_fail_bad_format)
                return	GWSTATUS_LEVEL_ERROR;
            break;
        case 1:
            result = lev.loadLevel("level01.dat");
            if	(result	==	Level::load_fail_file_not_found)
                return	GWSTATUS_PLAYER_WON;
            else if	(result	==	Level::load_fail_bad_format)
                return	GWSTATUS_LEVEL_ERROR;
            break;
        case 2:
            result = lev.loadLevel("level02.dat");
            if	(result	==	Level::load_fail_file_not_found)
                return	GWSTATUS_PLAYER_WON;
            else if	(result	==	Level::load_fail_bad_format)
                return	GWSTATUS_LEVEL_ERROR;
            break;
        case 3:
            result = lev.loadLevel("level03.dat");
            if	(result	==	Level::load_fail_file_not_found)
                return	GWSTATUS_PLAYER_WON;
            else if	(result	==	Level::load_fail_bad_format)
                return	GWSTATUS_LEVEL_ERROR;
            break;
        default:
            break;
    }
    
    
    /*
    if (level == 0)
    {
        ss << "level" << 0 << ".dat";
        curLevel = ss.str();
        result = lev.loadLevel("level00.dat");
        if	(result	==	Level::load_fail_file_not_found)
            return	GWSTATUS_NO_FIRST_LEVEL;
        else if	(result	==	Level::load_fail_bad_format)
            return	GWSTATUS_LEVEL_ERROR;
    }
    else
    {
        ss << "level" << 0 << level << ".dat";
        curLevel = ss.str();
        result = lev.loadLevel(curLevel);
        if	(result	==	Level::load_fail_file_not_found)
            return	GWSTATUS_PLAYER_WON;
        else if	(result	==	Level::load_fail_bad_format)
            return	GWSTATUS_LEVEL_ERROR;
    }
    */
    
    for (int x = 0; x < VIEW_WIDTH; x++)
    {
        for (int y = 0; y < VIEW_HEIGHT; y++)
        {
            if (lev.getContentsOf(x, y) == Level::player)
            {
                m_player = new Player(IID_PLAYER, x, y, this);
                actors.push_back(m_player);
            }
            else if(lev.getContentsOf(x, y) == Level::perma_brick)
            {
                //pBrick = new permBricks(IID_PERMA_BRICK, x, y);           // pointers getting messy.
                actors.push_back(new permBricks(IID_PERMA_BRICK, x, y));
            }
            else if (lev.getContentsOf(x, y) == Level::destroyable_brick)
            {
                //dBrick = new destroyableBricks(IID_DESTROYABLE_BRICK, x, y);
                actors.push_back(new destroyableBricks(IID_DESTROYABLE_BRICK, x, y));
            }
        }
    }
    
    return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move()
{
    // This code is here merely to allow the game to build, run, and terminate after hitting enter a few times
    //updateDisplayText(); // update the score/lives/level text at screen top
    
    //If player is still alive:
    m_player->doSomething();
    
    return GWSTATUS_CONTINUE_GAME;
}

void StudentWorld::cleanUp()
{
    while (!actors.empty())
    {
        vector<Actor*>::iterator temp;
        temp = actors.end();
        temp--;
        delete *temp;
        actors.pop_back();
    }
}


StudentWorld::~StudentWorld()
{
    cleanUp();
}









