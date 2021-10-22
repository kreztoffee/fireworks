#ifndef __PARTICLE_H__
#define __PARTICLE_H__

#define MAX_NUM_PARTICLES 256
#define GRAVITY 10

struct particle {
	float xpos;
	float ypos;
	float life;
};

static int particle_cur = 0;

void add_particle(float xpos, float ypos);
void update_particles();
void render_particles();

struct particle particles[MAX_NUM_PARTICLES];

#endif /* __PARTICLE_H__ */
