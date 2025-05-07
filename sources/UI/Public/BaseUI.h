#pragma once

class UIManager; // Forward declaration

class BaseUI
{
public:

	explicit BaseUI(UIManager* UIManager);

	virtual ~BaseUI() = default;

	virtual void OnUpdate(float DeltaTime) = 0;

	virtual void OnCreate() = 0;

	virtual void SetupScreen() = 0;

	void RemoveFromParent() const;

	virtual void OnDestroy();

private:

	UIManager* AUIManager;
};
