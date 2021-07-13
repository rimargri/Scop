#version 400 core
in vec3 text_coords;
out vec4 frag_colour;
uniform samplerCube skybox;

void main()
{    
    frag_colour = texture(skybox, text_coords);
}