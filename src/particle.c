#include "particle.h"

void add_particle(float xpos, float ypos) {
	particle_cur++;
	if (particle_cur >= MAX_NUM_PARTICLES) {
		particle_cur = 0;
	}
	particles[particle_cur].xpos = xpos;
	particles[particle_cur].ypos = ypos;
	particles[particle_cur].life = 100.0f;
}

void update_particles() {
	for (int i = 0; i < MAX_NUM_PARTICLES; ++i) {
		if (particles[particle_cur].life > 0) {
			// update

		}
	}
}

void render_particles() {
	for (int i = 0; i < MAX_NUM_PARTICLES; ++i) {
		if (particles[particle_cur].life > 0) {
			// render
		}
	}
}
