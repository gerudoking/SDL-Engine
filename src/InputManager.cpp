/*
 * InputManager.h
 *
 *  Created on: 03/04/2017
 *		Author: Eduardo
 */

 #include "InputManager.h"

 InputManager* InputManager::instance = nullptr;

 InputManager::InputManager(){
 	for(int i = 0; i < 6; i++){
 		mouseState[i] = false;
 		mouseUpdate[i] = 0;
 	}

 	quitRequested = false;
 	updateCounter = 0;
 	mouseX = 0;
 	mouseY = 0;
 }

 void InputManager::Update(){
 	SDL_Event event;

 	SDL_GetMouseState(&mouseX, &mouseY);

 	if(!(event.key.repeat == 1)){
 		while(SDL_PollEvent(&event)){
 			if(event.type == SDL_QUIT){
 				quitRequested = true;
 			}

 			if(event.type == SDL_MOUSEBUTTONDOWN){
 				mouseState[event.button.button] = true;
 				mouseUpdate[event.button.button] = updateCounter;
 			}

 			if(event.type == SDL_MOUSEBUTTONUP){
 				mouseState[event.button.button] = false;
 				mouseUpdate[event.button.button] = updateCounter;
 			}

 			if(event.type == SDL_KEYDOWN){
 				keyState[event.key.keysym.sym] = true;
 				keyUpdate[event.key.keysym.sym] = updateCounter;
 			}

 			if(event.type == SDL_KEYUP){
 				keyState[event.key.keysym.sym] = false;
 				keyUpdate[event.key.keysym.sym] = updateCounter;
 			}
 		}
 	}

 	updateCounter++;
 }

 bool InputManager::KeyPress(int key){
 	return ((keyUpdate[key] == updateCounter - 1) ? (keyState[key]) : (false));
 }

 bool InputManager::KeyRelease(int key){
 	return ((keyUpdate[key] == updateCounter - 1) ? (!keyState[key]) : (false));
 }

 bool InputManager::IsKeyDown(int key){
 	return keyState[key];
 }

 bool InputManager::MousePress(int button){
 	return ((mouseUpdate[button] == updateCounter - 1) ? (mouseState[button]) : (false));
 }

 bool InputManager::MouseRelease(int button){
 	return ((mouseUpdate[button] == updateCounter - 1) ? (!mouseState[button]) : (false));
 }

 bool InputManager::IsMouseDown(int button){
 	return mouseState[button];
 }

 int InputManager::GetMouseX(){
 	return mouseX;
 }

 int InputManager::GetMouseY(){
 	return mouseY;
 }

 bool InputManager::QuitRequested(){
 	return quitRequested;
 }

 InputManager& InputManager::GetInstance(){
 	if(instance == nullptr)
 		instance = new InputManager();
 	return *instance;
 }
