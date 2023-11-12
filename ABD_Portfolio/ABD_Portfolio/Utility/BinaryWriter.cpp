#include "framework.h"
#include "BinaryWriter.h"

BinaryWriter::BinaryWriter(string path)
{
	if (!StartsWith(path, "_"))
		path = "_TextData/" + path;

	file = CreateFileA
	(
		path.c_str(),
		GENERIC_WRITE,
		0, 0,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		nullptr
	);
}

BinaryWriter::BinaryWriter(wstring path)
{
	if (!StartsWith(path, L"_"))
		path = L"_TextData/" + path;

	file = CreateFile
	(
		path.c_str(),
		GENERIC_WRITE,
		0, 0,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		nullptr
	);
}

BinaryWriter::~BinaryWriter()
{
	CloseHandle(file);
}

void BinaryWriter::WriteData(int data)
{
	WriteFile(file, &data, sizeof(int), &size, nullptr);
}

void BinaryWriter::WriteData(UINT data)
{
	WriteFile(file, &data, sizeof(UINT), &size, nullptr);
}

void BinaryWriter::WriteData(float data)
{
	WriteFile(file, &data, sizeof(float), &size, nullptr);
}

void BinaryWriter::WriteData(string data)
{
	WriteData((UINT)data.size());

	const char* str = data.c_str();

	WriteFile(file, str, sizeof(char) * data.size(), &size, nullptr);
}

void BinaryWriter::WriteData(wstring data)
{
	WriteData((UINT)data.size());

	const wchar_t* str = data.c_str();

	WriteFile(file, str, sizeof(wchar_t) * data.size(), &size, nullptr);
}

void BinaryWriter::WriteData(Vector3 data)
{
	WriteData(data.x);
	WriteData(data.y);
	WriteData(data.z);
}

void BinaryWriter::WriteData(Vector4 data)
{
	WriteData(data.x);
	WriteData(data.y);
	WriteData(data.z);
	WriteData(data.w);
}

void BinaryWriter::WriteData(void* data, UINT dataSize)
{
	WriteFile(file, data, dataSize, &size, nullptr);
}

void BinaryWriter::WriteData(XMFLOAT4X4 data)
{
	WriteFile(file, &data, sizeof(XMFLOAT4X4), &size, nullptr);
}

void BinaryWriter::WriteData(Matrix data)
{
	WriteFile(file, &data, sizeof(Matrix), &size, nullptr);
}

void BinaryWriter::WriteData(size_t data)
{
	WriteData((UINT)data);
}
