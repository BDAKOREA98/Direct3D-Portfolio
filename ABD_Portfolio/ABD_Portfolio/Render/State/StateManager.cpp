#include "framework.h"
#include "StateManager.h"

StateManager::StateManager()
{
	CreateSamplerState();
	CreateRasterizerState();
	CreateBlendState();
	CreateDepthStencilState();
}

StateManager::~StateManager()
{
	delete    samplerState;
	delete rasterizerState;

	for (BlendState* blendState : blendStates)
		delete blendState;

	blendStates.clear();

	for (DepthStencilState* depthStencilState : depthStencilStates)
		delete depthStencilState;

	depthStencilStates.clear();
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

void StateManager::CreateBlendState()
{
	blendStates.push_back(new BlendState());
	blendStates.push_back(new BlendState());
	blendStates.push_back(new BlendState());

	blendStates[1]->Alpha(true);
	blendStates[2]->Additive();
}

void StateManager::CreateDepthStencilState()
{
	depthStencilStates.push_back(new DepthStencilState());
	depthStencilStates.push_back(new DepthStencilState());

	depthStencilStates[1]->DepthEnable(false);
}

void StateManager::AlphaBegin()
{
	blendStates[1]->SetState();
}

void StateManager::AlphaEnd()
{
	blendStates[0]->SetState();
}

void StateManager::DepthEnable()
{
	depthStencilStates[0]->SetState();
}

void StateManager::DepthDisable()
{
	depthStencilStates[1]->SetState();
}

void StateManager::Set()
{
	AlphaEnd();
	DepthEnable();
}

void StateManager::PostSet()
{
	AlphaBegin();
	DepthDisable();
}
