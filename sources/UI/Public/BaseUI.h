#pragma once
#include <raylib.h>

class UIManager; // Forward declaration

class BaseUI
{
public:

	BaseUI(UIManager* UIManager);

	virtual ~BaseUI() = default;

	virtual void OnUpdate(float DeltaTime) = 0;

	virtual void OnCreate() = 0;

	virtual void SetupScreen() = 0;

	void RemoveFromParent();

	virtual void OnDestroy();

	Vector2 GetScreenCenter();

private:

	UIManager* AUIManager;
};
