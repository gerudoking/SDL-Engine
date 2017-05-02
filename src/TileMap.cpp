/*
 * TileMap.cpp
 *
 *  Created on: 25/03/2017
 *      Author: Eduardo
 */

#include "TileMap.h"

TileMap::TileMap(std::string file, TileSet* ts) {
	Load(file);
	tileSet = ts;
}

void TileMap::Load(std::string file){
	std::ifstream f;
	std::string num;
	f.open(file.c_str(), std::ios::in);
	if(f.is_open()){
		getline(f, num, ',');
		//std::cout << "leu: " << num << std::endl;
		mapWidth = atoi(num.c_str());
		getline(f, num, ',');
		//std::cout << "leu: " << num << std::endl;
		mapHeight = atoi(num.c_str());
		getline(f, num, ',');
		//std::cout << "leu: " << num << std::endl;
		mapDepth = atoi(num.c_str());
		while(getline(f, num, ',')){
			tileMatrix.push_back(atoi(num.c_str())-1);
			//std::cout << "leu: " << num << std::endl;
			//std::cout << "atoi: " << atoi(num.c_str())-1 << std::endl;
		}
	}
	else{
		std::cout<< "f.open: unable to open file: " << file.c_str();
	}
}

void TileMap::SetTileSet(TileSet* ts){
	tileSet = ts;
}

int& TileMap::At(int x, int y, int z){
	//std::cout << "x:" << x << std::endl;
	//std::cout << "y:" << y << std::endl;
	//std::cout << "z:" << z << std::endl;
	//std::cout << "retorno de At" << x + (y*mapWidth) + (z*mapWidth*mapHeight) << std::endl;
	return tileMatrix.at(x + (y*mapWidth) + (z*mapWidth*mapHeight));
}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY){
	int i, j;
	int tileWidth = tileSet->GetTileWidth();
	int tileHeight = tileSet->GetTileHeight();
	for(j = 0; j < mapHeight; j++){
		for(i = 0; i < mapWidth; i++){
			tileSet->Render(At(i, j, layer), i*tileWidth - cameraX, j*tileHeight - cameraY);
		}
	}
}

void TileMap::Render(int cameraX, int cameraY){
	for(int i = 0; i < mapDepth; i++){
		RenderLayer(i, cameraX, cameraY);
	}
}

int TileMap::GetWidth(){
	return mapWidth;
}

int TileMap::GetHeight(){
	return mapHeight;
}

int TileMap::GetDepth(){
	return mapDepth;
}
