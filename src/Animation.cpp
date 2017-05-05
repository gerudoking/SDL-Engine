/*
 * Animation.cpp
 *
 *  Created on: 23/04/2017
 *      Author: Eduardo
 */

 #include "Animation.h"

 Animation::Animation(float x, float y, float rotation, std::string sprite, int frameCount, float frameTime, bool ends){
 	sp = Sprite(sprite, frameCount, frameTime);
 	box.x = x;
 	box.y = y;
 	box.w = sp.GetWidth();
 	box.h = sp.GetHeight();
 	ends = false;
 	
 }

 void Animation::Update(float dt){
 	
 }

 void Animation::Render(){

 }

 bool Animation::IsDead(){

 }

 void Animation::NotifyCollision(GameObject* other){

 }

 bool Animation::Is(std::string type){

 }