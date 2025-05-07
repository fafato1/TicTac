#include <UI/Public/BaseUI.h>

BaseUI::BaseUI(UIManager* UIManager)
{
	AUIManager = UIManager;
}

void BaseUI::RemoveFromParent() const
{
	delete this;
}

void BaseUI::OnCreate()
{
	// Initialization code here
}

void BaseUI::OnDestroy()
{
	// Cleanup code here
}


