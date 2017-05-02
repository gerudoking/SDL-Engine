/*
 * Game.cpp
 *
 *  Created on: 11/03/2017
 *      Author: Eduardo
 */

#include "Game.h"
#include "InputManager.h"

Game* Game::instance;

Game::Game(std::string title, int width, int height) {
	int flagsSDL, flagsImg;

	flagsSDL = SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER;
	flagsImg = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;

	dt = 0;
	frameStart = 0;

	srand(time(NULL));

	if (instance == nullptr){
		instance = this;
	}
	else{
		exit(EXIT_FAILURE);
	}

	if(SDL_Init(flagsSDL) != 0){
		SDL_Log("SDL_Init: Unable to initialize SDL: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	if(IMG_Init(flagsImg) != flagsImg){
		SDL_Log("IMG_Init: Unable to initialize SDL_image: %s\n", IMG_GetError());
		exit(EXIT_FAILURE);
	}

	this->window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
	if(this->window == nullptr){
		SDL_Log("SDL_CreateWindow: Unable to create window!");
		exit(EXIT_FAILURE);
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == nullptr){
		SDL_Log("SDL_CreateRenderer: Unable to create renderer!");
		exit(EXIT_FAILURE);
	}

	state = new State();
}

Game::~Game() {
	IMG_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

}

Game* Game::GetInstance(){
	return instance;
}

State* Game::GetState(){
	return state;
}

SDL_Renderer* Game::GetRenderer(){
	return renderer;
}

void Game:: Run(){
	while(state->QuitRequested() == false){
		CalculateDeltaTime();
		InputManager::GetInstance().Update();
		state->Update();
		state->Render();
		SDL_RenderPresent(renderer);
		SDL_Delay(33);
	}
}

void Game::CalculateDeltaTime(){
	dt = (SDL_GetTicks() - frameStart)/1000.0;
	frameStart = SDL_GetTicks();
}

float Game::GetDeltaTime(){
	return dt;
}
