#pragma once

class Quad : public Transform
{
public:
	Quad(Vector2 size = { 1, 1 });
	~Quad();

	void Render();

private:
	Material* material = nullptr;
	Mesh*     mesh     = nullptr;

	vector<VertexTextureNormal> vertices;
	vector<UINT>                 indices;

	MatrixBuffer* worldBuffer = nullptr;
};
