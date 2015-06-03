#version 330 core

in vec2 UV;
in float alpha;
out vec4 color;
uniform sampler2D diffuse;

void main()
{
	color = texture( diffuse, UV );
	color.a*=alpha;
}