#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir

typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING } GameScreen;

// Config - Default values
const Color LineColor = WHITE;
const int LineTickness = 10;
float VerticalLineX = 100;
float HorizontalLineY = 100;

int main()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI | FLAG_BORDERLESS_WINDOWED_MODE);

	// Create the window and OpenGL context
	InitWindow(GetScreenWidth(), GetScreenHeight(), "TicTac Game");

	const Vector2 ScreenCenter = { GetScreenWidth() / 2, GetScreenHeight() / 2 };
	const float BorderOffset = 300.f;
	const float LineOffset = 100.f;

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	GameScreen currentScreen = LOGO;

	Vector2 MousePosition = Vector2(0, 0);

	// Load a texture from the resources directory
	//Texture wabbit = LoadTexture("wabbit_alpha.png");
	Texture TextureX = LoadTexture("TextureX.png");
	Texture TextureO = LoadTexture("TextureO.png");

	bool showMessageBox = false;
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

			/*
			// raygui: controls drawing
			//----------------------------------------------------------------------------------
			GuiGroupBox(Rectangle{ 66, 200, 276, 312 }, "Vertical Line X");
			GuiSlider(Rectangle{ 110, 224, 216, 16 }, TextFormat("%0.2f", VerticalLineX), NULL, &VerticalLineX, 50.0f, 400.0f);
			GuiSlider(Rectangle{ 110, 248, 216, 16 }, TextFormat("%0.2f", HorizontalLineY), NULL, &HorizontalLineY, 50.0f, 400.0f);
			*/

			//Borders
			DrawLineEx(Vector2(ScreenCenter.x - BorderOffset, ScreenCenter.y - BorderOffset), Vector2(ScreenCenter.x + BorderOffset, ScreenCenter.y - BorderOffset), LineTickness, LineColor); // Border Up
			DrawLineEx(Vector2(ScreenCenter.x - BorderOffset, ScreenCenter.y + BorderOffset), Vector2(ScreenCenter.x + BorderOffset, ScreenCenter.y + BorderOffset), LineTickness, LineColor); // Border Down
			DrawLineEx(Vector2(ScreenCenter.x - BorderOffset, ScreenCenter.y - BorderOffset), Vector2(ScreenCenter.x - BorderOffset, ScreenCenter.y + BorderOffset), LineTickness, LineColor); // Border Left
			DrawLineEx(Vector2(ScreenCenter.x + BorderOffset, ScreenCenter.y - BorderOffset), Vector2(ScreenCenter.x + BorderOffset, ScreenCenter.y + BorderOffset), LineTickness, LineColor); // Border Right

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
		//DrawTexture(wabbit, 400, 200, WHITE);

		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// cleanup
	// unload our texture so it can be cleaned up
	//UnloadTexture(wabbit);

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}





/////////////////////////////////
//
///*******************************************************************************************
//*
//*   raygui - custom sliders
//*
//*   DEPENDENCIES:
//*       raylib 4.0  - Windowing/input management and drawing.
//*       raygui 3.0  - Immediate-mode GUI controls.
//*
//*   COMPILATION (Windows - MinGW):
//*       gcc -o $(NAME_PART).exe $(FILE_NAME) -I../../src -lraylib -lopengl32 -lgdi32 -std=c99
//*
//*   LICENSE: zlib/libpng
//*
//*   Copyright (c) 2016-2024 Ramon Santamaria (@raysan5)
//*
//**********************************************************************************************/
//
//#include "raylib.h"
//
//#define RAYGUI_IMPLEMENTATION
//#include "raygui.h"
//
////----------------------------------------------------------------------------------
//// Controls Functions Declaration
////----------------------------------------------------------------------------------
//float GuiVerticalSlider(Rectangle bounds, const char* textTop, const char* textBottom, float value, float minValue, float maxValue);
//float GuiVerticalSliderBar(Rectangle bounds, const char* textTop, const char* textBottom, float value, float minValue, float maxValue);
//float GuiVerticalSliderPro(Rectangle bounds, const char* textTop, const char* textBottom, float value, float minValue, float maxValue, int sliderHeight);
//
//bool GuiSliderOwning(Rectangle bounds, const char* textLeft, const char* textRight, float* value, float minValue, float maxValue, bool editMode);
//bool GuiSliderBarOwning(Rectangle bounds, const char* textLeft, const char* textRight, float* value, float minValue, float maxValue, bool editMode);
//bool GuiSliderProOwning(Rectangle bounds, const char* textLeft, const char* textRight, float* value, float minValue, float maxValue, int sliderWidth, bool editMode);
//
//bool GuiVerticalSliderOwning(Rectangle bounds, const char* textTop, const char* textBottom, float* value, float minValue, float maxValue, bool editMode);
//bool GuiVerticalSliderBarOwning(Rectangle bounds, const char* textTop, const char* textBottom, float* value, float minValue, float maxValue, bool editMode);
//bool GuiVerticalSliderProOwning(Rectangle bounds, const char* textTop, const char* textBottom, float* value, float minValue, float maxValue, int sliderHeight, bool editMode);
//
////------------------------------------------------------------------------------------
//// Program main entry point
////------------------------------------------------------------------------------------
//int main()
//{
//  // Initialization
//  //---------------------------------------------------------------------------------------
//  int screenWidth = 800;
//  int screenHeight = 450;
//
//  InitWindow(screenWidth, screenHeight, "raygui - custom sliders");
//
//  float value = 0.5f;
//  bool sliderEditMode = false;
//  bool vSliderEditMode = false;
//  bool vSliderBarEditMode = false;
//
//  SetTargetFPS(60);
//  //--------------------------------------------------------------------------------------
//
//  // Main game loop
//  while (!WindowShouldClose())    // Detect window close button or ESC key
//  {
//    // Update
//    //----------------------------------------------------------------------------------
//    // TODO: Implement required update logic
//    //----------------------------------------------------------------------------------
//
//    // Draw
//    //----------------------------------------------------------------------------------
//    BeginDrawing();
//
//    ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));
//
//    if (vSliderEditMode || vSliderBarEditMode) GuiLock();
//    else GuiUnlock();
//
//
//
//    GuiGroupBox(Rectangle { 378, 24, 276, 312 }, "OWNING");
//    if (GuiSliderOwning(Rectangle { 408, 48, 216, 16 }, NULL, TextFormat("%0.2f", value), & value, 0.0f, 1.0f, sliderEditMode)) sliderEditMode = !sliderEditMode;
//    if (GuiVerticalSliderOwning(Rectangle { 432, 120, 24, 192 }, NULL, TextFormat("%0.2f", value), & value, 0.0f, 1.0f, vSliderEditMode)) vSliderEditMode = !vSliderEditMode;
//    if (GuiVerticalSliderBarOwning(Rectangle { 576, 120, 24, 192 }, NULL, TextFormat("%0.2f", value), & value, 0.0f, 1.0f, vSliderBarEditMode)) vSliderBarEditMode = !vSliderBarEditMode;
//    //----------------------------------------------------------------------------------
//
//    EndDrawing();
//    //----------------------------------------------------------------------------------
//  }
//
//  // De-Initialization
//  //--------------------------------------------------------------------------------------
//  CloseWindow();        // Close window and OpenGL context
//  //--------------------------------------------------------------------------------------
//
//  return 0;
//}
//
////------------------------------------------------------------------------------------
//// Controls Functions Definitions (local)
////------------------------------------------------------------------------------------
//float GuiVerticalSliderPro(Rectangle bounds, const char* textTop, const char* textBottom, float value, float minValue, float maxValue, int sliderHeight)
//{
//  GuiState state = (GuiState)GuiGetState();
//
//  int sliderValue = (int)(((value - minValue) / (maxValue - minValue)) * (bounds.height - 2 * GuiGetStyle(SLIDER, BORDER_WIDTH)));
//
//  Rectangle slider = {
//      bounds.x + GuiGetStyle(SLIDER, BORDER_WIDTH) + GuiGetStyle(SLIDER, SLIDER_PADDING),
//      bounds.y + bounds.height - sliderValue,
//      bounds.width - 2 * GuiGetStyle(SLIDER, BORDER_WIDTH) - 2 * GuiGetStyle(SLIDER, SLIDER_PADDING),
//      0.0f,
//  };
//
//  if (sliderHeight > 0)        // Slider
//  {
//    slider.y -= sliderHeight / 2;
//    slider.height = (float)sliderHeight;
//  }
//  else if (sliderHeight == 0)  // SliderBar
//  {
//    slider.y -= GuiGetStyle(SLIDER, BORDER_WIDTH);
//    slider.height = (float)sliderValue;
//  }
//  // Update control
//  //--------------------------------------------------------------------
//  if ((state != STATE_DISABLED) && !guiLocked)
//  {
//    Vector2 mousePoint = GetMousePosition();
//
//    if (CheckCollisionPointRec(mousePoint, bounds))
//    {
//      if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
//      {
//        state = STATE_PRESSED;
//
//        // Get equivalent value and slider position from mousePoint.x
//        float normalizedValue = (bounds.y + bounds.height - mousePoint.y - (float)(sliderHeight / 2)) / (bounds.height - (float)sliderHeight);
//        value = (maxValue - minValue) * normalizedValue + minValue;
//
//        if (sliderHeight > 0) slider.y = mousePoint.y - slider.height / 2;  // Slider
//        else if (sliderHeight == 0)                                          // SliderBar
//        {
//          slider.y = mousePoint.y;
//          slider.height = bounds.y + bounds.height - slider.y - GuiGetStyle(SLIDER, BORDER_WIDTH);
//        }
//      }
//      else state = STATE_FOCUSED;
//    }
//
//    if (value > maxValue) value = maxValue;
//    else if (value < minValue) value = minValue;
//  }
//
//
//  // Bar limits check
//  if (sliderHeight > 0)        // Slider
//  {
//    if (slider.y < (bounds.y + GuiGetStyle(SLIDER, BORDER_WIDTH))) slider.y = bounds.y + GuiGetStyle(SLIDER, BORDER_WIDTH);
//    else if ((slider.y + slider.height) >= (bounds.y + bounds.height)) slider.y = bounds.y + bounds.height - slider.height - GuiGetStyle(SLIDER, BORDER_WIDTH);
//  }
//  else if (sliderHeight == 0)  // SliderBar
//  {
//    if (slider.y < (bounds.y + GuiGetStyle(SLIDER, BORDER_WIDTH)))
//    {
//      slider.y = bounds.y + GuiGetStyle(SLIDER, BORDER_WIDTH);
//      slider.height = bounds.height - 2 * GuiGetStyle(SLIDER, BORDER_WIDTH);
//    }
//  }
//
//  //--------------------------------------------------------------------
//  // Draw control
//  //--------------------------------------------------------------------
//  GuiDrawRectangle(bounds, GuiGetStyle(SLIDER, BORDER_WIDTH), Fade(GetColor(GuiGetStyle(SLIDER, BORDER + (state * 3))), guiAlpha), Fade(GetColor(GuiGetStyle(SLIDER, (state != STATE_DISABLED) ? BASE_COLOR_NORMAL : BASE_COLOR_DISABLED)), guiAlpha));
//
//  // Draw slider internal bar (depends on state)
//  if ((state == STATE_NORMAL) || (state == STATE_PRESSED)) GuiDrawRectangle(slider, 0, BLANK, Fade(GetColor(GuiGetStyle(SLIDER, BASE_COLOR_PRESSED)), guiAlpha));
//  else if (state == STATE_FOCUSED) GuiDrawRectangle(slider, 0, BLANK, Fade(GetColor(GuiGetStyle(SLIDER, TEXT_COLOR_FOCUSED)), guiAlpha));
//
//  // Draw top/bottom text if provided
//  if (textTop != NULL)
//  {
//    Rectangle textBounds = { 0 };
//    textBounds.width = (float)GetTextWidth(textTop);
//    textBounds.height = (float)GuiGetStyle(DEFAULT, TEXT_SIZE);
//    textBounds.x = bounds.x + bounds.width / 2 - textBounds.width / 2;
//    textBounds.y = bounds.y - textBounds.height - GuiGetStyle(SLIDER, TEXT_PADDING);
//
//    GuiDrawText(textTop, textBounds, TEXT_ALIGN_RIGHT, Fade(GetColor(GuiGetStyle(SLIDER, TEXT + (state * 3))), guiAlpha));
//  }
//
//  if (textBottom != NULL)
//  {
//    Rectangle textBounds = { 0 };
//    textBounds.width = (float)GetTextWidth(textBottom);
//    textBounds.height = (float)GuiGetStyle(DEFAULT, TEXT_SIZE);
//    textBounds.x = bounds.x + bounds.width / 2 - textBounds.width / 2;
//    textBounds.y = bounds.y + bounds.height + GuiGetStyle(SLIDER, TEXT_PADDING);
//
//    GuiDrawText(textBottom, textBounds, TEXT_ALIGN_LEFT, Fade(GetColor(GuiGetStyle(SLIDER, TEXT + (state * 3))), guiAlpha));
//  }
//  //--------------------------------------------------------------------
//
//  return value;
//}
//
//float GuiVerticalSlider(Rectangle bounds, const char* textTop, const char* textBottom, float value, float minValue, float maxValue)
//{
//  return GuiVerticalSliderPro(bounds, textTop, textBottom, value, minValue, maxValue, GuiGetStyle(SLIDER, SLIDER_WIDTH));
//}
//
//float GuiVerticalSliderBar(Rectangle bounds, const char* textTop, const char* textBottom, float value, float minValue, float maxValue)
//{
//  return GuiVerticalSliderPro(bounds, textTop, textBottom, value, minValue, maxValue, 0);
//}
//
//bool GuiSliderProOwning(Rectangle bounds, const char* textLeft, const char* textRight, float* value, float minValue, float maxValue, int sliderWidth, bool editMode)
//{
//  GuiState state = (GuiState)GuiGetState();
//
//  float tempValue = *value;
//  bool pressed = false;
//
//  int sliderValue = (int)(((tempValue - minValue) / (maxValue - minValue)) * (bounds.width - 2 * GuiGetStyle(SLIDER, BORDER_WIDTH)));
//
//  Rectangle slider = {
//      bounds.x,
//      bounds.y + GuiGetStyle(SLIDER, BORDER_WIDTH) + GuiGetStyle(SLIDER, SLIDER_PADDING),
//      0,
//      bounds.height - 2 * GuiGetStyle(SLIDER, BORDER_WIDTH) - 2 * GuiGetStyle(SLIDER, SLIDER_PADDING)
//  };
//
//  if (sliderWidth > 0)        // Slider
//  {
//    slider.x += (sliderValue - sliderWidth / 2);
//    slider.width = (float)sliderWidth;
//  }
//  else if (sliderWidth == 0)  // SliderBar
//  {
//    slider.x += GuiGetStyle(SLIDER, BORDER_WIDTH);
//    slider.width = (float)sliderValue;
//  }
//
//  // Update control
//  //--------------------------------------------------------------------
//  if ((state != STATE_DISABLED) && (editMode || !guiLocked))
//  {
//    Vector2 mousePoint = GetMousePosition();
//
//    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
//    {
//      if (CheckCollisionPointRec(mousePoint, bounds))
//      {
//        pressed = true;
//      }
//    }
//    else if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && editMode)
//    {
//      pressed = true;
//    }
//    if (editMode)
//    {
//      state = STATE_PRESSED;
//      tempValue = ((maxValue - minValue) * (mousePoint.x - (float)(bounds.x + sliderWidth / 2))) / (float)(bounds.width - sliderWidth) + minValue;
//
//      if (sliderWidth > 0) slider.x = mousePoint.x - slider.width / 2;  // Slider
//      else if (sliderWidth == 0) slider.width = (float)sliderValue;          // SliderBar
//
//    }
//    else if (CheckCollisionPointRec(mousePoint, bounds))
//    {
//      state = STATE_FOCUSED;
//    }
//
//    if (tempValue > maxValue) tempValue = maxValue;
//    else if (tempValue < minValue) tempValue = minValue;
//  }
//
//
//  // Bar limits check
//  if (sliderWidth > 0)        // Slider
//  {
//    if (slider.x <= (bounds.x + GuiGetStyle(SLIDER, BORDER_WIDTH))) slider.x = bounds.x + GuiGetStyle(SLIDER, BORDER_WIDTH);
//    else if ((slider.x + slider.width) >= (bounds.x + bounds.width)) slider.x = bounds.x + bounds.width - slider.width - GuiGetStyle(SLIDER, BORDER_WIDTH);
//  }
//  else if (sliderWidth == 0)  // SliderBar
//  {
//    if (slider.width > bounds.width) slider.width = bounds.width - 2 * GuiGetStyle(SLIDER, BORDER_WIDTH);
//  }
//
//  //--------------------------------------------------------------------
//  // Draw control
//  //--------------------------------------------------------------------
//  GuiDrawRectangle(bounds, GuiGetStyle(SLIDER, BORDER_WIDTH), Fade(GetColor(GuiGetStyle(SLIDER, BORDER + (state * 3))), guiAlpha), Fade(GetColor(GuiGetStyle(SLIDER, (state != STATE_DISABLED) ? BASE_COLOR_NORMAL : BASE_COLOR_DISABLED)), guiAlpha));
//
//  // Draw slider internal bar (depends on state)
//  if ((state == STATE_NORMAL) || (state == STATE_PRESSED))
//    GuiDrawRectangle(slider, 0, BLANK, Fade(GetColor(GuiGetStyle(SLIDER, BASE_COLOR_PRESSED)), guiAlpha));
//  else if (state == STATE_FOCUSED)
//    GuiDrawRectangle(slider, 0, BLANK, Fade(GetColor(GuiGetStyle(SLIDER, TEXT_COLOR_FOCUSED)), guiAlpha));
//
//  // Draw left/right text if provided
//  if (textLeft != NULL)
//  {
//    Rectangle textBounds = { 0 };
//    textBounds.width = (float)GetTextWidth(textLeft);
//    textBounds.height = (float)GuiGetStyle(DEFAULT, TEXT_SIZE);
//    textBounds.x = bounds.x - textBounds.width - GuiGetStyle(SLIDER, TEXT_PADDING);
//    textBounds.y = bounds.y + bounds.height / 2 - GuiGetStyle(DEFAULT, TEXT_SIZE) / 2;
//
//    GuiDrawText(textLeft, textBounds, TEXT_ALIGN_RIGHT, Fade(GetColor(GuiGetStyle(SLIDER, TEXT + (state * 3))), guiAlpha));
//  }
//
//  if (textRight != NULL)
//  {
//    Rectangle textBounds = { 0 };
//    textBounds.width = (float)GetTextWidth(textRight);
//    textBounds.height = (float)GuiGetStyle(DEFAULT, TEXT_SIZE);
//    textBounds.x = bounds.x + bounds.width + GuiGetStyle(SLIDER, TEXT_PADDING);
//    textBounds.y = bounds.y + bounds.height / 2 - GuiGetStyle(DEFAULT, TEXT_SIZE) / 2;
//
//    GuiDrawText(textRight, textBounds, TEXT_ALIGN_LEFT, Fade(GetColor(GuiGetStyle(SLIDER, TEXT + (state * 3))), guiAlpha));
//  }
//  //--------------------------------------------------------------------
//
//  *value = tempValue;
//  return pressed;
//}
//
//bool GuiSliderOwning(Rectangle bounds, const char* textLeft, const char* textRight, float* value, float minValue, float maxValue, bool editMode)
//{
//  return GuiSliderProOwning(bounds, textLeft, textRight, value, minValue, maxValue, GuiGetStyle(SLIDER, SLIDER_WIDTH), editMode);
//}
//
//bool GuiSliderBarOwning(Rectangle bounds, const char* textLeft, const char* textRight, float* value, float minValue, float maxValue, bool editMode)
//{
//  return GuiSliderProOwning(bounds, textLeft, textRight, value, minValue, maxValue, 0, editMode);
//}
//
//bool GuiVerticalSliderProOwning(Rectangle bounds, const char* textTop, const char* textBottom, float* value, float minValue, float maxValue, int sliderHeight, bool editMode)
//{
//  GuiState state = (GuiState)GuiGetState();
//
//  float tempValue = *value;
//  bool pressed = false;
//
//  int sliderValue = (int)(((tempValue - minValue) / (maxValue - minValue)) * (bounds.height - 2 * GuiGetStyle(SLIDER, BORDER_WIDTH)));
//
//  Rectangle slider = {
//      bounds.x + GuiGetStyle(SLIDER, BORDER_WIDTH) + GuiGetStyle(SLIDER, SLIDER_PADDING),
//      bounds.y + bounds.height - sliderValue,
//      bounds.width - 2 * GuiGetStyle(SLIDER, BORDER_WIDTH) - 2 * GuiGetStyle(SLIDER, SLIDER_PADDING),
//      0.0f,
//  };
//
//  if (sliderHeight > 0)        // Slider
//  {
//    slider.y -= sliderHeight / 2;
//    slider.height = (float)sliderHeight;
//  }
//  else if (sliderHeight == 0)  // SliderBar
//  {
//    slider.y -= GuiGetStyle(SLIDER, BORDER_WIDTH);
//    slider.height = (float)sliderValue;
//  }
//  // Update control
//  //--------------------------------------------------------------------
//  if ((state != STATE_DISABLED) && (editMode || !guiLocked))
//  {
//    Vector2 mousePoint = GetMousePosition();
//
//    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
//    {
//      if (CheckCollisionPointRec(mousePoint, bounds))
//      {
//        pressed = true;
//      }
//    }
//    else if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && editMode)
//    {
//      pressed = true;
//    }
//    if (editMode)
//    {
//      state = STATE_PRESSED;
//
//      float normalizedValue = (bounds.y + bounds.height - mousePoint.y - (float)(sliderHeight / 2)) / (bounds.height - (float)sliderHeight);
//      tempValue = (maxValue - minValue) * normalizedValue + minValue;
//
//      if (sliderHeight > 0) slider.y = mousePoint.y - slider.height / 2;  // Slider
//      else if (sliderHeight == 0)                                          // SliderBar
//      {
//        slider.y = mousePoint.y;
//        slider.height = bounds.y + bounds.height - slider.y - GuiGetStyle(SLIDER, BORDER_WIDTH);
//      }
//    }
//    else if (CheckCollisionPointRec(mousePoint, bounds))
//    {
//      state = STATE_FOCUSED;
//    }
//
//    if (tempValue > maxValue) tempValue = maxValue;
//    else if (tempValue < minValue) tempValue = minValue;
//  }
//
//
//  // Bar limits check
//  if (sliderHeight > 0)        // Slider
//  {
//    if (slider.y < (bounds.y + GuiGetStyle(SLIDER, BORDER_WIDTH))) slider.y = bounds.y + GuiGetStyle(SLIDER, BORDER_WIDTH);
//    else if ((slider.y + slider.height) >= (bounds.y + bounds.height)) slider.y = bounds.y + bounds.height - slider.height - GuiGetStyle(SLIDER, BORDER_WIDTH);
//  }
//  else if (sliderHeight == 0)  // SliderBar
//  {
//    if (slider.y < (bounds.y + GuiGetStyle(SLIDER, BORDER_WIDTH)))
//    {
//      slider.y = bounds.y + GuiGetStyle(SLIDER, BORDER_WIDTH);
//      slider.height = bounds.height - 2 * GuiGetStyle(SLIDER, BORDER_WIDTH);
//    }
//  }
//
//  //--------------------------------------------------------------------
//  // Draw control
//  //--------------------------------------------------------------------
//  GuiDrawRectangle(bounds, GuiGetStyle(SLIDER, BORDER_WIDTH), Fade(GetColor(GuiGetStyle(SLIDER, BORDER + (state * 3))), guiAlpha), Fade(GetColor(GuiGetStyle(SLIDER, (state != STATE_DISABLED) ? BASE_COLOR_NORMAL : BASE_COLOR_DISABLED)), guiAlpha));
//
//  // Draw slider internal bar (depends on state)
//  if ((state == STATE_NORMAL) || (state == STATE_PRESSED))
//    GuiDrawRectangle(slider, 0, BLANK, Fade(GetColor(GuiGetStyle(SLIDER, BASE_COLOR_PRESSED)), guiAlpha));
//  else if (state == STATE_FOCUSED)
//    GuiDrawRectangle(slider, 0, BLANK, Fade(GetColor(GuiGetStyle(SLIDER, TEXT_COLOR_FOCUSED)), guiAlpha));
//
//  // Draw top/bottom text if provided
//  if (textTop != NULL)
//  {
//    Rectangle textBounds = { 0 };
//    textBounds.width = (float)GetTextWidth(textTop);
//    textBounds.height = (float)GuiGetStyle(DEFAULT, TEXT_SIZE);
//    textBounds.x = bounds.x + bounds.width / 2 - textBounds.width / 2;
//    textBounds.y = bounds.y - textBounds.height - GuiGetStyle(SLIDER, TEXT_PADDING);
//
//    GuiDrawText(textTop, textBounds, TEXT_ALIGN_RIGHT, Fade(GetColor(GuiGetStyle(SLIDER, TEXT + (state * 3))), guiAlpha));
//  }
//
//  if (textBottom != NULL)
//  {
//    Rectangle textBounds = { 0 };
//    textBounds.width = (float)GetTextWidth(textBottom);
//    textBounds.height = (float)GuiGetStyle(DEFAULT, TEXT_SIZE);
//    textBounds.x = bounds.x + bounds.width / 2 - textBounds.width / 2;
//    textBounds.y = bounds.y + bounds.height + GuiGetStyle(SLIDER, TEXT_PADDING);
//
//    GuiDrawText(textBottom, textBounds, TEXT_ALIGN_LEFT, Fade(GetColor(GuiGetStyle(SLIDER, TEXT + (state * 3))), guiAlpha));
//  }
//  //--------------------------------------------------------------------
//
//  *value = tempValue;
//  return pressed;
//}
//
//bool GuiVerticalSliderOwning(Rectangle bounds, const char* textTop, const char* textBottom, float* value, float minValue, float maxValue, bool editMode)
//{
//  return GuiVerticalSliderProOwning(bounds, textTop, textBottom, value, minValue, maxValue, GuiGetStyle(SLIDER, SLIDER_WIDTH), editMode);
//}
//
//bool GuiVerticalSliderBarOwning(Rectangle bounds, const char* textTop, const char* textBottom, float* value, float minValue, float maxValue, bool editMode)
//{
//  return GuiVerticalSliderProOwning(bounds, textTop, textBottom, value, minValue, maxValue, 0, editMode);
//}