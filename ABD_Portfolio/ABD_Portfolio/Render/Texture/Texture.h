#pragma once

class Texture
{
private:
	Texture(ID3D11ShaderResourceView* srv, ScratchImage& image);
	~Texture();

public:
	static Texture* Get(wstring file);
	static Texture* Load(wstring file);
	static void Delete();

	void PSSetShaderResources(UINT slot);

	vector<Vector4> ReadPixels();

	Vector2 GetSize()
	{
		return Vector2(image.GetMetadata().width, image.GetMetadata().height);
	}

	wstring GetPath() { return path; }

private:
	ID3D11ShaderResourceView* srv = nullptr;

	ScratchImage image;

	static map<wstring, Texture*> textures;

	wstring path;
};
