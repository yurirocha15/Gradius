/*
 * Controler.h
 *
 *  Created on: 27/05/2013
 *      Author: yuri
 */

#ifndef CONTROLER_H_
#define CONTROLER_H_

#include "Background.h"
#include "Boss.h"
#include "Bullet.h"
#include "Chunk.h"
#include "Enemy.h"
#include "Entity.h"
#include "Event.h"
#include "GameOver.h"
#include "GradiusShield.h"
#include "GradiusShip.h"
#include "Message.h"
#include "Music.h"
#include "Screen.h"
#include "Simple.h"
#include "SimpleEnemy.h"
#include "SquadEnemy.h"
#include "Sprite.h"
#include "Stage.h"
#include "StringInput.h"
#include "Timer.h"
#include "Title.h"
#include "Upgrade.h"
#include "WinScreen.h"
#include <list>
#include <sstream>
#include <vector>

using namespace std;

class Controler {
private:
	bool quit;
	bool isShooting;
	bool isPaused;
	const int FRAME_PER_SECOND;
	int xVel;
	int yVel;
//	int lastFireTime;
	int score;
	int startTime;
	static int enemyCount;
	int upgradeCount;
	enum {
		ENTITY_GRADIUS = 0,
		ENTITY_SHIELD,
		ENTITY_BULLET,
		ENTITY_UPGRADE,
		ENTITY_ENEMY,
		ENTITY_BOSS,
	};

	Music *backgroundMusic;
	Timer fps, globalTime;
	Event event;
	static Stage stage;
	GradiusShip gradius;
	Boss *boss;
	Message text;
	Message textScore;
	vector<Sprite*> bottomBar;

//	Bullet *tiro;
	list<Entity*> gradiusList;
	static list<Entity*> enemyList;
	list<Entity*> explosionList;
	SDL_TimerID timerID1;
	static SDL_TimerID timerID2;

	void setBottomBar();
	void HandleInput();
	void GamePause();
	void StageLoop();
	void BossTransition();
	void BossLoop();
	void BossDeathAnimation(Entity*);
	void ManageEntities();
	void manageUpgrade(int, int);
	static Uint32 FactoryEnemy(Uint32, void*);
	static Uint32 WaveEnemySimple(Uint32, void*);
	static Uint32 WaveEnemySquad1(Uint32, void*);
	static Uint32 WaveEnemySquad2(Uint32, void*);
	int RandomGenerator(int);
	bool Save();
	bool Load();

public:
	Controler();
	virtual ~Controler();
	void GameLoop();
	bool GameQuit();

};

#endif /* CONTROLER_H_ */
