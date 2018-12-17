#version 330 core
layout (location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
//layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec3 ourColor;
out vec2 TexCoord;
out vec3 Normal;
out vec3 FragPos;


uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    // 注意乘法要从右向左读
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    TexCoord=aTexCoord;
	//在世界空间中进行所有的光照计算，因此我们需要一个在世界空间中的顶点位置
	FragPos = vec3(model * vec4(aPos, 1.0));
	Normal = aNormal;
}