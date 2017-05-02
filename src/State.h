/*
 * State.h
 *
 *  Created on: 14/03/2017
 *      Author: Eduardo
 */

#ifndef STATE_H_
#define STATE_H_

#include "GameObject.h"
#include "Sprite.h"
#include "TileSet.h"
#include "TileMap.h"
#include <math.h>
#include <iostream>
#include <vector>
#include <memory>

class Sprite;
class TileSet;
class TileMap;

class State {
public:
	State();
	~State();
	bool QuitRequested();
	void Update();
	void Render();
	void LoadAssets();
	void AddObject(GameObject* obj);
private:
	void Input();

	std::vector<std::unique_ptr<GameObject>> objectArray;
	Sprite* bg;
	bool quitRequested;
	TileSet* tileSet;
	TileMap* tileMap;
};

#endif /* STATE_H_ */


