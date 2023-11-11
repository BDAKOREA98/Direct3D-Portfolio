#include "Framework.h"
#include "TerrainScene.h"

TerrainScene::TerrainScene()
{
	terrain = new Terrain(L"Landscape/Dirt.png", L"HeightMap/HeightMap.png");
}

TerrainScene::~TerrainScene()
{
	delete terrain;
}

void TerrainScene::Update()
{
	terrain->Update();
}

void TerrainScene::PreRender()
{
}

void TerrainScene::Render()
{
	RS->ChangeState(D3D11_FILL_WIREFRAME);
	terrain->Render();
}

void TerrainScene::PostRender()
{
}

