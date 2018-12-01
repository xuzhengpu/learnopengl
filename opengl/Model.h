#pragma once
#include "Mesh.h"
#include "assimp/Importer.hpp"
#include <assimp/scene.h>
#include <assimp/postprocess.h>
using namespace std;
class Model
{
public:
	vector<Texture> textures_loaded;
	/*  ����   */
	Model();
	~Model();
	Model(string path)
	{
		loadModel(path);
	}
	void Draw(Shader shader);
private:
	/*  ģ������  */
	vector<Mesh> meshes;
	string directory;
	/*  ����   */
	void loadModel(string path);
	void processNode(aiNode *node, const aiScene *scene);
	Mesh processMesh(aiMesh *mesh, const aiScene *scene);
	vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type,
		string typeName);
};

