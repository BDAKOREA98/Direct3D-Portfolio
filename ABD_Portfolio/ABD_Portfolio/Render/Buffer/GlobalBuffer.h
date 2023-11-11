#pragma once

class MatrixBuffer : public ConstBuffer
{
public:
	MatrixBuffer()
		: ConstBuffer(&data, sizeof(Data))
	{
		data.matrix = XMMatrixIdentity();
	}

	void SetData(XMMATRIX value)
	{
		data.matrix = XMMatrixTranspose(value);
	}

private:
	struct Data
	{
		XMMATRIX matrix;
	} data;
};

class LightBuffer : public ConstBuffer
{
public:
	LightBuffer()
		: ConstBuffer(&data, sizeof(Data))
	{
		data.direction    = V_DOWN;
		data.padding      = 0.0f;
		data.ambientLight = Vector4(0.1f, 0.1f, 0.1f, 1.0f);
	}

	struct Data
	{
		Vector3 direction;

		float   padding;

		Vector4 ambientLight;
	} data;
};



class ViewBuffer : public ConstBuffer
{
public:
	ViewBuffer()
		: ConstBuffer(&data, sizeof(Data))
	{
		data.view    = XMMatrixIdentity();
		data.invView = XMMatrixIdentity();
	}

	void SetData(Matrix view, Matrix invView)
	{
		data.view    = XMMatrixTranspose(view);
		data.invView = XMMatrixTranspose(invView);
	}

private:
	struct Data
	{
		Matrix view;
		Matrix invView;
	} data;
};


class MaterialBuffer : public ConstBuffer
{
public:
	MaterialBuffer()
		: ConstBuffer(&data, sizeof(Data))
	{
	}

	struct Data
	{
		Vector4 diffuse  = Vector4(1, 1, 1, 1);
		Vector4 specular = Vector4(1, 1, 1, 1);
		Vector4 ambient  = Vector4(1, 1, 1, 1);

		int hasDiffuseMap  = 0;
		int hasSpecularMap = 0;
		int hasNormalMap   = 0;

		float shininess = 24.0f;
	} data;
};


class RayBuffer : public ConstBuffer
{
public:
	RayBuffer()
		: ConstBuffer(&data, sizeof(Data))
	{
	}

	struct Data
	{
		Vector3 origin     = {};
		float   outputSize = 0;
		
		Vector3 direction  = {};
		float   padding    = 0;
	} data;
};

class BrushBuffer : public ConstBuffer
{
public:
	BrushBuffer()
		: ConstBuffer(&data, sizeof(Data))
	{
	}

	struct Data
	{
		int     type     = 0;
		Vector3 location = {};
		
		float   range = 10.0f;
		Vector3 color = { 0.0f, 0.5f, 0.0f };
	} data;
};