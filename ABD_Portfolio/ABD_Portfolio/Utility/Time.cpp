#include "framework.h"
#include "Time.h"

float Time::timeElapsed = 0.0;

Time::Time()
	: curTick(0), frameCount(0), frameRate(0), oneSecCount(0), runningTime(0), scanningRate(0)
{
	QueryPerformanceFrequency((LARGE_INTEGER*)&ticksPerSecond);

	QueryPerformanceCounter((LARGE_INTEGER*)&lastTick);

	timeScale = 1.0 / ticksPerSecond;
}

Time::~Time()
{
}

void Time::Update()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&curTick);

	timeElapsed = (curTick - lastTick) * timeScale;

	if (scanningRate != 0)
	{
		while (timeElapsed < (1.0 / scanningRate))
		{
			QueryPerformanceCounter((LARGE_INTEGER*)&curTick);
			timeElapsed = (curTick - lastTick) * timeScale;
		}
	}

	lastTick = curTick;

	frameCount++;

	oneSecCount += timeElapsed;

	runningTime += timeElapsed;

	if (oneSecCount >= 1.0)
	{
		frameRate  = frameCount;
		frameCount = 0;

		oneSecCount = 0;
	}
}

void Time::Render()
{
	ImGui::Text("FPS : %d", frameRate);
}
