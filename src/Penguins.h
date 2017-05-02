/*
 * Penguins.h
 *
 *  Created on: 16/04/2017
 *      Author: Eduardo
 */

 #include "GameObject.h"
 #include "Sprite.h"
 #include "Vec2.h"

 class Penguins: public GameObject{
 public:
 	Penguins(float x, float y);
 	~Penguins();

 	void Update(float dt);
 	void Render(int cameraX = 0, int cameraY = 0);
 	bool IsDead();

 	void Shoot();

 	static Penguins* player;
 private:
 	Sprite bodySp;
 	Sprite cannonSp;
 	Vec2 speed;
 	float linearSpeed;
 	float cannonAngle;
 	int hp;
 };