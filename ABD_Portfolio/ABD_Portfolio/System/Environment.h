#pragma once

class Environment : public Singleton<Environment>
{
	friend class Singleton;
private:
	Environment();
	~Environment();

	void CreatePerspective();
	void CreateOrthographic();

	void DebugLight(int lightIndex);

public:
	void SetViewport(UINT width = WIN_WIDTH, UINT height = WIN_HEIGHT);
	void SetEnvironment();
	void PostSet();

	void PostRender();

	Matrix GetPersMatrix() { return persMatrix; }

private:
	MatrixBuffer* persBuffer;
	Matrix         persMatrix;

	MatrixBuffer* orthoBuffer;
	Matrix         orthoMatrix;

	ViewBuffer* UIViewBuffer;

	LightBuffer* lightBuffer;
};
