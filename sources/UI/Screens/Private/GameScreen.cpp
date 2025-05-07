#include <UI/Screens/Public/GameScreen.h>
#include <raylib.h>
#include <Core/Public/Core.h>
#include <Core/Public/Game.h>

void GameScreen::OnUpdate(float DeltaTime)
{
}

void GameScreen::OnCreate()
{
}

GameScreen::~GameScreen()
{
}

void GameScreen::OnDestroy()
{
	__super::OnDestroy();
}

void GameScreen::SetupScreen() {

	//DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLANK);
	DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);

	// Borders
	// New Border Implementation
	DrawRectangleLinesEx(Rectangle(GetScreenCenter().x - GetBorderOffset(), GetScreenCenter().y - GetBorderOffset(), GetBorderOffset()*2, GetBorderOffset()*2), 10, WHITE);

	DrawLineEx(Vector2(GetScreenCenter().x - GetLineOffset(), GetScreenCenter().y - GetBorderOffset()), Vector2(GetScreenCenter().x - GetLineOffset(), GetScreenCenter().y + GetBorderOffset()), LineThickness, LineColor); // First Vertical Line
	DrawLineEx(Vector2(GetScreenCenter().x + GetLineOffset(), GetScreenCenter().y - GetBorderOffset()), Vector2(GetScreenCenter().x + GetLineOffset(), GetScreenCenter().y + GetBorderOffset()), LineThickness, LineColor); // Second Vertical Line
	DrawLineEx(Vector2(GetScreenCenter().x - GetBorderOffset(), GetScreenCenter().y - GetLineOffset()), Vector2(GetScreenCenter().x + GetBorderOffset(), GetScreenCenter().y - GetLineOffset()), LineThickness, LineColor); // First Horizontal Line
	DrawLineEx(Vector2(GetScreenCenter().x - GetBorderOffset(), GetScreenCenter().y + GetLineOffset()), Vector2(GetScreenCenter().x + GetBorderOffset(), GetScreenCenter().y + GetLineOffset()), LineThickness, LineColor); // Second Horizontal Line

	Game jogo;



}
