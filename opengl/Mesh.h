#pragma once
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <vector>
#include <string>
#include "Shader.h"
using namespace std;

//������
//һ������Ӧ��������Ҫһϵ�еĶ��㣬ÿ���������һ��λ��������һ����������һ����������������
//����ṹ  �����Բ�����ɫ��Ϣ�ȡ���
struct Vertex {
	glm::vec3 Position;    //λ����Ϣ
	glm::vec3 Normal;      //������
	glm::vec2 TexCoords;  //��������
	glm::vec3 Tangent;
	glm::vec3 Bitangent;
};
// ����ṹ
//�����������id�Լ��������ͣ���������������ͼ�����Ǿ������ͼ,��ͼ��λ��
struct Texture {
	unsigned int id;
	string type;
	string path;
};



class Mesh
{
public:
	/*  ��������  */
	vector<Vertex> vertices;        //��������
	vector<unsigned int> indices;   //������ͼ����������
	vector<Texture> textures;       //��ͼ����
	/*  ����  */
	Mesh();
	~Mesh();
	Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);
	void Draw(Shader shader);
private:
	/*  ��Ⱦ����  */
	unsigned int VAO, VBO, EBO;
	/*  ����  */
	void setupMesh();
};

