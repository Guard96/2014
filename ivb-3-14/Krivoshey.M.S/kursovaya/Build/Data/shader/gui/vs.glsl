#version 330 core

layout(location = 0) in vec2 vPos;
layout(location = 1) in vec2 vertexUV;

out vec2 UV;

uniform mat3 MVP;
uniform int invert_y;

void main()
{
	vec3 temp = MVP * vec3(vPos, 1);
	temp.z=0;
	
	if(invert_y)
		temp.y = -temp.y;
		
    gl_Position =  vec4(temp, 1);
    UV = vertexUV;
}