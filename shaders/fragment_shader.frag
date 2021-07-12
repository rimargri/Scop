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





// grayscale shader:
// void main()										
// {
// 	vec4 color = texture(our_texture, text_coord.xy);
// 	float gray = dot(color.rgb, vec3(0.299, 0.587, 0.114));
//     vec3 grayscale = vec3(gray);
// 	frag_colour = vec4(grayscale, color.a);
// }

// https://gist.github.com/Volcanoscar/4a9500d240497d3c0228f663593d167a