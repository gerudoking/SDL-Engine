/*
 * Sprite.h
 *
 *  Created on: 14/03/2017
 *      Author: Eduardo
 */

#ifndef SPRITE_H_
#define SPRITE_H_

#include <SDL_image.h>
#include <string>
#include "Game.h"
#include "Resources.h"
#include <stdlib.h>

class Sprite {
public:
	Sprite();
	Sprite(std::string file, int frameCount = 1, float frameTime = 1);
	~Sprite();

	void Update(float dt);
	void SetFrame(int frame);
	void SetFrameCount(int frameCount);
	void SetFrameTime(float frameTime);

	void Open(std::string file);
	void SetClip(int x, int y, int w, int h);
	void Render(int x, int y, float angle = 0);
	int GetWidth();
	int GetHeight();
	bool IsOpen();
	void SetScaleX(float a);
	void SetScaleY(float a);
private:
	SDL_Texture* texture;
	int width;
	int height;
	SDL_Rect clipRect;
	SDL_Rect dstRect;
	float scaleX = 1;
	float scaleY = 1;
	int frameCount;
	int currentFrame;
	float timeElapsed;
	float frameTime;
};

#endif /* SPRITE_H_ */
