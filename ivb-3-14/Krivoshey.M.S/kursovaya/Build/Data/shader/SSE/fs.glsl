#version 330 core

in vec2 UV;
out vec4 color;

uniform sampler2D diffuse;
uniform int diffuse_enable;

const vec3 gray = vec3(0.3, 0.59, 0.11);
const float brightThreshold = 0.5;

vec2 offsets[12] = vec2[](
	vec2(-0.001631, -0.002029),
	vec2(-0.004222, -0.00039),
	vec2(-0.003457, 0.0022685),
	vec2(-0.0010225, 0.003108),
	vec2(0.00482, -0.0009915),
	vec2(0.002367, -0.002413),
	vec2(0.002578, 0.003811),
	vec2(0.0009305, -0.004462),
	vec2(0.0025155, 0.0003125),
	vec2(0.00446, 0.002079),
	vec2(-0.00162, -0.0046575),
	vec2(-0.0039795, -0.0029525)
);

void main()
{
	vec4 result;
	
	vec4 sample = vec4(0,0,0,0);
	for(int n = 0; n < 12; n++)
		sample += texture(diffuse, UV + offsets[n]);
	sample /= 12;

	sample.rgb -= brightThreshold;
	sample = max(sample, 0.0f);
	sample.rgb /= (1.0f + sample.rgb);
	
	result = texture(diffuse, UV) + sample * 0.5;
	
	if(diffuse_enable==1) {
		float value = dot(result.rgb, gray);
		result = vec4(value,value,value,result.a);
	}
	color = result;
}