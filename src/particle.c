#include "particle.h"

GLuint particle_vao;
GLuint particle_vbo;
int num_verts_to_render;
struct vertex vertices[MAX_NUM_PARTICLES];

void init_particle_system() {
	for (int i = 0; i < MAX_NUM_PARTICLES; ++i) {
		particles[i].life = 0.0f;
		particles[i].active = 0;
	}
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glGenVertexArrays(1, &particle_vao);
	glBindVertexArray(particle_vao);
	glGenBuffers(1, &particle_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, particle_vbo);
	int stride = (2 * sizeof(float) + 4 * sizeof(uint8_t));
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, stride, (void*) 0);
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, stride, (void*) offsetof(struct vertex, r));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glPointSize(2.0f);
}

void add_particle(struct point* pos, struct vec* vel, struct color* col) {
	for (int i = 0; i < MAX_NUM_PARTICLES; ++i) {
		if (particles[i].active < 1) {
			particles[i].x = pos->x;
			particles[i].y = pos->y;
			particles[i].vx = vel->x;
			particles[i].vy = vel->y;
			particles[i].r = col->r;
			particles[i].g = col->g;
			particles[i].b = col->b;
			particles[i].a = col->a;
			particles[i].life = 1.0f;
			particles[i].active = 1;
			break;
		}
	}
}

void update_particles(float dt) {
	struct particle* p = &particles[0];
	num_verts_to_render = 0;
	for (int i = 0; i < MAX_NUM_PARTICLES; ++i) {
		if (p->active > 0) {
			p->life -= (1.0f/LIFE_SPAN) * dt;
			if (p->life <= 0.0f) {
				p->active = 0;
				p++;
				continue;
			}
			p->vy -= GRAVITY * dt;
			p->x += p->vx * dt;
			p->y += p->vy * dt;

			add_to_render(p, num_verts_to_render);
			num_verts_to_render++;
		}
		p++;
	}
	bind_to_vertex_array();
}

void add_to_render(struct particle* p, int vi) {
	struct vertex* v = &vertices[vi];
	v->x = p->x;
	v->y = p->y;
	v->r = p->r;
	v->g = p->g;
	v->b = p->b;
	v->a = (uint8_t)(p->life * 255);
}

void bind_to_vertex_array() {
	glBindBuffer(GL_ARRAY_BUFFER, particle_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),
				 vertices,
				 GL_DYNAMIC_DRAW);
}

void render_particles(GLuint basic_prog_id) {
	if(num_verts_to_render == 0) {
		return;
	}

	glUseProgram(basic_prog_id);
	glDrawArrays(GL_POINTS, 0, num_verts_to_render);
}
