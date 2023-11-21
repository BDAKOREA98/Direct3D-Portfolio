#pragma once

class GeometryShader : public Shader
{
	friend class Shader;
public:
	GeometryShader(wstring file);
	~GeometryShader();

	virtual void SetShader() override;
private:
	ID3D11GeometryShader* shader;
};
