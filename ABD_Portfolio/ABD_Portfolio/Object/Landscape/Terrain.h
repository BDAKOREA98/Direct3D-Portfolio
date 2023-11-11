#pragma once

class Terrain : public Transform
{
public:
	Terrain(wstring diffuseFile, wstring heightFile);
	~Terrain();

	void Render();

private:
	void CreateMesh();
	void CreateNormal();

private:
	vector<VertexTextureNormal> vertices;
	vector<UINT>                 indices;

	Material* material;
	Mesh*     mesh;

	MatrixBuffer* worldBuffer;

	UINT  width = 10;
	UINT height = 10;

	Texture* heightMap;

	const float MAP_HEIGHT = 20.0f;
};
