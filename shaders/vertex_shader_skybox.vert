#version 400 core
in vec3 vp;

out vec3 text_coords;

uniform mat4 projection;
// uniform mat4 view;

void main()
{
    text_coords = vp;
    gl_Position = /* projection *  */vec4(vp, 1.0);
    // gl_Position = projection * view * vec4(aPos, 1.0);
} 
