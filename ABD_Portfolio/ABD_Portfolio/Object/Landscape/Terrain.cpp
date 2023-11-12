#include "framework.h"
#include "Terrain.h"

Terrain::Terrain(wstring diffuseFile, wstring heightFile)
{
	material = new Material();
	material->SetShader(L"Diffuse");
	material->SetDiffuseMap(diffuseFile);

	worldBuffer = new MatrixBuffer();

	heightMap = Texture::Get(heightFile);

	CreateMesh();
	
	CreateNormal();

	mesh = new Mesh(vertices, indices);
}

Terrain::~Terrain()
{
	delete mesh;
	delete worldBuffer;
	delete material;
}

void Terrain::Render()
{
	worldBuffer->SetData(world);
	worldBuffer->SetVSBuffer(0);

	    mesh->SetMesh();
	material->SetMaterial();

	DC->DrawIndexed(indices.size(), 0, 0);
}

void Terrain::CreateMesh()
{
     width = heightMap->GetSize().x;
	height = heightMap->GetSize().y;

	vector<Vector4> colors = heightMap->ReadPixels();

	//Vertices
	for (float z = 0; z < height; z++)
	{
		for (float x = 0; x < width; x++)
		{
			VertexTextureNormal vertex;
			vertex.pos = Vector3(x, 0, z);

			vertex.uv.x =     x / (width  - 1);
			vertex.uv.y = 1 - z / (height - 1);

			//HeightMap
			UINT index = x + z * width;
			vertex.pos.y = colors[index].x * MAP_HEIGHT;


			vertices.push_back(vertex);
		}
	}

	//Indices
	for (float z = 0; z < height - 1; z++)
	{
		for (float x = 0; x < width - 1; x++)
		{
			indices.push_back(x + 0 + width * (z + 1)); //7
			indices.push_back(x + 1 + width * (z + 1)); //8
			indices.push_back(x + 0 + width * (z + 0)); //0

			indices.push_back(x + 0 + width * (z + 0)); //0
			indices.push_back(x + 1 + width * (z + 1)); //8
			indices.push_back(x + 1 + width * (z + 0)); //1
		}
	}

}

void Terrain::CreateNormal()
{
	for (UINT i = 0; i < indices.size() / 3; i++)
	{
		UINT index0 = indices[i * 3 + 0];
		UINT index1 = indices[i * 3 + 1];
		UINT index2 = indices[i * 3 + 2];
		
		Vector3 p0 = vertices[index0].pos;
		Vector3 p1 = vertices[index1].pos;
		Vector3 p2 = vertices[index2].pos;

		Vector3 v01 = p1 - p0;
		Vector3 v02 = p2 - p0;

		Vector3 normal = Vector3::Cross(v01, v02).GetNormalized();

		vertices[index0].normal += normal;
		vertices[index1].normal += normal;
		vertices[index2].normal += normal;
	}
}
