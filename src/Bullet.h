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
 	Bullet(float x, float y, float angle, float speed, float maxDistance, std::string sprite, int frameCount = 0, float frameTime = 0);
 	void Update(float dt);
 	void Render(int cameraX = 0, int cameraY = 0);
 	bool IsDead();

 	void NotifyCollision(GameObject& other);
 	bool Is(std::string type);

 private:
 	Sprite sp;
 	Vec2 speed;
 	float distanceLeft;
 };

 #endif