// Created by {BK}Charly

#include <iostream>
#include <Windows.h>
#include <vector>


#include "Macro.h"
#include "MultiMacro.h"

int main()
{
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 270, 150, TRUE);

    SetConsoleTitle(TEXT("BK Admin v0.1"));

    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    FlushConsoleInputBuffer(hConsole);

    std::cout << "NUMPAD1 = /k\nNUMPAD2 = /kill\nNUMPAD3 = /timemute\nNUMPAD4 = /timeban" << std::endl;

    SetConsoleTextAttribute(hConsole, 12);
    std::cout << "By {BK}Charly" << std::endl;

    std::vector<CHAR> keys = { 't','/','k', ' ' };
    std::vector<DWORD> pause{ 0,0,0,0 };
    Macro macro = Macro(keys, pause, true, VK_NUMPAD1);

    std::vector<CHAR> keys1 = { 't','/','k','i','l','l', ' ' };
    std::vector<DWORD> pause1{ 0,0,0,0,0,0,0 };
    Macro macro1 = Macro(keys1, pause1, true, VK_NUMPAD2);

    std::vector<CHAR> keys2 = { 't','/','t','i','m','e','m','u','t','e', ' ' };
    std::vector<DWORD> pause2{ 0,0,0,0,0,0,0,0,0,0,0 };
    Macro macro2 = Macro(keys2, pause2, true, VK_NUMPAD3);

    std::vector<CHAR> keys3 = { 't','/','t','i','m','e','b','a','n', ' ' };
    std::vector<DWORD> pause3{ 0,0,0,0,0,0,0,0,0,0 };
    Macro macro3 = Macro(keys3, pause3, true, VK_NUMPAD4);

    std::vector<Macro> macroK = { macro, macro1, macro2, macro3 };

    MultiMacro multiMacro = MultiMacro(macroK);
    multiMacro.run();

    return 0;
}