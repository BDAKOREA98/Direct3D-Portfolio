#pragma once

class DepthStencilState
{
public:
	DepthStencilState();
	~DepthStencilState();

	void SetState(UINT stencilRef = 1);

	void ChangeState();

	void DepthEnable(bool value);

private:
	ID3D11DepthStencilState* state = nullptr;

	D3D11_DEPTH_STENCIL_DESC desc = {};
};
