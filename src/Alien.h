/*
 * Alien.h
 *
 *  Created on: 07/04/2017
 *      Author: Eduardo
 */

 #ifndef ALIEN_H_
 #define ALIEN_H_

 #include "GameObject.h"
 #include "Sprite.h"
 #include "Vec2.h"
 #include "Minion.h"
 #include <queue>

 class Alien: public GameObject{
 public:
 	Alien(float x, float y, int nMinions);
 	~Alien();

 	void Update(float dt);
 	void Render(int cameraX = 0, int cameraY = 0);
 	bool IsDead();

 	void NotifyCollision(GameObject& other);
 	bool Is(std::string type);

 	static int alienCount = 0;

 private:
 	enum AlienState{MOVING = 1, RESTING = 2};

 	AlienState state;
 	Timer restTimer;
 	Vec2 destination;
 	Sprite sp;
 	Vec2 speed;
 	int hp;

 	std::vector<Minion> minionArray;
 };

 #endif