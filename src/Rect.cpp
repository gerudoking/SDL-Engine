/*
 * Rect.cpp
 *
 *  Created on: 20/03/2017
 *      Author: Eduardo
 */

#include "Rect.h"

Rect::Rect() {
	x = 0;
	y = 0;
	w = 0;
	h = 0;
}

Rect::Rect(float a, float b, float c, float d){
	x = a;
	y = b;
	w = c;
	h = d;
}

bool Rect::IsInside(float a, float b){
	if((a >= x)&&(a <= w + x)&&(b >= y)&&(b <= h + y))
		return true;
	else
		return false;
}

Vec2 Rect::BoxCenter(){
	Vec2 v;

	v.x = x + w/2;
	v.y = y + h/2;

	return v;
}
