#include "framework.h"
#include "Program.h"

Program::Program()
{
	Initialize();

	//scene = new TutorialScene();
	//scene = new TextureScene();
	//scene = new TerrainScene();
	scene = new TerrainEditorScene();
}


Program::~Program()
{
	delete scene;

	Release();
}

void Program::Update()
{
	scene->Update();

	Time::GetInstance()->Update();
	Keyboard::GetInstance()->Update();
	Camera::GetInstance()->Update();
}

void Program::Render()
{
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	if (isWireFrame)
	{
		RS->ChangeState(D3D11_FILL_WIREFRAME);
	}
	else
	{
		RS->ChangeState(D3D11_FILL_SOLID);
	}

	scene->PreRender();

	Device::GetInstance()->Clear();

	Environment::GetInstance()->SetEnvironment();

	scene->Render();
	Time::GetInstance()->Render();


	scene->PostRender();
	Camera::GetInstance()->PostRender();
	Environment::GetInstance()->PostRender();

	ImGui::Checkbox("WireFrame", &isWireFrame);

	ImGui::Render();

	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	Device::GetInstance()->Present();
}

void Program::Initialize()
{
	//Device::GetInstance();
	StateManager::GetInstance();
	Environment::GetInstance();
	Keyboard::GetInstance();
	Time::GetInstance();

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui::StyleColorsDark();
	ImGui_ImplWin32_Init(hWnd);
	ImGui_ImplDX11_Init(DEVICE, DC);
}

void Program::Release()
{
	Time::Delete();
	Device::Delete();
	Shader::Delete();
	Keyboard::Delete();
	Environment::Delete();
	StateManager::Delete();
	Camera::Delete();
	Texture::Delete();

	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
}
