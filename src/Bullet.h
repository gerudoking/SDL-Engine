/*
 * Bullet.h
 *
 *  Created on: 10/04/2017
 *      Author: Eduardo
 */

 #ifndef BULLET_H_
 #define BULLET_H_

 #include <string>
 #include <math.h>
 #include "Sprite.h"
 #include "Vec2.h"
 #include "InputManager.h"
 
 class Bullet : public GameObject{
 public:
 	Bullet(float x, float y, float angle, float speed, float maxDistance, std::string sprite);
 	void Update(float dt);
 	void Render(int cameraX = 0, int cameraY = 0);
 	bool IsDead();

 private:
 	Sprite sp;
 	Vec2 speed;
 	float distanceLeft;
 };

 #endif