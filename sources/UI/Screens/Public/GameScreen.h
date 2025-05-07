#pragma once

#include <array>

#include <UI/Public/BaseUI.h>

#include "raylib.h"
#include "Core/Public/Game.h"


class GameScreen : public BaseUI, Core
{

public:
	explicit GameScreen(UIManager *UIManager): BaseUI(UIManager){}

	void OnUpdate(float DeltaTime) override;

	void SetupScreen() override;

	void OnCreate() override;

	~GameScreen() override;

	void OnDestroy() override;

	// Config - Default values
	const Color LineColor = WHITE;
	const float LineThickness = 10;


private:




};
