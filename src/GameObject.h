/*
 * GameObject.h
 *
 *  Created on: 20/03/2017
 *      Author: Eduardo
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "Rect.h"
#include <string>

class GameObject {
public:
	virtual ~GameObject();
	virtual void Update(float dt) = 0;
	virtual void Render(int cameraX, int cameraY) = 0;
	virtual bool IsDead() = 0;
	virtual void NotifyCollision(GameObject& other) = 0;
	virtual bool Is(std::string type) = 0;

	Rect box;
	float rotation = 0;
	float translation = 0;
};

#endif /* GAMEOBJECT_H_ */

