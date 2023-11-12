#include "Framework.h"
#include "GridScene.h"

GridScene::GridScene()
{
	material = new Material(L"Tutorial");

	worldBuffer = new WorldBuffer;

	CreateMesh();
}

GridScene::~GridScene()
{
	delete material;
	delete vertexBuffer;
	delete worldBuffer;
}

void GridScene::Update()
{
}

void GridScene::PreRender()
{
}

void GridScene::Render()
{
	worldBuffer->SetVSBuffer(0);

	material->SetMaterial();
	vertexBuffer->IASetBuffer(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);

	DC->Draw(vertices.size(), 0);
}

void GridScene::PostRender()
{
}

void GridScene::CreateMesh()
{
	vertices.emplace_back(-width, 0, 0, 1, 0, 0, 1);
	vertices.emplace_back(+width, 0, 0, 1, 0, 0, 1);

	vertices.emplace_back(0, -width, 0, 0, 1, 0, 1);
	vertices.emplace_back(0, +width, 0, 0, 1, 0, 1);

	vertices.emplace_back(0, 0, -width, 0, 0, 1, 1);
	vertices.emplace_back(0, 0, +width, 0, 0, 1, 1);

	int halfW =  width * 0.5f;
	int halfH = height * 0.5f;

	for (int x = -halfW; x <= halfW; x++)
	{
		if (x == 0) continue;

		vertices.emplace_back(x, 0, -halfW, 0.5f, 0.5f, 0.5f, 1.0f);
		vertices.emplace_back(x, 0, +halfW, 0.5f, 0.5f, 0.5f, 1.0f);
	}

	for (int z = -halfH; z <= halfH; z++)
	{
		if (z == 0) continue;

		vertices.emplace_back(-halfH, 0, z, 0.5f, 0.5f, 0.5f, 1.0f);
		vertices.emplace_back(+halfH, 0, z, 0.5f, 0.5f, 0.5f, 1.0f);
	}

	vertexBuffer = new VertexBuffer(vertices);
}
