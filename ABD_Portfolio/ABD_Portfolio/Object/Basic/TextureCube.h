#pragma once

class TextureCube : public Transform
{
	enum Side
	{
		LEFT,
		RIGHT,
		BOTTOM,
		TOP,
		FRONT,
		BACK
	};

public:
	TextureCube();
	~TextureCube();

	void Update();
	void Render();

	void CreateQuads();

private:
	vector<Quad*> quads;
};
