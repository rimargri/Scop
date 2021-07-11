#version 400
// layout (location = 0) in vec3 vp;
in vec3 vp;
uniform mat4 mvp;
uniform mat4 model_matrix;
out vec4 text_coord;

void main() {
	gl_Position = mvp * vec4(vp, 1.0);
	// text_coord = model_matrix * vec4(vp, 1.0);
	text_coord = vec4(vp, 1.0);
}


// https://learnopengl.com/Lighting/Basic-Lighting