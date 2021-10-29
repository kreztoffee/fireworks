#version 400 core

layout (location = 0) in vec2 pos;
layout (location = 1) in vec4 col;

uniform mat4 proj;

out vec4 col_out;

void main() {
	gl_Position = proj * vec4(pos.x, pos.y, 0.5, 1.0);
	col_out = col;
}
