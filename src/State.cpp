/*
 * State.cpp
 *
 *  Created on: 14/03/2017
 *      Author: Eduardo
 */

#include "State.h"
#include "Face.h"
#include "Alien.h"
#include "Penguins.h"
#include "InputManager.h"
#include "Camera.h"
#include "Collision.h"
#include <SDL.h>

State::State(){
	quitRequested = false;
	LoadAssets();
	Penguins* p = new Penguins(704, 640);
	AddObject(new Alien(512, 300, 4));
	AddObject(p);

	Camera::Follow(p);
}

State::~State(){
	objectArray.clear();
}

void State::Update(){
	int i = 0;
	std::vector<std::unique_ptr<GameObject>>::iterator it;

	Camera::Update(Game::GetInstance()->GetDeltaTime());

	if(InputManager::GetInstance().QuitRequested() || InputManager::GetInstance().IsKeyDown(ESCAPE_KEY)){
        quitRequested = true;
    }

    for(unsigned i = 0; i < objectArray.size(); i++) {
			for(unsigned j = i+1; j < objectArray.size(); j++) {
				if(objectArray.at(j)->Is("Animation")) {

				}
				else if(Collision::IsColliding(objectArray.at(i)->box, objectArray.at(j)->box, objectArray.at(i)->rotation, objectArray.at(j)->rotation)) {
					objectArray.at(i)->NotifyCollision(*objectArray.at(j));
					objectArray.at(j)->NotifyCollision(*objectArray.at(i));
				}
			}
		}

    for(unsigned i = 0; i < objectArray.size(); i++){
    	objectArray.at(i)->Update(Game::GetInstance()->GetDeltaTime());
    }

	for(it = objectArray.begin(); it < objectArray.end(); it++, i++){
		if(objectArray.at(i)->IsDead()){
			objectArray.erase(objectArray.begin()+i);
		}
	}
	//std::cout << "tamanho do array: " << objectArray.size();
}

void State::Render(){
	std::vector<std::unique_ptr<GameObject>>::iterator it;

	bg->Render(0, 0);
	tileMap->RenderLayer(0, Camera::pos.x, Camera::pos.y);
	for(unsigned i = 0; i < objectArray.size(); i++){
		//std::cout << "\nloop de render de objects\n";
		objectArray.at(i)->Render(Camera::pos.x, Camera::pos.y);
	}
	tileMap->RenderLayer(1, Camera::pos.x * 1.5, Camera::pos.y * 1.5);
}

void State::LoadAssets(){
	bg = new Sprite("img/ocean.jpg");
	tileSet = new TileSet(64, 64, "img/tileset.png");
	tileMap = new TileMap("map/tileMap.txt", tileSet);
}

bool State::QuitRequested(){
	return this->quitRequested;
}

void State::AddObject(GameObject* obj){
	//double ang = rand() % (360);
	//ang = ang*(3.14/180);
	std::cout << "Adicionou objeto\n";
	objectArray.emplace_back(obj);

	std::cout << "tamanho do array: " << objectArray.size();
}
