#version 400 core
in vec3 vp;

out vec3 text_coords;

uniform mat4 projection;
uniform mat4 rotation;

void main()
{
    text_coords = vp;
    gl_Position = projection * rotation * vec4(vp, 1.0);
} 
