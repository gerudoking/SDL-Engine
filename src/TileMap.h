/*
 * TileMap.h
 *
 *  Created on: 25/03/2017
 *      Author: Eduardo
 */

#ifndef TILEMAP_H_
#define TILEMAP_H_

#include "TileSet.h"
#include <fstream>
#include <string>
#include <string.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <stdlib.h>

class TileSet;

class TileMap {
public:
	TileMap(std::string file, TileSet* tileSet);
	void Load(std::string file);
	void SetTileSet(TileSet* tileSet);
	int& At(int x, int y, int z = 0);
	void Render(int cameraX = 0, int cameraY = 0);
	void RenderLayer(int layer, int cameraX = 0, int cameraY = 0);
	int GetWidth();
	int GetHeight();
	int GetDepth();

private:
	std::vector<int> tileMatrix;
	TileSet* tileSet;
	int mapWidth;
	int mapHeight;
	int mapDepth;
};

#endif /* TILEMAP_H_ */
