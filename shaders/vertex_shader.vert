#version 400
layout (location = 0) in vec3 vp;
uniform mat4 mvp;
out vec4 vertex_color;
void main() {
 	gl_Position = mvp * vec4(vp, 1.0);
	vertex_color = vec4(0.5, 0.0, 0.5, 1.0);
}
