#include <UI/Screens/Public/GameScreen.h>
#include <raylib.h>

void GameScreen::OnUpdate(float DeltaTime) {
}

void GameScreen::OnCreate() {
}

GameScreen::~GameScreen() {
}

void GameScreen::OnDestroy() {
	BaseUI::OnDestroy();
}

void GameScreen::SetupScreen() {

	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);
	DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);

	// Borders
	// New Border Implementation
	DrawRectangleLinesEx(Rectangle(GetScreenCenter().x - BorderOffset, GetScreenCenter().y - BorderOffset, 600, 600), 10, WHITE);

	DrawLineEx(Vector2(GetScreenCenter().x - LineOffset, GetScreenCenter().y - BorderOffset), Vector2(GetScreenCenter().x - LineOffset, GetScreenCenter().y + BorderOffset), LineTickness, LineColor); // First Vertical Line
	DrawLineEx(Vector2(GetScreenCenter().x + LineOffset, GetScreenCenter().y - BorderOffset), Vector2(GetScreenCenter().x + LineOffset, GetScreenCenter().y + BorderOffset), LineTickness, LineColor); // Second Vertical Line
	DrawLineEx(Vector2(GetScreenCenter().x - BorderOffset, GetScreenCenter().y - LineOffset), Vector2(GetScreenCenter().x + BorderOffset, GetScreenCenter().y - LineOffset), LineTickness, LineColor); // First Horizontal Line
	DrawLineEx(Vector2(GetScreenCenter().x - BorderOffset, GetScreenCenter().y + LineOffset), Vector2(GetScreenCenter().x + BorderOffset, GetScreenCenter().y + LineOffset), LineTickness, LineColor); // Second Horizontal Line

}
