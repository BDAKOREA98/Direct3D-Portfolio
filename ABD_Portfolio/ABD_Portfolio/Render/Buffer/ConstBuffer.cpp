#include "Framework.h"
#include "ConstBuffer.h"


ConstBuffer::ConstBuffer(void* data, UINT dataSize)
	:data(data), dataSize(dataSize)
{
	D3D11_BUFFER_DESC bufferDesc = {};
	
	bufferDesc.ByteWidth           = dataSize;
	bufferDesc.Usage               = D3D11_USAGE_DEFAULT;
	bufferDesc.BindFlags           = D3D11_BIND_CONSTANT_BUFFER;
	bufferDesc.CPUAccessFlags      = 0;
	bufferDesc.MiscFlags           = 0;
	bufferDesc.StructureByteStride = 0;
	
	DEVICE->CreateBuffer(&bufferDesc, nullptr, &constBuffer);
}

ConstBuffer::~ConstBuffer()
{
	constBuffer->Release();
}

void ConstBuffer::SetVSBuffer(UINT slot)
{
	UpdateSubResource();

	DC->VSSetConstantBuffers(slot, 1, &constBuffer);
}

void ConstBuffer::SetPSBuffer(UINT slot)
{
	UpdateSubResource();

	DC->PSSetConstantBuffers(slot, 1, &constBuffer);
}

void ConstBuffer::UpdateSubResource()
{
	DC->UpdateSubresource(constBuffer, 0, nullptr, data, 0, 0);
}
