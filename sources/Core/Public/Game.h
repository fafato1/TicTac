#pragma once

#include <Core/Public/Core.h>
#include <array>


class Game
{

public:
    Game() {Buttons.fill(Unchecked);}
    static bool InvisibleButton(uint8_t Index);

void SetupGame();

    enum ECheckStatus
    {
        Unchecked = 0,
        Player1 = 1,
        Player2 = 2
    };

    std::array<ECheckStatus, 9> Buttons = {};
};
