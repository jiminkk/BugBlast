BugBlast
========

CS 32 Project

Basic framework provided by the professor.
Wrote the code for Actor.h, Actor.cpp, StudentWorld.h, and StudentWorld.cpp

Actor.cpp contains the game's object declarations and implementations.
StudentWorld.cpp executes the game rules.


BugBlast is a simplified version of the original game called Bomberman. In BugBlast, the player has to exterminate all the Zumi bugs using bug spray and navigating the maze, then the player can move up to the next level.


================================================================================

1. Pseudocode

Actor Class:
Actor(int i_d, int x, int y, StudentWorld* gw);
	This constructor gets four parameters: the ID of the actor, the coordinates of the
	actor's position, and the pointer to StudentWorld. I set gw to my private variable
	called m_getWorld, set default visibility to true, and alive to true. All derived
	actors will point to gw, be visible, and alive (except for Exit and goodies until the 
	right time).
    
virtual ~Actor();
	The destructor has no implementation.
    
virtual void doSomething() = 0;
    Each actor has a doSomething function. Actor class is the parent class. This function
    is a dummy function (no implementation), so it is a pure virtual function.
    
bool isAlive() const;
	This function returns whether the actor is alive or not. This doesn't have to be
	virtual because every actor calls the same function without modifying it.
    
void setDead();
    This function sets the actor as dead, turns the bool member of alive to false. This
    also doesn't have to be virtual.
    
StudentWorld* getWorld() const;
	This function returns the pointer to the StudentWorld.
    

Player Class:
Player(int x, int y, StudentWorld* gw);
	This Player constructor sets the ID to IID_PLAYER, the coordinates of the player's
	position, and the pointer to the StudentWorld.
    
virtual ~Player();
	This destructor has no implementation.
    
virtual void doSomething();
	If the player is at the same location as a simple zumi or a complex zumi, the game plays
	the SOUND_PLAYER_DIE, sets the player to dead, and returns nothing.

	If the player is at the same location as a destroyable/permanent brick, the game plays
	the SOUND_PLAYER_DIE, sets the player to dead, and returns nothing (only if the player
	doesn't have the WalkThroughWalls goodie).

	If player can walk through walls, goodie's lifetime will decrease by one, and canWalk will
	be set to true, until lifetime becomes 0.

	If player has simultaneous sprayer, goodie's lifetime will decrease by one, and hassSSGoodie
	will be true, until lifetime becomes 0.

	Once user hits a key during one tick,
		Depending on the key (left-right-down-up),
			If the actor left to player is on a destroyable/permanent brick, function returns,
			unless player can walk through walls and the actor left to player is a destroyable
			brick.
			Else, move left.
		If key is space
			Drop a bug sprayer in the current square if it's not on a permanent Brick or a 
			Bug sprayer.
				If player has a simultaneous sprayer,
					If number of bug sprayers is less than the maximum number of sprayers
						add a bug sprayer at the current position
						increment number of bug sprayers
					If number of bug sprayers is less than 2 (default)
						then add bug sprayer
						increment number of bug sprayers

    
void decreaseNumOfSprayers();
    Decrement number of bug sprayers
    
void activateWalkThroughWalls(unsigned int lifetime);
    Assign parameter to private member variable
    Assign canWalk to true
    
bool canWalkThroughWalls() const;
    return bool variable of canWalk
    
void increaseSimultaneousSprayers(unsigned int max, unsigned int lifetime);
    assign hasSSGoodie to true
    assign lifetime_sprayers to lifetime parameter
    assign max_sprayers to max parameter
    
bool hasSimultaneousSprayer();
	return bool variable of hasSSGoodie
	
Brick Class:
Bricks(int i_d, int x, int y, StudentWorld* gw);
	Initializer list assigns an i_d to Actor constructor
    
virtual ~Bricks();
    No implementation.
    
virtual void doSomething();
    No implementation.
    
    
Destroyable Brick Class:
destroyableBricks(int x, int y, StudentWorld* gw);
    Initializer list assigns i_d to destroyable Brick.
    
virtual ~destroyableBricks();
	This is virtual because Brick class is the parent class here.
	
	
Permanent Brick Class:
permBricks(int x, int y, StudentWorld* gw);
    Initializer list assigns i_d to permanent brick.
    
virtual ~permBricks();
	Virtual because Brick class is parent class.
	

Zumi Class:
Zumi(int i_d, int x, int y, StudentWorld* gw, unsigned int ticksPerMove);
    Initializer list assigns i_d to Actor parent class.
    
virtual ~Zumi();
	Virtual because Zumi has a parent class, Actor.
	
	
Simple Zumi Class:
SimpleZumi(int x, int y, StudentWorld* gw);
    Assigns currentDirection to a random number generated to get random direction.
    
virtual ~SimpleZumi();
    No implementation.
    
virtual void doSomething();
	If not alive, return immediately.
	
	If the actor at current location is bugsprays, 
		decrement number of zumis
		set zumi to dead
		add Goodies to this position.
		If live zumi is 0,
			play sound that exit is revealed
	If player and zumi are at the same location
		set player dead
	
	Depending on current direction,
		If there is no bugsprayer, permanent brick, and destroyable brick,
			Move to that position
		If not,
			Set current direction to another random direction.
	

Complex Zumi Class:
ComplexZumi(int x, int y, StudentWorld* gw);
    m_counter is 0
    current direction is random
    
virtual ~ComplexZumi();
    No implementation.
    
virtual void doSomething();
	Complex Zumi's doSomething has the same implementation as does the Simple Zumi
	

Exit Class:
Exit(int x, int y, StudentWorld* gw);
    Set visible to false first.
    
virtual ~Exit();
    
virtual void doSomething();
    If there is no more live zumi, set exit as visible.
    If exit is visible and player is on the exit sign,
    	set level as finished.
    	
void setExitVisible();
	This just sets visibility to true.
	

TimedLifetimeActor Class
TimedLifetimeActor(int i_d, int startX, int startY, StudentWorld* gw, unsigned int lifetime);
    This class is the parent class for actors with time limits.
    
virtual void doSomething();
    Parent class. This has no implementation.
    
void expireImmediately();
	Set lifetime to 1.
    
void inputLifeTime(int n);
	Assign lifetime to the parameter.

int getLifeTime();
    Returns lifetime.
    
void decrementLifeTime();
	Decrements lifetime by 1.
	
	
BugSprayers(int x, int y, StudentWorld* gw);
    As this is derived from TimedLifetimeActor, assign lifetime to 40.
    
virtual ~BugSprayers();
    
virtual void doSomething();
	If alive,
		This class adds spray in four directions.
    

BugSpray Class:
	This bug spray class is implemented for 3 ticks.
	While it's alive, if it hits one of the destroyable bricks or the player,
	or a zumi, it kills/destroys the actors.
	
Goodie Class:
	This is a parent Goodie class for the three goodies.
	I needed this parent class in order to get the option value of GoodieLifetime
	in Ticks from the Level class. 
	
ExtraLifeGoodie Class:
	This class's doSomething function incremented lives every time.
	
WalkThroughWalls Class:
	This class's doSomething function is similar to ExtraLifeGoodie, except it assigns
	the option of WalkThroughTicks.

IncreaseBugSprayGoodie Class:
	The same goes for this goodie class.
	
	
	
2. A list of failures:
-I could not correctly and fully implement the ComplexZumi Class, so I made the complex
zumis work like the simple zumis.
-I failed to finish implementing the display status.
-I was not able to keep track of the total score correctly.


3. Test cases:

-StudentWorld's init()
I tested this function by loading just the first level first. I replaced the level
variable with case 0, and saw if the result loaded level. By loading this level, I pushed
back bricks and the player into the collection of vectors into each location. If the
game didn't show the specified actors, I knew what was wrong.

-Exit class
I tested if the exit sign showed up by setting visibility to true in the constructor.

-Player class
I tested if the player showed up by setting isAlive to false or true. I also checked for
each goodie by changing each state to true. For instance, if Can Walk Through Walls, then
player could walk through the destroyable bricks.
I also tested how it moved by just choosing one character (direction).

-Simple Zumi Class
I tested if Simple Zumi comes out by changing isAlive to false. I also tested its alive
states by killing it manually. I also tested the directions by setting the current
direction to one specific direction, instead of a random direction.

-BugSprayer Class
I checked if bug sprayer worked on a player by just adding spray on the player's position.
I also checked this by playing the sound at certain places to know where the problem was.

-BugSpray Class
I checked this by playing sound at different places.

-Goodie Classes
I checked for each goodie by checking if walk through gave the player the ability to
walk through. This applies to the other goodie classes.
