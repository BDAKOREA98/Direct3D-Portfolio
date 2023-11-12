// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "__Other/targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <functional>

#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>
#include <DirectXCollision.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "dxguid.lib")

#include "DirectXTex.h"
#include "DirectXTex.inl"

#pragma comment(lib, "DirectXTex.lib")

using namespace std;
using namespace DirectX;

#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"

#pragma comment(lib, "ImGui.lib")

#include "ImGuiFileDialog.h"

#include <Shlwapi.h>

#pragma comment(lib, "shlwapi.lib")

#define WIN_WIDTH 1280.0f
#define WIN_HEIGHT 720.0f

#define DEVICE Device::GetInstance()->GetDevice()
#define DC     Device::GetInstance()->GetDC()

#define KEY_UP(p)    Keyboard::GetInstance()->Up(p)
#define KEY_DOWN(p)  Keyboard::GetInstance()->Down(p)
#define KEY_PRESS(p) Keyboard::GetInstance()->Press(p)

#define CAMERA Camera::GetInstance()->GetTransform()

#define SCENE SceneManager::GetInstance()

#define RS StateManager::GetInstance()->GetRS()

#define Dialog ImGuiFileDialog::Instance()

#define MAX_BONE 256
#define MAX_FRAME_KEY 512

#define MAX_INSTANCE 128
#define MAX_LIGHT    10

#define LERP(start, end, t) (start + (end - start) * t)

typedef XMMATRIX Matrix;
typedef XMFLOAT4 Vector4;
typedef XMFLOAT2 Vector2;

#include "Utility/Singleton.h"
#include "Utility/Vector3.h"
#include "Utility/Time.h"
#include "Utility/Keyboard.h"
#include "Utility/Utility.h"
#include "Utility/BinaryReader.h"
#include "Utility/BinaryWriter.h"
#include "Utility/MyMath.h"

using namespace Utility;
using namespace MyMath;

#include "Object/Transform.h"

#include "System/Device.h"

#include "Render/Shader/Shader.h"
#include "Render/Shader/VertexShader.h"
#include "Render/Shader/PixelShader.h"
#include "Render/Shader/ComputeShader.h"

#include "Render/Buffer/VertexLayout.h"
#include "Render/Buffer/VertexBuffer.h"
#include "Render/Buffer/IndexBuffer.h"
#include "Render/Buffer/ConstBuffer.h"
#include "Render/Buffer/GlobalBuffer.h"
#include "Render/Buffer/RawBuffer.h"
#include "Render/Buffer/StructuredBuffer.h"


#include "Render/Texture/Texture.h"
#include "Render/Mesh.h"
#include "Render/Material.h"

#include "Render/State/SamplerState.h"
#include "Render/State/RasterizerState.h"


#include "Render/State/StateManager.h"





#include "System/Environment.h"
#include "System/Camera.h"

#include "Object/Basic/Cube.h"
#include "Object/Basic/Quad.h"
#include "Object/Basic/TextureCube.h"
#include "Object/Basic/Sphere.h"

#include "Object/Landscape/Terrain.h"
#include "Object/Landscape/TerrainEditor.h"


#include "Scene/Scene.h"
#include "Scene/TutorialScene.h"
#include "Scene/TextureScene.h"
#include "Scene/TerrainScene.h"
#include "Scene/TerrainEditorScene.h"

#include "Scene/GridScene.h"
#include "Scene/SceneManager.h"


#include "Program.h"



extern HWND hWnd;
extern Vector3 mousePos;