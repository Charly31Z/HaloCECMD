#pragma once

#include <Windows.h>
#include <iostream>
#include <vector>
#include "Macro.h"

class MultiMacro
{
	std::vector<Macro> macro;
	UINT stopKey = VK_NUMPAD5;

public:
	MultiMacro(std::vector<Macro> macro, UINT stopKey = VK_NUMPAD5);
	static void startMacro(Macro macroParam);
	void run();
};
