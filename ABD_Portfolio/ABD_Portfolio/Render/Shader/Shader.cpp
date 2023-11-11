#include "Framework.h"
#include "Shader.h"

map<wstring, Shader*> Shader::shaders = {};

Shader::~Shader()
{
	blob->Release();
}

VertexShader* Shader::GetVS(wstring file)
{
	file = L"_Shader/Vertex" + file + L".hlsl";

	if (shaders.count(file) > 0)
		return (VertexShader*)shaders[file];

	shaders[file] = new VertexShader(file);

	return (VertexShader*)shaders[file];
}

PixelShader* Shader::GetPS(wstring file)
{
	file = L"_Shader/Pixel" + file + L".hlsl";

	if (shaders.count(file) > 0)
		return (PixelShader*)shaders[file];

	shaders[file] = new PixelShader(file);

	return (PixelShader*)shaders[file];
}

void Shader::Delete()
{
	for (pair<wstring, Shader*> shader : shaders)
		delete shader.second;

	shaders.clear();
}
