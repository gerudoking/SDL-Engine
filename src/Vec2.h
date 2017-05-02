/*
 * Vec2.h
 *
 *  Created on: 20/03/2017
 *      Author: Eduardo
 */

#ifndef VEC2_H_
#define VEC2_H_

#include <cmath>

class Vec2 {
public:
	Vec2();
	Vec2(float a, float b);
	Vec2* SomaVec2(Vec2 a, Vec2 b);
	Vec2* SubtVec2(Vec2 a, Vec2 b);
	Vec2* MultpEsc(Vec2 a, float num);
	float Magnitude(Vec2 a);
	float Dist(Vec2 a, Vec2 b);

	float x;
	float y;
};

#endif /* VEC2_H_ */
