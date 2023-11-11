#pragma once

class Sphere : public Transform
{
	typedef VertexTextureNormalTangent VertexType;
public:
	Sphere(float radius = 1.0f, UINT sliceCount = 20, UINT stackCount = 10);
	~Sphere();

	void Render();

	Material* GetMaterial() { return material; }

private:
	void CreateMesh();
	void CreateTangent();

private:
	Material* material = nullptr;
	Mesh*     mesh     = nullptr;

	vector<VertexType> vertices;
	vector<UINT>        indices;

	MatrixBuffer* worldBuffer = nullptr;

	float radius;
	UINT  sliceCount;
	UINT  stackCount;
};
