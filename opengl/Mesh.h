#pragma once
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <vector>
#include <string>
#include "Shader.h"
using namespace std;

//网格类
//一个网格应该至少需要一系列的顶点，每个顶点包含一个位置向量、一个法向量和一个纹理坐标向量。
//顶点结构  还可以补充颜色信息等……
struct Vertex {
	glm::vec3 Position;    //位置信息
	glm::vec3 Normal;      //法向量
	glm::vec2 TexCoords;  //纹理坐标
	glm::vec3 Tangent;
	glm::vec3 Bitangent;
};
// 纹理结构
//储存了纹理的id以及它的类型，比如是漫反射贴图或者是镜面光贴图,贴图的位置
struct Texture {
	unsigned int id;
	string type;
	string path;
};



class Mesh
{
public:
	/*  网格数据  */
	vector<Vertex> vertices;        //顶点数据
	vector<unsigned int> indices;   //索引绘图的索引数据
	vector<Texture> textures;       //贴图数据
	/*  函数  */
	Mesh();
	~Mesh();
	Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);
	void Draw(Shader shader);
private:
	/*  渲染数据  */
	unsigned int VAO, VBO, EBO;
	/*  函数  */
	void setupMesh();
};

