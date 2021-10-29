#ifndef __POINT_H__
#define __POINT_H__

struct point {
	float x;
	float y;
};

struct point* create_point(float x, float y);

#endif /* __POINT_H__ */
