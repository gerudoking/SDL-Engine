/*
 * Resources.cpp
 *
 *  Created on: 30/03/2017
 *      Author: Eduardo
 */

#include "Resources.h"

std::unordered_map<std::string, SDL_Texture*> Resources::imageTable;

SDL_Texture* Resources::GetImage(std::string file){
	SDL_Texture* texture;
	std::unordered_map<std::string, SDL_Texture*>::const_iterator it;
	it = imageTable.find(file);

	if(it == imageTable.end()){
		texture = IMG_LoadTexture(Game::GetInstance()->GetRenderer(), file.c_str());
		if(texture == nullptr){
			SDL_Log("IMG_LoadTexture: Unable to load texture: %s\n", SDL_GetError());
			exit(EXIT_FAILURE);
		}
		imageTable.emplace(file, texture);

		return texture;
	}
	else{
		return it->second;
	}
}

void Resources::ClearImages(){
	for(auto it = imageTable.begin(); it != imageTable.end(); ++it){
		SDL_DestroyTexture(it->second);
	}
}
