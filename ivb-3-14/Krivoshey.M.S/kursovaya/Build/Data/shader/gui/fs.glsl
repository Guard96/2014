#version 330 core

in vec2 UV;
out vec4 color;
uniform sampler2D diffuse;
uniform vec4 colorMult;
uniform vec4 colorBack;
uniform int diffuse_enable;

const vec4 color_null = vec4(0,0,0,0);

void main()
{
	vec4 tex;
	if(diffuse_enable==1)
		tex = texture( diffuse, UV ).rgba;
	else
		tex = color_null;
	color = (colorBack * (1-tex.a) + tex) * colorMult;
}