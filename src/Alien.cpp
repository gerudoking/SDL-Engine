/*
 * Alien.cpp
 *
 *  Created on: 08/04/2017
 *      Author: Eduardo
 */

 #include "Alien.h"
 #include "InputManager.h"
 #include "Camera.h"
 #include <iostream>

 Alien::Alien(float x, float y, int nMinions) : sp("img/alien.png"){
 	box.x = x;
 	box.y = y;
 	box.w = sp.GetWidth();
 	box.h = sp.GetHeight();
 	hp = 30;

 	int scale;

 	for(int i = 0; i < nMinions; i++){
 		scale = rand() % 2;
 		if(scale == 1)
 			minionArray.emplace_back(Minion(this, i * 360/nMinions, 1.5));
 		else
 			minionArray.emplace_back(Minion(this, i * 360/nMinions));
 	}
 }

 Alien::~Alien(){

 }

 void Alien::Update(float dt){
 	rotation -= 2;

 	if(InputManager::GetInstance().MousePress(LEFT_MOUSE_BUTTON)){
 		taskQueue.push(Action(Action::SHOOT, InputManager::GetInstance().GetMouseX() + Camera::pos.x, InputManager::GetInstance().GetMouseY() + Camera::pos.y));
 	}
 	if(InputManager::GetInstance().MousePress(RIGHT_MOUSE_BUTTON)){
 		taskQueue.push(Action(Action::MOVE, InputManager::GetInstance().GetMouseX() + Camera::pos.x, InputManager::GetInstance().GetMouseY() + Camera::pos.y));
 	}

 	if(taskQueue.size() > 0){
 		Vec2 pos = Vec2(taskQueue.front().pos.x - box.w/2, taskQueue.front().pos.y - box.h/2);
 		float dx = pos.x - box.x;
 		float dy = pos.y - box.y;
 		//float ds = pos.Dist(Vec2(box.x, box.y), pos);
 		float ds = pow(pow(dx, 2) + pow(dy, 2), 0.5);
 		if(taskQueue.front().type == Action::MOVE){
 			if(dx/ds == NAN || dy/ds == NAN){
 				taskQueue.pop();
 			}
 			if((box.x + 20 * dx/ds > pos.x && pos.x > box.x) || (box.x + 20 * dx/ds < pos.x && pos.x < box.x))
 				box.x = pos.x;
 			else
 				box.x += 20 * dx/ds;
 			if((box.y + 20 * dy/ds > pos.y && pos.y > box.y) || (box.y + 20 * dy/ds < pos.y && pos.y < box.y))
 				box.y = pos.y;
 			else
 				box.y += 20 * dy/ds;

 			if(box.x == pos.x && box.y == pos.y)
 				taskQueue.pop();
 		}

 		if(taskQueue.front().type == Action::SHOOT){
 			minionArray.at(1).Shoot(pos);
 			taskQueue.pop();
 		}
 	}

 	for(unsigned i = 0; i < minionArray.size(); i++){
 		minionArray.at(i).Update(dt);
 	}
 }

 void Alien::Render(int cameraX, int cameraY){
 	sp.Render(box.x - cameraX, box.y - cameraY, rotation);

 	for(unsigned i = 0; i < minionArray.size(); i++){
 		minionArray.at(i).Render(Camera::pos.x, Camera::pos.y);
 	}
 }

 bool Alien::IsDead(){
 	if (hp <= 0)
 		return true;
 	else
 		return false;
 }