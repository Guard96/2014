#version 330 core

layout(location = 0) in vec4 vPos;

out vec2 UV;
out float alpha;
const vec2 uv_0 = vec2(0,0);
const vec2 uv_1 = vec2(1,0);
const vec2 uv_2 = vec2(1,1);
const vec2 uv_3 = vec2(0,1);

void main()
{
	if(vPos.z==0.0f)
		UV = uv_0;
	else if(vPos.z==1.0f)
		UV = uv_1;
	else if(vPos.z==2.0f)
		UV = uv_2;
	else
		UV = uv_3;
		
	alpha = vPos.w;
    gl_Position =  vec4(vPos.x, vPos.y, 0, 1);
}