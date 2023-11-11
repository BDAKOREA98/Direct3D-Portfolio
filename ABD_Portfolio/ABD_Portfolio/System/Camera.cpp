#include "Framework.h"
#include "Camera.h"

Camera::Camera()
{
	viewBuffer = new ViewBuffer();

	transform = new Transform();

	transform->translation = { 60.0f, 100.0f, -80.0f };
	transform->rotation.x = 0.65f;

	Load();
}

Camera::~Camera()
{
	Save();

	delete transform;

	delete viewBuffer;
}

void Camera::Update()
{
	FreeMode();
}

void Camera::PostRender()
{
	Vector3 pos = transform->translation;
	Vector3 rot = transform->rotation;

	ImGui::Text("Camera Pos : %.3f, %.3f, %.3f", pos.x, pos.y, pos.z);
	ImGui::Text("Camera Rot : %.3f, %.3f, %.3f", rot.x, rot.y, rot.z);
}

Ray Camera::ScreenPointToRay(Vector3 screenPos)
{
	Ray ray;
	ray.origin = transform->translation;

	///////////////InvViewport///////////////

	Vector3 point;

	point.x = +(2.0f * screenPos.x) / WIN_WIDTH  - 1.0f;
	point.y = -(2.0f * screenPos.y) / WIN_HEIGHT + 1.0f;
	point.z =   1.0f; //FarZ


	/////////////InvProjection/////////////

	Matrix projection = Environment::GetInstance()->GetProjMatrix();

	XMFLOAT4X4 proj;
	
	XMStoreFloat4x4(&proj, projection);

	point.x /= proj._11;
	point.y /= proj._22;

	///////////////InvView//////////

	Matrix invView = transform->GetWorld();

	ray.direction = point * invView;
	ray.direction.Normalize();

	return ray;
}

void Camera::FreeMode()
{
	if (KEY_PRESS(VK_RBUTTON))
	{
		if (KEY_PRESS(VK_LSHIFT))
			moveSpeed = 50.0f;
		else
			moveSpeed = 20.0f;

		if (KEY_PRESS('A'))
			transform->translation += transform->Left()     * moveSpeed * Time::Delta();
														    
		if (KEY_PRESS('D'))								    
			transform->translation += transform->Right()    * moveSpeed * Time::Delta();

		if (KEY_PRESS('S'))
			transform->translation += transform->Backward() * moveSpeed * Time::Delta();

		if (KEY_PRESS('W'))
			transform->translation += transform->Forward()  * moveSpeed * Time::Delta();
														    
		if (KEY_PRESS('Q'))								    
			transform->translation += transform->Up()       * moveSpeed * Time::Delta();
														    
		if (KEY_PRESS('E'))								    
			transform->translation += transform->Down()     * moveSpeed * Time::Delta();

		Vector3 dir = mousePos - oldPos;

		transform->rotation.y += dir.x * rotSpeed * Time::Delta();
		transform->rotation.x += dir.y * rotSpeed * Time::Delta();

	}

	oldPos = mousePos;

	SetView();
}

void Camera::TargetMode()
{
}

void Camera::SetView()
{
	transform->Update();

	//Vector3   eyePos = transform->translation;
	//Vector3 focusPos = transform->translation + transform->Forward();
	//Vector3 upVector = transform->Up();
	//
	//viewMatrix = XMMatrixLookAtLH(eyePos, focusPos, upVector);

	viewMatrix = XMMatrixInverse(nullptr, transform->GetWorld());

	viewBuffer->SetData(viewMatrix, transform->GetWorld());
	viewBuffer->SetVSBuffer(1);
}

void Camera::Save()
{
	BinaryWriter data(L"CameraData");

	data.WriteData(transform->scale);
	data.WriteData(transform->rotation);
	data.WriteData(transform->translation);
}

void Camera::Load()
{
	BinaryReader data(L"CameraData");

	if (!data.Succeeded())
		return;

	transform->scale       = data.ReadVector3();
	transform->rotation    = data.ReadVector3();
	transform->translation = data.ReadVector3();
}
