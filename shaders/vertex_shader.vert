#version 400
in vec3 vp;
uniform mat4 mvp;
out vec4 text_coord;
out float PrimitiveID;

void main() {
	PrimitiveID = gl_VertexID / 3;

	gl_Position = mvp * vec4(vp, 1.0);
	// text_coord = model_matrix * vec4(vp, 1.0);
	text_coord = vec4(vp, 1.0);
}


// https://learnopengl.com/Lighting/Basic-Lighting
// https://triplepointfive.github.io/ogltutor/tutorials/tutorial25.html
// https://learnopengl.com/Advanced-OpenGL/Cubemaps