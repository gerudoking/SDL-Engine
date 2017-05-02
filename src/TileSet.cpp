/*
 * TileSet.cpp
 *
 *  Created on: 24/03/2017
 *      Author: Eduardo
 */

#include "TileSet.h"

TileSet::TileSet(int a, int b, std::string file){
	tileSet = new Sprite(file);
	this->tileWidth = a;
	this->tileHeight = b;

	columns = tileSet->GetWidth()/tileWidth;
	rows = tileSet->GetHeight()/tileHeight;
	//std::cout << "rows: " << rows << std::endl;
	//std::cout << "columns" << columns << std::endl;
}

void TileSet::Render(int index, float x, float y){
	int i, j;
	//std::cout << "index:" << index << std::endl;
	//std::cout << "x:" << x << std::endl;
	//std::cout << "y:" << y << std::endl;
	if(((int)index >= 0) && ((int)index <= rows*columns)){
		int row = index / columns;
		j = row *tileHeight;
		int column = index - row*columns;
		i = column * tileWidth;

		//std::cout << "image height " << tileSet->GetHeight() << std::endl;
		//std::cout << "tile height " << tileHeight << std::endl;
		//std::cout << "j " << j << std::endl;
		tileSet->SetClip(i, j, tileWidth, tileHeight);
		tileSet->Render((int)x, (int)y);
	}
}

int TileSet::GetTileWidth(){
	return tileWidth;
}

int TileSet::GetTileHeight(){
	return tileHeight;
}
