/*
 * Resources.h
 *
 *  Created on: 30/03/2017
 *      Author: Eduardo
 */

#ifndef RESOURCES_H_
#define RESOURCES_H_

#include <SDL_image.h>
#include <string>
#include "Game.h"
#include <stdlib.h>
#include <unordered_map>

class Resources {
public:
	static SDL_Texture* GetImage(std::string file);
	static void ClearImages();

private:
	static std::unordered_map<std::string, SDL_Texture*> imageTable;
};

#endif /* RESOURCES_H_ */
