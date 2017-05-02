/*
 * Minion.h
 *
 *  Created on: 09/04/2017
 *      Author: Eduardo
 */

 #ifndef MINION_H_
 #define MINION_H_

 #define PI 	3.14

 #include "GameObject.h"
 #include "Vec2.h"
 #include "Sprite.h"

 class Minion : public GameObject{
 public:
 	Minion(GameObject* minionCenter, float arcOffset = 0, float scale = 1);
 	void Update(float dt);
 	void Render(int cameraX = 0, int cameraY = 0);
 	bool IsDead();
 	void Shoot(Vec2 pos);

 private:
 	GameObject* center;
 	Sprite sp;
 	float arc;
 };

 #endif