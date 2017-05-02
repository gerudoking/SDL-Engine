/*
 * Camera.cpp
 *
 *  Created on: 07/04/2017
 *      Author: Eduardo
 */

 #include "Camera.h"
 #include "InputManager.h"

 GameObject* Camera::focus;
 Vec2 Camera::pos;
 Vec2 Camera::speed;

 void Camera::Follow(GameObject* newFocus){
 	focus = newFocus;
 }

 void Camera::Unfollow(){
 	focus = nullptr;
 }

 void Camera::Update(float dt){
 	speed.x = 0;
 	speed.y = 0;

 	if(focus != nullptr){
 		pos = focus->box.BoxCenter();
 		pos.x = pos.x - SCREEN_WIDTH/2;
 		pos.y = pos.y - SCREEN_HEIGHT/2;
 	}
 	else{
 		if(InputManager::GetInstance().IsKeyDown(LEFT_ARROW_KEY)){
 			speed.x = -200;
 		}
 		else if(InputManager::GetInstance().IsKeyDown(RIGHT_ARROW_KEY)){
 			speed.x = 200;
 		}

 		if(InputManager::GetInstance().IsKeyDown(UP_ARROW_KEY)){
 			speed.y = -200;
 		}
 		else if(InputManager::GetInstance().IsKeyDown(DOWN_ARROW_KEY)){
 			speed.y = 200;
 		}

 		pos.x += speed.x * dt;
 		pos.y += speed.y * dt;
 	}
 }