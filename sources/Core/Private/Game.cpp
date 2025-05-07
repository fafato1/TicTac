#include <Core/Public/Game.h>
#include <raylib.h>

bool Game::InvisibleButton(const uint8_t Index)
{
  if (Index < 1 || Index > 9)
  {
    Log(0, "Index is out of range");
    exit(1);
  }
  int row = (Index - 1) / 3 + 1;
  int col = (Index - 1) % 3 + 1;

  const Rectangle LocationToCheck
  (
    Core::GetScreenCenter().x - Core::GetBorderOffset() + ((Core::GetCellSize() * static_cast<float>(col) - Core::GetCellSize())),
    Core::GetScreenCenter().y - Core::GetBorderOffset() + ((Core::GetCellSize() * static_cast<float>(row)- Core::GetCellSize())),
    Core::GetCellSize(),
    Core::GetCellSize()
  );
  Vector2 mousePos = GetMousePosition();
  bool bIsHovered = CheckCollisionPointRec(mousePos, LocationToCheck);
  bool bIsClicked = bIsHovered && IsMouseButtonReleased(MOUSE_LEFT_BUTTON);

  // Opcionalmente, você pode descomentá-lo para visualizar a área durante o desenvolvimento
  if (bIsHovered) DrawRectangleLines(LocationToCheck.x, LocationToCheck.y, LocationToCheck.width, LocationToCheck.height, GREEN);

  return bIsClicked;
}



void Game::SetupGame()
{

}

