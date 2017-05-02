/*
 * Animation.h
 *
 *  Created on: 23/04/2017
 *      Author: Eduardo
 */

 #ifndef ANIMATION_H_
 #define ANIMATION_H_

 #include "GameObject.h"
 #include <string>
 #include "Timer.h"
 #include "Sprite.h"

 class Animation : public GameObject{
 public:
 	Animation(float x, float y, float rotation, std::string sprite, int frameCount, float frameTime, bool ends);

 	void Update(float dt);
 	void Render();
 	bool IsDead();

 	void NotifyCollision(GameObject* other);
 	bool Is(std::string type);
 private:
 	Timer endTimer;
 	float timeLimit;
 	bool oneTimeOnly;
 	Sprite sp;
 };

 #endif