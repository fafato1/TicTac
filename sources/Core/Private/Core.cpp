#include <Core/Public/Core.h>

#include "raylib.h"


Vector2 Core::GetScreenCenter()  {
    return { static_cast<float>(GetScreenWidth()) / 2.f, static_cast<float>(GetScreenHeight()) / 2.f };
}
