/*
 * Game.h
 *
 *  Created on: 11/03/2017
 *      Author: Eduardo
 */

#ifndef GAME_H_
#define GAME_H_

#include <stdlib.h>
#include "SDL.h"
#include "SDL_image.h"
#include "State.h"
#include <string>
#include <time.h>


class State;

class Game {
public:
	Game(std::string title, int width, int height);
	~Game();
	void Run();
	SDL_Renderer* GetRenderer();
	State* GetState();
	static Game* GetInstance();
	float GetDeltaTime();
private:
	static Game* instance;
	SDL_Window* window;
	SDL_Renderer* renderer;
	State* state;
	int frameStart;
	float dt;

	void CalculateDeltaTime();
};

#endif /* GAME_H_ */
