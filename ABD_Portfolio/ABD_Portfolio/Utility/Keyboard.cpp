#include "Framework.h"
#include "Keyboard.h"

Keyboard::Keyboard()
{
	ZeroMemory(keyState,    sizeof(keyState));
	ZeroMemory(keyOldState, sizeof(keyOldState));
	ZeroMemory(keyMap,      sizeof(keyMap));
}

Keyboard::~Keyboard()
{
}

void Keyboard::Update()
{
	memcpy(keyOldState, keyState, sizeof(keyState));

	ZeroMemory(keyState, sizeof(keyState));
	ZeroMemory(keyMap,   sizeof(keyMap));

	if (!GetKeyboardState(keyState))
		return;

	for (int i = 0; i < MAX_KEY; i++)
	{
		byte key = keyState[i] & 0x80;
		keyState[i] = key ? 1 : 0;

		byte old = keyOldState[i];
		byte cur = keyState[i];

		if (old == 0 && cur == 1)      
			keyMap[i] = DOWN;
		else if (old == 1 && cur == 0) 
			keyMap[i] = UP;
		else if (old == 1 && cur == 1) 
			keyMap[i] = PRESS;
		else
			keyMap[i] = NONE;
	}
}
