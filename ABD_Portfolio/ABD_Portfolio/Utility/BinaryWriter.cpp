#include "Framework.h"
#include "BinaryWriter.h"

BinaryWriter::BinaryWriter(wstring path)
{
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

void BinaryWriter::WriteData(void* data, UINT dataSize)
{
	WriteFile(file, data, dataSize, &size, nullptr);
}
