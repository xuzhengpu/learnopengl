#version 330 core
out vec4 FragColor;
struct Material {
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float shininess;
};
uniform Material material;

struct Light {
	vec3 position;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

uniform Light light;

in vec3 ourColor;
in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;

uniform sampler2D ourTexture;
uniform sampler2D ourface;

uniform vec3 viewPos;
uniform vec3 lightPos;
uniform vec3 objectColor;
uniform vec3 lightColor;

void main()
{
	
	
	//漫反射
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(lightPos - FragPos);
	float diff = max(dot(norm, lightDir), 0.0);
	//镜面反射
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
   //环境光
	//vec3 ambient = light.ambient * material.ambient;
	//vec3 diffuse = light.diffuse * (diff * material.diffuse);
	vec3 ambient = light.ambient * vec3(texture(ourTexture, TexCoord));
	vec3 diffuse = light.diffuse * diff * vec3(texture(ourTexture, TexCoord));
	vec3 specular = light.specular * (spec * material.specular);

	vec3 result = (ambient + diffuse + specular) ;
	FragColor = vec4(result, 1.0);
    //FragColor = mix(texture(ourTexture, TexCoord), texture(ourface, TexCoord), 0.2);
	//FragColor = vec4(lightColor * objectColor, 1.0);
}