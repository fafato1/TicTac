#include <UI/Public/BaseUI.h>

BaseUI::BaseUI(UIManager* UIManager)
{
	AUIManager = UIManager;
}

void BaseUI::RemoveFromParent()
{

}

void BaseUI::OnCreate()
{
	// Initialization code here
}

void BaseUI::OnDestroy()
{
	// Cleanup code here
}

Vector2 BaseUI::GetScreenCenter()  {
	return { GetScreenWidth() / 2.f, GetScreenHeight() / 2.f };
}
