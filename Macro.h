#pragma once

#include <Windows.h>
#include <iostream>
#include <vector>

class Macro
{
	std::vector<CHAR> keys;
	std::vector<DWORD> pause;
	bool loop = false;
	UINT startKey = VK_NUMPAD1;

public:
	Macro(std::vector<CHAR> keys, std::vector<DWORD> pause, bool loop = false, UINT startKey = VK_NUMPAD1);
	static void pressKey(CHAR keyParam);
	void run();
};