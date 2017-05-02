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

 private:
 	class Action{
 	public:
 		enum ActionType {MOVE = 0, SHOOT = 1};

 		Action(ActionType type, float x, float y){
 			this->type = type;
 			pos.x = x;
 			pos.y = y;
 		}

 		ActionType type;
 		Vec2 pos;
 	};

 	Sprite sp;
 	Vec2 speed;
 	int hp;

 	std::queue<Action> taskQueue;
 	std::vector<Minion> minionArray;
 };

 #endif