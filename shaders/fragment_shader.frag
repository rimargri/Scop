#version 400
in vec4 vertex_color;
out vec4 frag_colour;
void main() {
  frag_colour = vertex_color;
}
