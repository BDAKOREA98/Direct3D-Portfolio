#pragma once

#define MAX_KEY 256

typedef unsigned char byte;

enum KeyState
{
	NONE,
	DOWN,
	UP,
	PRESS
};

class Keyboard : public Singleton<Keyboard>
{
	friend class Singleton;
private:
	Keyboard();
	~Keyboard();

public:
	void Update();

	bool  Down(DWORD key) { return keyMap[key] == DOWN; }
	bool    Up(DWORD key) { return keyMap[key] == UP; }
	bool Press(DWORD key) { return keyMap[key] == PRESS; }

private:
	byte keyState[MAX_KEY];
	byte keyOldState[MAX_KEY];
	byte keyMap[MAX_KEY];
};
