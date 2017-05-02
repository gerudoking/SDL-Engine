/*
 * Rect.h
 *
 *  Created on: 20/03/2017
 *      Author: Eduardo
 */

#ifndef RECT_H_
#define RECT_H_

#include "Vec2.h"

class Rect {
public:
	Rect();
	Rect(float a, float b, float c, float d);

	bool IsInside(float a, float b);
	Vec2 BoxCenter();

	float x;
	float y;
	float w;
	float h;
};

#endif /* RECT_H_ */
