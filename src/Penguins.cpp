/*
 * Penguins.cpp
 *
 *  Created on: 16/04/2017
 *      Author: Eduardo
 */

 #include "Penguins.h"
 #include "Game.h"
 #include "Bullet.h"
 #include "InputManager.h"
 #include "Camera.h"
 #include <math.h>

 Penguins* Penguins::player;

 Penguins::Penguins(float x, float y): bodySp("img/penguin.png"), cannonSp("img/cubngun.png"){
 	box.x = x;
 	box.y = y;
 	box.w = bodySp.GetWidth();
 	box.h = bodySp.GetHeight();

 	linearSpeed = 0;
 	player = this;
 	hp = 30;
 }

 Penguins::~Penguins(){
 	player = nullptr;
 }

 void Penguins::Update(float dt){
 	if(InputManager::GetInstance().IsKeyDown(SDLK_w)){
 		if(linearSpeed > 300){
 			linearSpeed = 300;
 		}
 		else{
 			linearSpeed += 10;
 		}
 	}

 	if(InputManager::GetInstance().IsKeyDown(SDLK_s)){
 		if(linearSpeed < 0){
 			linearSpeed = 0;
 		}
 		else{
 			linearSpeed -= 5;
 		}
 	}
 	if(InputManager::GetInstance().IsKeyDown(SDLK_a)){
 		rotation -= 20;
 	}
 	if(InputManager::GetInstance().IsKeyDown(SDLK_d)){
 		rotation += 20;
 	}

 	box.x += linearSpeed*dt*cos(rotation * M_PI/180);
 	box.y += linearSpeed*dt*sin(rotation * M_PI/180);

 	cannonAngle = (180/M_PI) * atan2(InputManager::GetInstance().GetMouseY() + Camera::pos.y - box.BoxCenter().y, InputManager::GetInstance().GetMouseX() + Camera::pos.x - box.BoxCenter().x);

 	if(InputManager::GetInstance().MousePress(LEFT_MOUSE_BUTTON)){
 		Shoot();
 	}
 }

 void Penguins::Render(int cameraX, int cameraY){
 	bodySp.Render(box.x - cameraX, box.y - cameraY, rotation);
 	cannonSp.Render(box.BoxCenter().x - cannonSp.GetWidth()/2 - cameraX, box.BoxCenter().y - cannonSp.GetHeight()/2 - cameraY, cannonAngle);
 }

 bool Penguins::IsDead(){
 	if(hp <= 0)
 		return true;
 	else
 		return false;
 }

 bool Penguins::Is(std::string type){
 	return (type == "Penguins");
 }

 void Penguins::NotifyCollision(GameObject& other){
 	
 }

 void Penguins::Shoot(){
 	float dx = InputManager::GetInstance().GetMouseX() - box.x;
	float dy = InputManager::GetInstance().GetMouseY() - box.y;
	float ds = pow(pow(dx, 2) + pow(dy, 2), 0.5);
 	Game::GetInstance()->GetState()->AddObject(new Bullet(box.BoxCenter().x + (cannonSp.GetWidth()/2)*cos(cannonAngle*M_PI/180), box.BoxCenter().y + (cannonSp.GetWidth()/2)*sin(cannonAngle*M_PI/180), cannonAngle, 20, ds, "img/penguinbullet.png"));
 }