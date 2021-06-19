#include "MultiMacro.h"

MultiMacro::MultiMacro(std::vector<Macro> macro, UINT stopKey)
{
    this->macro = macro;
    this->stopKey = stopKey;
}

void MultiMacro::startMacro(Macro macroParam)
{
    macroParam.run();
}

void MultiMacro::run()
{
    do {
        for (int i = 0; i < macro.size(); ++i) {
            startMacro(macro.at(i));
            Sleep(10 + 50);
        }
        if (GetAsyncKeyState(stopKey))
            return;
    } while (true);
}
