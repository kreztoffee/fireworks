#include "emitter.h"
#include <math.h>

#include "particle.h"
#include "vec.h"
#include "color.h"

void emit_particles(struct point* pos, int number, float force) {
	float rand_force;
	float angle;
	struct vec vel;
	struct color col;

	for (int i = 0; i < number; ++i) {
		rand_force = force * ((float) (rand() & 4095) / 4095.0f);
		angle = (2.0f * (float) M_PI / 4096.0f) * (float) (rand() & 4095);
		vel.x = rand_force * (float) cosf(angle);
		vel.y = rand_force * (float) sinf(angle);
		set_random_color(&col);
		add_particle(pos, &vel, &col);
	}
}
