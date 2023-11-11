#include "framework.h"
#include "Program.h"

Program::Program()
{
	Initialize();

	scene = new TutorialScene();
}

Program::~Program()
{
	delete scene;

	Release();
}

void Program::Update()
{
	scene->Update();
}

void Program::Render()
{
	scene->PreRender();

	Device::GetInstance()->Clear();

	scene->Render();

	scene->PostRender();

	Device::GetInstance()->Present();
}

void Program::Initialize()
{
	Device::GetInstance();
	Environment::GetInstance();
}

void Program::Release()
{
	Device::Delete();
	Shader::Delete();
	Environment::Delete();
}
