#pragma once

struct Vertex
{
    Vertex(float x, float y, float z)
    {
        pos = XMFLOAT3(x, y, z);
    }

    XMFLOAT3 pos;
};

struct VertexColor
{
    VertexColor(XMFLOAT3 pos, XMFLOAT4 color)
        :pos(pos), color(color)
    {
    }

    XMFLOAT3 pos;
    XMFLOAT4 color;
};

class TutorialScene : public Scene
{
public:
	TutorialScene();
	~TutorialScene();

	virtual void Update() override;

	virtual void PreRender() override;
	virtual void Render() override;
	virtual void PostRender() override;

private: 
    VertexShader* vertexShader;
     PixelShader*  pixelShader;
    
    VertexBuffer* vertexBuffer;
     IndexBuffer*  indexBuffer;

     MatrixBuffer* worldBuffer;
     MatrixBuffer*  viewBuffer;
     MatrixBuffer*  projBuffer;
    
    //////////////////////////////
    
    vector<VertexColor> vertices;
    vector<UINT>         indices;


};
