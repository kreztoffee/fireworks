#ifndef __PARTICLE_H__
#define __PARTICLE_H__

#include "graphics_helpers.h"
#include "point.h"
#include "vec.h"
#include "vertex.h"
#include "color.h"

#define MAX_NUM_PARTICLES 2048
#define GRAVITY -9.81f
#define LIFE_SPAN 8.0f

struct particle {
	float x, y;
	float vx, vy;
	uint8_t r, g, b, a;
	float life;
	int active;
};

void init_particle_system();

void add_particle(struct point* pos, struct vec* vel, struct color* col);
void update_particles(float dt);
void add_to_render(struct particle* p, int vi);
void bind_to_vertex_array();
void render_particles(GLuint basic_prog_id);

struct particle particles[MAX_NUM_PARTICLES];

#endif /* __PARTICLE_H__ */
