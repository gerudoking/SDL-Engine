/*
 * Bullet.cpp
 *
 *  Created on: 10/04/2017
 *      Author: Eduardo
 */

 #include "Bullet.h"

 Bullet::Bullet(float x, float y, float angle, float speed, float maxDistance, std::string sprite) : sp(sprite){
 	std::cout << "Is constructing\n";
 	box.x = x;
 	box.y = y;
 	box.w = sp.GetWidth();
 	box.h = sp.GetHeight();

 	distanceLeft = maxDistance;
 	this->speed.x = speed * cos(angle*M_PI/180);
 	this->speed.y = speed * sin(angle*M_PI/180);

 	rotation = angle;
 }

 void Bullet::Update(float dt){
 	std::cout << "Is updating\n";
 	float subtrair;

 	box.x += speed.x;
 	box.y += speed.y;

 	subtrair = speed.Magnitude(speed);
 	distanceLeft -= subtrair;
 }

 void Bullet::Render(int cameraX, int cameraY){
 	std::cout << "Is rendering\n";
 	sp.Render(box.x - cameraX, box.y - cameraY, rotation);
 }

 bool Bullet::IsDead(){
 	if(distanceLeft <= 0)
 		return true;
 	else
 		return false;
 }