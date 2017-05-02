/*
 * Face.cpp
 *
 *  Created on: 20/03/2017
 *      Author: Eduardo
 */

#include "Face.h"

Face::Face(float x, float y) : sp("img/penguinface.png"){
	box.x = x;
	box.y = y;
	box.w = sp.GetWidth();
	box.h = sp.GetHeight();
	hitpoints = 30;
}

void Face::Damage(int damage){
	hitpoints -= damage;
}

void Face::Update(float dt){

}

void Face::Render(int cameraX, int cameraY){
	sp.Render(box.x - cameraX, box.y - cameraY);
	//std::cout << "renderizou face\n" << box.x << box.y << std::endl;
}

bool Face::IsDead(){
	if (hitpoints <= 0)
		return true;
	else
		return false;
}
