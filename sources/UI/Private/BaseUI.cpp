#include <UI/Public/BaseUI.h>
#include <UI/Public/UIManager.h>

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