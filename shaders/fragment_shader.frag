#version 400
in vec4 text_coord;
out vec4 frag_colour;

uniform sampler2D our_texture;

void main() {
	// frag_colour = vec4(0.5, 0.0, 0.5, 1.0);
 	frag_colour = texture(our_texture, text_coord.xy);
}
