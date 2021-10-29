#version 400 core

in vec4 col_out;

out vec4 frag_color;

void main()
{
    frag_color = col_out;
}
