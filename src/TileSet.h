/*
 * TileSet.h
 *
 *  Created on: 24/03/2017
 *      Author: Eduardo
 */

#ifndef TILESET_H_
#define TILESET_H_

#include "Sprite.h"
#include <string>

class Sprite;

class TileSet {
public:
	TileSet(int a, int b, std::string file);
	void Render(int index, float x, float y);
	int GetTileWidth();
	int GetTileHeight();

private:
	Sprite* tileSet;

	int rows;
	int columns;
	int tileWidth;
	int tileHeight;
};

#endif /* TILESET_H_ */
