#pragma once

class StateManager : public Singleton<StateManager>
{
	friend class Singleton;
private:
	StateManager();
	~StateManager();

	void CreateSamplerState();
	void CreateRasterizerState();

public:
	RasterizerState* GetRS() { return rasterizerState; }

private:
	   SamplerState*    samplerState = nullptr;
	RasterizerState* rasterizerState = nullptr;
};
