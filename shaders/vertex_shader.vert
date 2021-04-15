#version 400
layout (location = 0) in vec3 vp;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 tex_coord;
uniform mat4 mvp;
out vec3 out_color;
out vec2 out_tex_coord;
void main() {
	gl_Position = mvp * vec4(vp, 1.0);
	out_color = color;
	out_tex_coord = tex_coord;
}
