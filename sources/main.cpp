#include "raylib.h"


#include "lib/resource_dir.h"	// utility header for SearchAndSetResourceDir

typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING } GameScreen;

// Config - Default values
const Color LineColor = WHITE;
const int LineTickness = 10;
const float BorderOffset = 300.f;
const float LineOffset = 100.f;

int main()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI | FLAG_BORDERLESS_WINDOWED_MODE);

	// Create the window and OpenGL context
	InitWindow(GetScreenWidth(), GetScreenHeight(), "TicTac Game");

	const Vector2 ScreenCenter = { GetScreenWidth() / 2.f, GetScreenHeight() / 2.f };

	const Vector2 ButtonsPosition[9] = {
		Vector2(ScreenCenter.x - 150.f, ScreenCenter.y - 150.f), Vector2(ScreenCenter.x + 50.f, ScreenCenter.y - 150.f), Vector2(ScreenCenter.x + 250.f, ScreenCenter.y - 150.f),
		Vector2(ScreenCenter.x - 150.f, ScreenCenter.y + 50.f), Vector2(ScreenCenter.x + 50.f, ScreenCenter.y + 50.f), Vector2(ScreenCenter.x + 250.f, ScreenCenter.y + 50.f) ,
		Vector2(ScreenCenter.x - 150.f, ScreenCenter.y + 250.f), Vector2(ScreenCenter.x + 50.f, ScreenCenter.y + 250.f), Vector2(ScreenCenter.x + 250.f, ScreenCenter.y + 250.f)
	};




	enum Players
	{
		Player1,
		Player2
	};

	struct gameData
	{
		bool IsMarked[9] = { false };
		Players CurrentPlayer = Player1;
		Players WhoMarked[9] = { };
	};

	gameData GameData;

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	GameScreen currentScreen = LOGO;

	Vector2 MousePosition = Vector2(0, 0);

	// Load a texture from the resources directory
	//Texture wabbit = LoadTexture("wabbit_alpha.png");
	Texture textureX = LoadTexture("TextureX.png");
	Texture textureO = LoadTexture("TextureO.png");

	int framesCounter = 0;
	// game loop
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		// drawing
		BeginDrawing();

		switch (currentScreen)
		{
		case LOGO:
		{
			// TODO: Update LOGO screen variables here!

			framesCounter++;    // Count frames

			// Wait for 2 seconds (120 frames) before jumping to TITLE screen
			if (framesCounter > (GetMonitorRefreshRate(0) * 2))
			{
				currentScreen = GAMEPLAY;
			}
		} break;
		case TITLE:
		{
			// TODO: Update TITLE screen variables here!
			// Press enter to change to GAMEPLAY screen
			if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
			{
				currentScreen = GAMEPLAY;
			}
		} break;
		case GAMEPLAY:
		{
			// TODO: Update GAMEPLAY screen variables here!

			// Press enter to change to ENDING screen
			/*if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
			{
				currentScreen = ENDING;
			}*/
		} break;
		case ENDING:
		{
			// TODO: Update ENDING screen variables here!

			// Press enter to return to TITLE screen
			if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
			{
				currentScreen = TITLE;
			}
		} break;
		default: break;
		}




		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		switch (currentScreen)
		{
		case LOGO:
		{
			// TODO: Draw LOGO screen here!
			DrawText("TicTac In Raylib", 40, 40, 40, GREEN);
			DrawText("WAIT for 2 SECONDS...", GetScreenWidth() / 3, GetScreenHeight() / 3, 20, GRAY);

		} break;
		case TITLE:
		{
			// TODO: Draw TITLE screen here!
			DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), GREEN);
			//DrawText("TITLE SCREEN", 20, 20, 40, DARKGREEN);
			DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKGREEN);

		} break;
		case GAMEPLAY:
		{
			// TODO: Draw GAMEPLAY screen here!


			DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);
			DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);


			// Borders
			// New Border Implementation
			DrawRectangleLinesEx(Rectangle(ScreenCenter.x - BorderOffset, ScreenCenter.y - BorderOffset, 600, 600), 10, WHITE);


			for (int i = 0; i < 9; i++)
			{
				if (GameData.IsMarked[i] == true) {

					if (GameData.WhoMarked[i] == Player2) DrawTexture(textureX, static_cast<int>(ButtonsPosition[i].x - 100), static_cast<int>(ButtonsPosition[i].y - 100), WHITE);
					else if (GameData.WhoMarked[i] == Player1) DrawTexture(textureO, static_cast<int>(ButtonsPosition[i].x - 100), static_cast<int>(ButtonsPosition[i].y - 100), WHITE);
				}
			}

			//DrawTexture(TextureX, )
			if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) MousePosition = GetMousePosition();
			DrawText(TextFormat("%2f X | %2f Y", MousePosition.x, MousePosition.y), 20, 80, 40, LineColor);



			DrawLineEx(Vector2(ScreenCenter.x - LineOffset, ScreenCenter.y - BorderOffset), Vector2(ScreenCenter.x - LineOffset, ScreenCenter.y + BorderOffset), LineTickness, LineColor); // First Vertical Line
			DrawLineEx(Vector2(ScreenCenter.x + LineOffset, ScreenCenter.y - BorderOffset), Vector2(ScreenCenter.x + LineOffset, ScreenCenter.y + BorderOffset), LineTickness, LineColor); // Second Vertical Line
			DrawLineEx(Vector2(ScreenCenter.x - BorderOffset, ScreenCenter.y - LineOffset), Vector2(ScreenCenter.x + BorderOffset, ScreenCenter.y - LineOffset), LineTickness, LineColor); // First Horizontal Line
			DrawLineEx(Vector2(ScreenCenter.x - BorderOffset, ScreenCenter.y + LineOffset), Vector2(ScreenCenter.x + BorderOffset, ScreenCenter.y + LineOffset), LineTickness, LineColor); // Second Horizontal Line

		} break;
		case ENDING:
		{
			// TODO: Draw ENDING screen here!
			DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLUE);
			DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
			DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);

		} break;
		default: break;
		}

		//EndDrawing();

		DrawFPS(0, 0);
		// draw our texture to the screen

		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// cleanup
	// unload our texture so it can be cleaned up

	UnloadTexture(textureX);
	UnloadTexture(textureO);

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
