/*
 * Camera.h
 *
 *  Created on: 07/04/2017
 *      Author: Eduardo
 */

 #ifndef CAMERA_H_
 #define CAMERA_H_

 #define SCREEN_WIDTH 	1024
 #define SCREEN_HEIGHT 	600

 #include "GameObject.h"
 #include "Vec2.h"

 class Camera{
 public:
 	static void Follow(GameObject* newFocus);
 	static void Unfollow();
 	static void Update(float dt);

 	static Vec2 pos;
 	static Vec2 speed;
 private:
 	static GameObject* focus;
 };

 #endif