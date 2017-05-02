/*
 * Sprite.cpp
 *
 *  Created on: 14/03/2017
 *      Author: Eduardo
 */

#include "Sprite.h"

Sprite::Sprite() {
	texture = nullptr;
}


Sprite::Sprite(std::string file, int frameCount, float frameTime){
	texture = nullptr;
	this->frameCount = frameCount;
	this->frameTime = frameTime;
	timeElapsed = 0;
	currentFrame = 1;
	Open(file);
}

Sprite::~Sprite() {

}

void Sprite::Update(float dt){
	timeElapsed += dt;

	if (timeElapsed > frameTime){
		currentFrame++;
		if (currentFrame > frameCount){
			currentFrame = 1;
		}
	}

	SetClip((currentFrame - 1)*(width/frameCount), 0, (width/frameCount)*currentFrame, height);
}

void Sprite::SetFrame(int frame){
	currentFrame = frame;
	SetClip((currentFrame - 1)*(width/frameCount), 0, (width/frameCount)*currentFrame, height);
}

void Sprite::SetFrameCount(int fc){
	frameCount = fc;
}

void Sprite::SetFrameTime(float ft){
	frameTime = ft;
}

void Sprite::Open(std::string file){
	texture = Resources::GetImage(file);
	if(texture == nullptr){
		SDL_Log("IMG_LoadTexture: Unable to load texture: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

	SetClip(0, 0, width/frameCount, height);
	//SetClip(0, 0, width, height);
}

void Sprite::SetClip(int x, int y, int w, int h){
	clipRect.x = x;
	clipRect.y = y;
	clipRect.w = w;
	clipRect.h = h;
}

void Sprite::Render(int x, int y, float angle){
	dstRect.w = clipRect.w * scaleX;
	dstRect.h = clipRect.h * scaleY;
	dstRect.x = x - (dstRect.w - clipRect.w)/2;
	dstRect.y = y - (dstRect.h - clipRect.h)/2;
	SDL_RenderCopyEx(Game::GetInstance()->GetRenderer(), texture, &clipRect, &dstRect, angle, nullptr, SDL_FLIP_NONE);
}

int Sprite::GetWidth(){
	return (width/frameCount);
}

int Sprite::GetHeight(){
	return height;
}

bool Sprite::IsOpen(){
	if (texture != nullptr)
		return true;
	else
		return false;
}

void Sprite::SetScaleX(float a){
	scaleX = a;
}

void Sprite::SetScaleY(float a){
	scaleY = a;
}
