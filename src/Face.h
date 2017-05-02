/*
 * Face.h
 *
 *  Created on: 20/03/2017
 *      Author: Eduardo
 */

#ifndef FACE_H_
#define FACE_H_

#include "GameObject.h"
#include "Sprite.h"
#include <iostream>

class Face: public GameObject {
public:
	Face(float x, float y);

	void Damage(int damage);

	void Update(float dt);
	void Render(int cameraX = 0, int cameraY = 0);
	bool IsDead();
private:
	int hitpoints;
	Sprite sp;
};

#endif /* FACE_H_ */
