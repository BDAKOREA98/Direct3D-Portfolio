#pragma once

class BinaryReader
{
public:
	BinaryReader(wstring path);
	~BinaryReader();

	int     ReadInt();
	UINT    ReadUINT();
	float   ReadFloat();
	string  ReadString();
	wstring ReadWString();
	Vector3 ReadVector3();

	void ReadData(OUT void** data, UINT dataSize);

	bool Succeeded();

private:
	HANDLE file = nullptr;
	DWORD  size = 0;
};
