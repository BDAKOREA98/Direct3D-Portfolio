#pragma once

class GridScene : public Scene
{
public:
	GridScene();
	~GridScene();

	virtual void Update() override;

	virtual void PreRender() override;
	virtual void Render() override;
	virtual void PostRender() override;

	void CreateMesh();

private:
	int width = 100, height = 100;

	Material* material;

	VertexBuffer* vertexBuffer;

	vector<VertexColor> vertices;

	WorldBuffer* worldBuffer;
};
