#pragma once
#include <memory>

class UIManager; // Forward declaration

class BaseUI
{
public:

	BaseUI(UIManager* UIManager);
	~BaseUI() = default;

	
	virtual void OnUpdate(float DeltaTime) = 0;

	virtual void OnCreate();

	void RemoveFromParent();

	virtual void OnDestroy();

private:

	UIManager* AUIManager;
};
