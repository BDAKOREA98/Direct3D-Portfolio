#pragma once

class Material
{
public:
	Material();
	Material(wstring file);
	~Material();

	void SetVertexShader(wstring file);
	void SetPixelShader(wstring file);

	void SetShader(wstring file);

	void SetMaterial();

	void SetDiffuseMap (wstring file);
	void SetSpecularMap(wstring file);
	void SetNormalMap  (wstring file);

	MaterialBuffer* GetBuffer() { return buffer; }

	void PostRender();

	void SelectMap();

private:
    VertexShader* vertexShader = nullptr;
     PixelShader*  pixelShader = nullptr;

	 Texture*  diffuseMap = nullptr;
	 Texture* specularMap = nullptr;
	 Texture*   normalMap = nullptr;

	 MaterialBuffer* buffer = nullptr;

	 string projectDir;
	 
	 static string ID;
};
