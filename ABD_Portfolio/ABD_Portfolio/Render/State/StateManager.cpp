#include "framework.h"
#include "StateManager.h"

StateManager::StateManager()
{
	CreateSamplerState();
	CreateRasterizerState();
}

StateManager::~StateManager()
{
	delete    samplerState;
	delete rasterizerState;
}

void StateManager::CreateSamplerState()
{
	samplerState = new SamplerState();
}

void StateManager::CreateRasterizerState()
{
	rasterizerState = new RasterizerState();
	rasterizerState->SetState();
}
