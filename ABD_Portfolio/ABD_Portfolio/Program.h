#pragma once
class Program
{
public:

	Program();
	~Program();

	void Update();
	void Render();

private:

	void Initialize();
	void Release();

private:
	
	bool isWireFrame = false;

};

