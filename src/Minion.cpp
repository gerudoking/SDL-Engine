/*
 * Minion.cpp
 *
 *  Created on: 09/04/2017
 *      Author: Eduardo
 */

 #include "Minion.h"
 #include "math.h"
 #include "Bullet.h"
 #include "Game.h"

 Minion::Minion(GameObject* minionCenter, float arcOffset, float scale) : sp("img/minion.png"){
 	translation = arcOffset;

 	center = minionCenter;

 	sp.SetScaleX(scale);
 	sp.SetScaleY(scale);

 	box.x = minionCenter->box.BoxCenter().x - sp.GetWidth()/2 + 200*cos(arcOffset * M_PI/180); 
 	box.y = minionCenter->box.BoxCenter().y - sp.GetHeight()/2 + 200*sin(arcOffset * M_PI/180);
 	box.w = sp.GetWidth();
 	box.h = sp.GetHeight();
 }

 void Minion::Update(float dt){
 	translation += 2;
 	rotation = translation + 90;

 	box.x = center->box.BoxCenter().x - sp.GetWidth()/2 + 200*cos(translation * M_PI/180); 
 	box.y = center->box.BoxCenter().y - sp.GetHeight()/2 + 200*sin(translation * M_PI/180);
 }

 void Minion::Render(int cameraX, int cameraY){
 	sp.Render(box.x - cameraX, box.y - cameraY, rotation);
 }

 bool Minion::IsDead(){
 	return false;
 }

void Minion::Shoot(Vec2 pos){
	std::cout << "is shooting\n";
	float dx = InputManager::GetInstance().GetMouseX() - box.x;
	float dy = InputManager::GetInstance().GetMouseY() - box.y;
	float ds = pow(pow(dx, 2) + pow(dy, 2), 0.5);

	Game::GetInstance()->GetState()->AddObject(new Bullet(box.x, box.y, atan(dy/dx)*180/M_PI, 20, ds, "img/minionbullet1.png"));
}