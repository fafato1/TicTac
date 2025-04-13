#pragma once

#include <UI/Public/BaseUI.h>

class GameScreen : public BaseUI
{

public:
	explicit GameScreen(UIManager *UIManager)
		: BaseUI(UIManager) {
	}

	void OnUpdate(float DeltaTime) override;

	void SetupScreen() override;

	void OnCreate() override;

	~GameScreen() override;

	void OnDestroy() override;

private:

	// Config - Default values
	const Color LineColor = WHITE;
	const int LineTickness = 10;
	const float BorderOffset = 300.f;
	const float LineOffset = 100.f;

};
