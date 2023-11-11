#pragma once

class BinaryWriter
{
public:
	BinaryWriter(wstring path);
	~BinaryWriter();

	void WriteData(    int data);
	void WriteData(   UINT data);
	void WriteData(  float data);
	void WriteData( string data);
	void WriteData(wstring data);
	void WriteData(Vector3 data);
	void WriteData(  void* data, UINT dataSize);

private:
	HANDLE file = nullptr;
	DWORD  size = 0;
};
