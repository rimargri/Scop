#version 400
in vec4 text_coord;
out vec3 frag_colour;

in float PrimitiveID;

uniform sampler2D our_texture;
uniform float mix_value;

void main() {
 	vec3 tex_color = texture(our_texture, text_coord.yz).xyz;
	float value = float(int(PrimitiveID) % 255) / 255.0;
	vec3 tri_color = vec3(value, value, value);

	vec3 result = mix(tri_color, tex_color, mix_value);
	frag_colour = result;
}
