#include "framework.h"
#include "Program.h"

Program::Program()
{
	srand(time(NULL));

	Initialize();


	SCENE->Create("Grid", new GridScene());
	
	SCENE->Create("Map Tool", new TerrainEditorScene());

	SCENE->Add("Grid");
	SCENE->Add("Map Tool");
}


Program::~Program()
{
	SceneManager::Delete();

	Release();
}

void Program::Update()
{
	SCENE->Update();

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

	SCENE->PreRender();

	Device::GetInstance()->Clear();

	Environment::GetInstance()->SetEnvironment();

	SCENE->Render();
	Time::GetInstance()->Render();


	SCENE->PostRender();
	Camera::GetInstance()->Debug();
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
