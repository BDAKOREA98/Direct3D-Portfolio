#pragma once

class BinaryReader
{
public:
	BinaryReader(wstring path);
	BinaryReader( string path);
	~BinaryReader();

	int        ReadInt();
	UINT       ReadUINT();
	float      ReadFloat();
	string     ReadString();
	wstring    ReadWString();
	Vector3    ReadVector3();
	Vector4    ReadVector4();
	XMFLOAT4X4 ReadFloat4X4();
	Matrix     ReadMatrix();

	void ReadData(OUT void** data, UINT dataSize);

	bool Succeeded();

private:
	HANDLE file = nullptr;
	DWORD  size = 0;
};
