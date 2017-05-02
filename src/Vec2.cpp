/*
 * Vec2.cpp
 *
 *  Created on: 20/03/2017
 *      Author: Eduardo
 */

#include "Vec2.h"

Vec2::Vec2() {
	x = 0;
	y = 0;
}

Vec2::Vec2(float a, float b){
	x = a;
	y = b;
}

Vec2* Vec2::SomaVec2(Vec2 a, Vec2 b){
	Vec2* resultado = new Vec2();
	resultado->x = a.x + b.x;
	resultado->y = a.y + b.y;

	return resultado;
}

Vec2* Vec2::SubtVec2(Vec2 a, Vec2 b){
	Vec2* resultado = new Vec2();
	resultado->x = a.x - b.x;
	resultado->y = a.x - b.y;

	return resultado;
}

Vec2* Vec2::MultpEsc(Vec2 a, float num){
	Vec2* resultado = new Vec2();
	resultado->x = a.x * num;
	resultado->y = a.y * num;

	return resultado;
}

float Vec2::Magnitude(Vec2 a){
	float base, altura;

	base = a.x;
	altura = a.y;

	return sqrt((base*base) + (altura*altura));
}

float Vec2::Dist(Vec2 a, Vec2 b){
	return Magnitude(*SubtVec2(a, b));
}
