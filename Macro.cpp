#include "Macro.h"

Macro::Macro(std::vector<CHAR> keys, std::vector<DWORD> pause, bool loop, UINT startKey) {
    this->keys = keys;
    this->pause = pause;
    this->loop = loop;
    this->startKey = startKey;
}

void Macro::pressKey(CHAR keyParam) {
    if (keyParam == '/') {
        INPUT input = { 0 };

        input.type = INPUT_KEYBOARD;
        input.ki.wScan = 0;
        input.ki.time = 0;
        input.ki.dwExtraInfo = 0;

        input.ki.wScan = ::MapVirtualKey(VK_LSHIFT, 0);
        input.ki.dwFlags = KEYEVENTF_SCANCODE;
        SendInput(1, &input, sizeof(INPUT));
        input.ki.wScan = ::MapVirtualKey('7', 0);
        input.ki.dwFlags = KEYEVENTF_SCANCODE;
        SendInput(1, &input, sizeof(INPUT));

        input.type = INPUT_KEYBOARD;
        input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
        input.ki.wScan = ::MapVirtualKey(VK_LSHIFT, 0);
        SendInput(1, &input, sizeof(INPUT));
    }
    else {
        SHORT key;
        UINT mappedkey;
        INPUT input = { 0 };
        key = VkKeyScan(keyParam);
        mappedkey = MapVirtualKey(LOBYTE(key), 0);
        input.type = INPUT_KEYBOARD;
        input.ki.dwFlags = KEYEVENTF_SCANCODE;
        input.ki.wScan = mappedkey;
        SendInput(1, &input, sizeof(input));
        Sleep(1);
        input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
        SendInput(1, &input, sizeof(input));
    }
}

void Macro::run() {
    if (keys.size() != pause.size()) {
        std::cout << "Aumento de teclas y frenos iguales!" << std::endl;
        return;
    }
    if (GetAsyncKeyState(startKey)) {
        for (int i = 0; i < keys.size(); ++i) {
            pressKey(keys.at(i));
            Sleep(1);
        }
    }
}
