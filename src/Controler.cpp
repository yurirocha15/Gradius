/*
 * Controler.cpp
 *
 *  Created on: 27/05/2013
 *      Author: yuri
 */

#include "Controler.h"

Stage Controler::stage;
list<Entity*> Controler::enemyList;
int Controler::enemyCount = 0;
SDL_TimerID Controler::timerID2 = 0;

Controler::Controler(): FRAME_PER_SECOND(50), gradius(stage.screenHeight/2,300) {
	score = 0;
	quit = false;
	isShooting = false;
	isPaused = false;
	xVel = yVel = 0;
	enemyList.clear();
	gradiusList.clear();
	gradiusList.push_front(&gradius);
	stage.setScreenWidth(1300);
	upgradeCount = 0;
	timerID1 = 0;
	startTime = 0;
	backgroundMusic = NULL;
	setBottomBar();
	boss = NULL;
}
//store bottom bar sprites on the vector
void Controler::setBottomBar(){
	Sprite* sprite;
	sprite = new Sprite("ALL_OFF.png", stage.screenWidth/2 - 400, stage.screenHeight - 40);
	bottomBar.push_back(sprite);
	sprite = new Sprite("SPEED_ON.png", stage.screenWidth/2 - 400, stage.screenHeight - 40);
	bottomBar.push_back(sprite);
	sprite = new Sprite("SHIELD_ON.png", stage.screenWidth/2 - 400, stage.screenHeight - 40);
	bottomBar.push_back(sprite);
	sprite = new Sprite("SHOOT_ON.png", stage.screenWidth/2 - 400, stage.screenHeight - 40);
	bottomBar.push_back(sprite);
}

Controler::~Controler() {
	// TODO Auto-generated destructor stub
}
//set the stage the game is
void Controler::GameLoop() {
	Title TitleScreen;
	switch(TitleScreen.TitleLoop()){
	case 1: Load(); break;
	case 2: quit = true; break;
	default: break;
	}
	globalTime.start();
	startTime = globalTime.get_ticks();

	if (!quit) {
		StageLoop();
	}
	if (!quit) {
		BossTransition();
	}
	if (!quit) {
		BossLoop();
	}
}
//first stage loop
void Controler::StageLoop() {
	backgroundMusic = new Music();
	backgroundMusic->loadFile("stage1.wav");
	backgroundMusic->playSound();
	timerID1 = SDL_AddTimer(3500,&Controler::FactoryEnemy, NULL);
	//stage lasts 30s
	while (!quit && globalTime.get_ticks() - startTime <= 30000) {
		fps.start();
		if(event.ThereIsEvent())
		{
			if(event.EventType() == SDL_QUIT)
			{
				quit = true;
			}
			HandleInput();
			if(isPaused)
			{
				GamePause();
			}
		}
		if(isShooting)
		{
			gradius.shoot(globalTime, &gradiusList);
		}
		if(gradius.shieldState()) {
			Entity *shield = gradius.getShield();
			gradiusList.push_back(shield);
			gradius.setShield(false);
			cout<<"SHIELD"<<endl;
		}
		gradius.move(xVel,yVel,stage.screenHeight,stage.screenWidth);
		stage.background.move(stage.screen);
		bottomBar[gradius.getUpgrade()]->show(stage.screen);
		gradius.show(stage.screen);

		//Move Entities and check if there is a collision
		ManageEntities();

		//Score printing
		textScore.setX(10);
		textScore.setY(10);
		textScore.setSize(30);
		stringstream stringScore;
		stringScore << score;
		textScore.setText(stringScore.str().c_str());
		textScore.show(stage.screen);

		textScore.setX(stage.screenWidth - 60);
		textScore.setY(10);
		textScore.setSize(30);
		stringstream stringLife;
		stringLife << gradius.getLife();
		textScore.setText(stringLife.str().c_str());
		textScore.show(stage.screen);

		stage.showScreen();

		if( fps.get_ticks() < 1000 / FRAME_PER_SECOND )
		{
			SDL_Delay( ( 1000 / FRAME_PER_SECOND ) - fps.get_ticks() );
		}
		fps.stop();
	}
	SDL_RemoveTimer(timerID1);
	delete backgroundMusic;
}
//Kill enemies and bullets on the screen and start the boss warning animation
void Controler::BossTransition() {
	backgroundMusic = new Music();
	backgroundMusic->loadFile("Warning.wav");
	backgroundMusic->playSound();
	list<Entity*>::iterator it1;
	explosionList.clear();
	for(it1 = ++gradiusList.begin(); it1 != gradiusList.end(); it1++) {
		if ((*it1)->EntityType() != ENTITY_SHIELD) {
			delete (*it1);
			it1 = gradiusList.erase(it1);
			--it1;
		}
	}
	stage.background.setXVel(20);
	for (int i = 0; i< 700; i++) {
		fps.start();
		stage.background.move(stage.screen);
		it1 = gradiusList.begin();
		gradius.move(-10, 0, stage.screenHeight, stage.screenWidth);
		(*it1)->show(stage.screen);
		text.setY(stage.screenHeight/3);
		text.setSize(80);
		text.setText("WARNING");
		text.show(stage.screen, stage.screenWidth);
		if(!enemyList.empty()){
			for(it1 = enemyList.begin(); it1 != enemyList.end(); ++it1){
				if((*it1)->onAnimation(globalTime)){
					if(it1 == enemyList.begin()){
						delete(*it1);
						it1 = enemyList.erase(it1);
					}
					else {
						delete(*it1);
						it1 = enemyList.erase(it1);
						--it1;
					}
				}
				if (!enemyList.empty()) {
					(*it1)->show(stage.screen);
				}
			}
		}
		stage.showScreen();
		if( fps.get_ticks() < 1000 / FRAME_PER_SECOND )
		{
			SDL_Delay( ( 1000 / FRAME_PER_SECOND ) - fps.get_ticks() );
		}
		fps.stop();
	}
	enemyList.clear();
	gradius.move(10, 0, stage.screenHeight, stage.screenWidth);
}
//Boss stage loop
void Controler::BossLoop() {
	backgroundMusic = new Music();
	backgroundMusic->loadFile("boss1.wav");
	backgroundMusic->playSound();
	stage.background.setXVel(10);
	boss = new Boss(stage.screenWidth + 20, stage.screenHeight/2 - 150);
	enemyList.push_front(boss);

	for(int i = 0; i < 40; i++){
		fps.start();
		stage.background.move(stage.screen);
		gradius.move(xVel,yVel,stage.screenHeight,stage.screenWidth);
		gradius.show(stage.screen);
		(*enemyList.begin())->setX(stage.screenWidth + 20 - (i+1)*8);
		(*enemyList.begin())->show(stage.screen);
		stage.showScreen();
		if( fps.get_ticks() < 1000 / FRAME_PER_SECOND )
		{
			SDL_Delay( ( 1000 / FRAME_PER_SECOND ) - fps.get_ticks() );
		}
		fps.stop();
	}
	while(!quit){
		fps.start();
		if(timerID1 != 0){
			SDL_RemoveTimer(timerID1);
		}
		if(timerID2 != 0){
			SDL_RemoveTimer(timerID2);
		}
		if(event.ThereIsEvent())
		{
			if(event.EventType() == SDL_QUIT)
			{
				quit = true;
			}
			HandleInput();
			if(isPaused)
			{
				GamePause();
			}
		}
		if(isShooting)
		{
			gradius.shoot(globalTime, &gradiusList);
		}
		stage.background.move(stage.screen);
		gradius.move(xVel,yVel,stage.screenHeight,stage.screenWidth);
		gradius.show(stage.screen);
		list<Entity*>::iterator it = enemyList.begin();
		if ((*it)->isAlive() && (*it)->EntityType() == ENTITY_BOSS) {
			boss->shoot(globalTime, &enemyList);
		}

		ManageEntities();

		textScore.setX(10);
		textScore.setY(10);
		textScore.setSize(30);
		stringstream stringScore;
		stringScore << score;
		textScore.setText(stringScore.str().c_str());
		textScore.show(stage.screen);

		textScore.setX(stage.screenWidth - 60);
		textScore.setY(10);
		textScore.setSize(30);
		stringstream stringLife;
		stringLife << gradius.getLife();
		textScore.setText(stringLife.str().c_str());
		textScore.show(stage.screen);

		stage.showScreen();
		if( fps.get_ticks() < 1000 / FRAME_PER_SECOND )
		{
			SDL_Delay( ( 1000 / FRAME_PER_SECOND ) - fps.get_ticks() );
		}
		fps.stop();
	}
}
//Boss death animation spawn random explosions over its sprite
void Controler::BossDeathAnimation(Entity* boss) {
	list<Entity*>::iterator it = gradiusList.begin();
	++it;
	for(;it != gradiusList.end(); ++it){
		delete(*it);
		it = gradiusList.erase(it);
		--it;
	}
	it = enemyList.begin();
	++it;
	for(;it != enemyList.end(); ++it){
		delete(*it);
		it = enemyList.erase(it);
		--it;
	}
	it = enemyList.begin();
	list<Entity*>::iterator it2;

	for(int i = 0; i < 250; i++){
		fps.start();
		stage.background.move(stage.screen);
		gradius.move(xVel,yVel,stage.screenHeight,stage.screenWidth);
		gradius.show(stage.screen);
		(*it)->show(stage.screen);
		if (i%10 == 0) {
			int posX = (*it)->getX() + rand()%((*it)->getWidth() - 40);
			int posY = (*it)->getY() + rand()%((*it)->getHeight() - 40);
			Entity* explosion = new SimpleEnemy(posX,posY);
			explosionList.push_back(explosion);
		}

		if(!explosionList.empty()){
			for(it2 = explosionList.begin(); it2 != explosionList.end(); ++it2){
				if((*it2)->onAnimation(globalTime)){
					if(it2 == explosionList.begin()){
						delete(*it2);
						it2 = explosionList.erase(it2);
					}
					else {
						delete(*it2);
						it2 = explosionList.erase(it2);
						--it2;
					}
				}
				if (!explosionList.empty()) {
					(*it2)->show(stage.screen);
				}
			}
		}
		stage.showScreen();
		if( fps.get_ticks() < 1000 / FRAME_PER_SECOND ){
			SDL_Delay( ( 1000 / FRAME_PER_SECOND ) - fps.get_ticks() );
		}
		fps.stop();
	}
	explosionList.clear();
	quit = true;
	backgroundMusic = new Music();
	backgroundMusic->loadFile("King_of_Kings.wav");
	backgroundMusic->playSound();
	WinScreen Win;
}

bool Controler::GameQuit() {
	return quit;
}

//handle the controlls
//ARROWS -> Controls Ship
//SPACE -> Shoot
//C -> Activate Upgrade
//P -> Pause
//S -> Save
void Controler::HandleInput() {

	if(event.EventType() == SDL_KEYDOWN)
	{
		switch(event.EventKey())
		{
			case SDLK_UP: yVel -= 5; break;
			case SDLK_DOWN: yVel += 5; break;
			case SDLK_LEFT: xVel -= 5; break;
			case SDLK_RIGHT: xVel += 5; break;
			case SDLK_SPACE: isShooting = true; break;
			default: break;
		}
	}
	else if(event.EventType() == SDL_KEYUP)
	{
		switch(event.EventKey())
		{
			case SDLK_UP: yVel += 5; break;
		    case SDLK_DOWN: yVel -= 5; break;
		    case SDLK_LEFT: xVel += 5; break;
		    case SDLK_RIGHT: xVel -= 5; break;
		    case SDLK_SPACE: isShooting = false; break;
		    case SDLK_p: isPaused = !isPaused; break;
		    case SDLK_s: if(isPaused) Save(); break;
		    case SDLK_c: gradius.activateUpgrade(); break;
		    default: break;
		}
	}
}
//Pause stope the enemy spawns and wait for P be pressed again
void Controler::GamePause() {
	fps.pause();
	backgroundMusic->pauseSound();
	text.setY(stage.screenHeight/3);
	text.setSize(60);
	text.setText("PAUSED");
	text.show(stage.screen, stage.screenWidth);
	Message info;
	info.setY(2*stage.screenHeight/3);
	info.setSize(35);
	info.setText("RETURN - P    SAVE - S");
	info.show(stage.screen, stage.screenWidth);
	stage.showScreen();
	SDL_RemoveTimer(timerID1);
	SDL_RemoveTimer(timerID2);

	while(fps.is_paused())
	{
		if(event.ThereIsEvent())
		{
			HandleInput();
			if(event.EventType() == SDL_QUIT)
			{
				quit = true;
				isPaused = false;
			}
			if(!isPaused)
			{
				fps.unpause();
				timerID1 = SDL_AddTimer(3500,&Controler::FactoryEnemy, NULL);
				backgroundMusic->pauseSound();
			}
		}
	}
}
//Manage collision between good and bad entities
void Controler::ManageEntities() {

	list<Entity*>::iterator it1;
	list<Entity*>::iterator it2;

//TODO Improve the collision loop. Check design pattern observer.
//Checking collision, moving bad entities, death management
	for(it2 = enemyList.begin(); it2 != enemyList.end(); ++it2){
		for(it1 = gradiusList.begin(); it1 != gradiusList.end(); ++it1){
			if (!gradiusList.empty() && !enemyList.empty()){
				if((*it2)->checkCollision(*it1)){
					if ((*it2)->EntityType() != ENTITY_UPGRADE) {
						if((*it1)->EntityType() != ENTITY_GRADIUS){
							(*it1)->beDamaged(1);
							if(!(*it1)->isAlive()){
								if((*it1)->EntityType() == ENTITY_SHIELD)
									gradius.destroyShield();
								else
									delete (*it1);
								it1 = gradiusList.erase(it1);
								--it1;
							}
						}
						else {
							(*it1)->beDamaged(1);
							if(!(*it1)->isAlive()){
								gradiusList.clear();
								enemyList.clear();
								it1 = gradiusList.end();
								it2 = enemyList.end();
								backgroundMusic = new Music();
								backgroundMusic->loadFile("Loser_of_Losers.wav");
								backgroundMusic->playSound();
								GameOver gameover;
								quit = true;
								return;
							}
						}
					}
					if(it2 == enemyList.begin() || it2 == enemyList.end()){
						if ((*it2)->EntityType() != ENTITY_UPGRADE) {
							(*it2)->beDamaged(1);
							if(!(*it2)->isAlive()){
								if ((*it2)->EntityType() == ENTITY_ENEMY) {
									upgradeCount++;
									if(upgradeCount > 0){
										manageUpgrade((*it2)->getX(), (*it2)->getY());
										upgradeCount = 1;
									}
									explosionList.push_back(*it2);
									score += 200;
								}
								else if ((*it2)->EntityType() == ENTITY_BOSS) {
									BossDeathAnimation(*it2);
								}
								else
									delete (*it2);
								it2 = enemyList.erase(it2);
							}
						}
						else if ((*it1)->EntityType() == ENTITY_GRADIUS && (*it2)->EntityType() == ENTITY_UPGRADE){
							(*it1)->addUpgrade();
							delete (*it2);
							it2 = enemyList.erase(it2);
						}
					}
					else{
						if ((*it2)->EntityType() != ENTITY_UPGRADE) {
							(*it2)->beDamaged(1);
							if(!(*it2)->isAlive()){
								if ((*it2)->EntityType() == ENTITY_ENEMY) {
									upgradeCount++;
									if(upgradeCount == 20){
										manageUpgrade((*it2)->getX(), (*it2)->getY());
										upgradeCount = 0;
									}
									explosionList.push_back(*it2);
									score += 200;
								}
								else if ((*it2)->EntityType() == ENTITY_BOSS) {
									BossDeathAnimation(*it2);
								}
								else
									delete (*it2);
								it2 = enemyList.erase(it2);
								--it2;
							}
						}
						else if ((*it1)->EntityType() == ENTITY_GRADIUS && (*it2)->EntityType() == ENTITY_UPGRADE){
							(*it1)->addUpgrade();
							delete (*it2);
							it2 = enemyList.erase(it2);
							--it2;
						}
					}
				}
			}
		}
		if(!enemyList.empty()){
			(*it2)->move(stage.screenWidth, stage.screenHeight);
			if((*it2)->endScreen( stage.screenWidth, stage.screenHeight) && (*it2)->EntityType() != ENTITY_BOSS){
				delete (*it2);
				it2 = enemyList.erase(it2);
				--it2;
			}
			else{
				(*it2)->show(stage.screen);
			}
		}
	}
	//Animating Explosions
	if(!explosionList.empty()){
		for(it1 = explosionList.begin(); it1 != explosionList.end(); ++it1){
			if((*it1)->onAnimation(globalTime)){
				if(it1 == explosionList.begin()){
					delete(*it1);
					it1 = explosionList.erase(it1);
				}
				else {
					delete(*it1);
					it1 = explosionList.erase(it1);
					--it1;
				}
			}
			if (!explosionList.empty()) {
				(*it1)->show(stage.screen);
			}
		}
	}
	//Moving good entities
	if(!gradiusList.empty()){
		it2 = gradiusList.begin();
		it2++;
		for( it1 = it2; it1 != gradiusList.end(); it1++){

			if ((*it1)->EntityType() != ENTITY_SHIELD) {
				(*it1)->move(stage.screenWidth, stage.screenHeight);
				if((*it1)->endScreen( stage.screenWidth, stage.screenHeight))
				{
					delete (*it1);
					it1 = gradiusList.erase(it1);
					--it1;
				}

				else{
					(*it1)->show(stage.screen);
				}
			}
			else {
				(*it1)->onAnimation(globalTime);
				(*it1)->show(stage.screen);
			}
		}
	}
}

void Controler::manageUpgrade(int x, int y) {
	Entity* upgrade;

	upgrade = new Upgrade(x,y);
	enemyList.push_back(upgrade);

}

Uint32 Controler::FactoryEnemy(Uint32 interval, void *p){
	int position;
	int sort = rand() % 3;

	position = rand() % (stage.screenHeight - 180) + 90;

	if(sort <= 1){
		timerID2 = SDL_AddTimer(250 ,&Controler::WaveEnemySimple,(void *)(intptr_t)position);
	}
	else if(sort == 2){
		timerID2 = SDL_AddTimer(350 ,&Controler::WaveEnemySquad1,(void *)(intptr_t)position);
	}
	else{
		timerID2 = SDL_AddTimer(300 ,&Controler::WaveEnemySquad2,(void *)(intptr_t)position);
	}

	return 0;

}

Uint32 Controler::WaveEnemySimple(Uint32 interval, void *p){
	Entity* creep;
	creep = new SimpleEnemy(stage.screenWidth , (intptr_t)p);
	enemyList.push_back(creep);
	creep = new SimpleEnemy(stage.screenWidth, stage.screenHeight - (intptr_t)p);
	creep->setYVel(-creep->getYVel());
	enemyList.push_back(creep);
	enemyCount++;
	if((enemyCount%5) == 0){
			return 0;
	}
	return interval;
}

Uint32 Controler::WaveEnemySquad1(Uint32 interval, void *p){
	Entity* squad;
	squad = new SquadEnemy(stage.screenWidth ,stage.screenHeight/2 + 180);
	enemyList.push_back(squad);
	squad = new SquadEnemy(stage.screenWidth, stage.screenHeight/2);
	enemyList.push_back(squad);
	squad = new SquadEnemy(stage.screenWidth , stage.screenHeight/2 - 180 );
	enemyList.push_back(squad);
	//squad = new SquadEnemy(stage.screenWidth , stage.screenHeight/2 - 75);
	//enemyList.push_back(squad);
	//squad = new SquadEnemy(stage.screenWidth, stage.screenHeight/2 - 150);
	//squad->setYVel(-squad->getYVel());
	//enemyList.push_back(squad);
	enemyCount++;
	if((enemyCount%1) == 0){
			return 0;
	}

	return interval;
}

Uint32 Controler::WaveEnemySquad2(Uint32 interval, void *p){
	Entity* squad;
	cout<< "squad1";
	squad = new SquadEnemy(stage.screenWidth, stage.screenHeight/2);
	enemyList.push_back(squad);
	cout<< "squad2";
	squad = new SquadEnemy(stage.screenWidth , stage.screenHeight/2 + 75);
	enemyList.push_back(squad);
	cout<< "squad3";
	squad = new SquadEnemy(stage.screenWidth , stage.screenHeight/2 - 75);
	enemyList.push_back(squad);
	cout<< "squad4";
	squad = new SquadEnemy(stage.screenWidth, stage.screenHeight/2 - 150);
	cout<< "squad5";
	enemyList.push_back(squad);
	enemyCount++;
	if((enemyCount%1) == 0){
			return 0;
	}

	return interval;
}

////////////////////////////////////
////////Teste Persistência//////////
////////////////////////////////////
bool Controler::Save(){
	list<Entity*>::iterator it1;
	list<Entity*>::iterator it2;


	ofstream myfile ("save.txt");
	if (myfile.is_open())
	{
		myfile << gradiusList.size() << endl;
		myfile << enemyList.size() << endl;
		for(it1 = gradiusList.begin(); it1 != gradiusList.end(); it1++){
			//myfile << (*it1)->ge;
			(*it1)->Save(myfile);
		}
		for(it2 = enemyList.begin(); it2 != enemyList.end(); it2++){
			//myfile << (*it1)->type;
			(*it2)->Save(myfile);
		}
		myfile.close();
	}
	  else cout << "Unable to open file";

	return true;
}

bool Controler::Load(){
	Bullet* bullet;
	Enemy* enemy;

	ifstream myfile ("save.txt");
	if (myfile.is_open())
	{
		int sizeGlist;
		int sizeElist;
		int x = 0;
		int y = 0;
		myfile >> sizeGlist;
		myfile >> sizeElist;
		myfile >> x;
		myfile >> y;
		gradius.setX(x);
		gradius.setY(y);
		gradius.Load(myfile);
		gradiusList.push_back(&gradius);
		for(int i = 1; i < sizeGlist; i++){
			if(myfile.good()){
				myfile >> x;
				myfile >> y;
				bullet = new Simple("tiro1.png", x, y, true);
				bullet->Load(myfile);
				gradiusList.push_back(bullet);
			}
		}
		for(int j = 0; j < sizeElist; j++){
			if(!myfile.fail()){
				myfile >> x;
				myfile >> y;
				enemy = new SimpleEnemy( x, y);
				enemy->Load(myfile);
				enemyList.push_back(enemy);
			}
		}
		myfile.close();
	}
	  else cout << "Unable to open file";

	return true;
}
