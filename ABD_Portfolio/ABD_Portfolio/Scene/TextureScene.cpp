#include "Framework.h"
#include "TextureScene.h"

TextureScene::TextureScene()
{
	cube = new TextureCube();
	cube->SetLabel("Cube");

	CAMERA->translation = { 0, 3, -5 };

	cube2 = new Cube({ 1, 0, 0, 1});
	cube2->translation.x = 2;

	sphere = new Sphere();
	sphere->translation.x = -2;
	sphere->GetMaterial()->SetDiffuseMap(L"Landscape/Fieldstone_DM.tga");
	sphere->GetMaterial()->SetSpecularMap(L"Landscape/Fieldstone_SM.tga");
	sphere->GetMaterial()->SetNormalMap(L"Landscape/Fieldstone_NM.tga");
}

TextureScene::~TextureScene()
{
	delete cube;
	delete cube2;
	delete sphere;
}

void TextureScene::Update()
{
	  cube->Update();
	 cube2->Update();
	sphere->Update();

	  cube->rotation.x += Time::Delta();
	 cube2->rotation.x += Time::Delta();
	sphere->rotation.y += Time::Delta();
}

void TextureScene::PreRender()
{
}

void TextureScene::Render()
{
	  cube->Render();
	 cube2->Render();


	//RS->ChangeState(D3D11_FILL_WIREFRAME);
	sphere->Render();
	//RS->ChangeState(D3D11_FILL_SOLID);
}

void TextureScene::PostRender()
{
	cube->Debug();

	sphere->GetMaterial()->PostRender();
}
