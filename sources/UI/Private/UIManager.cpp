#include <UI/Public/UIManager.h>
#include <UI/Public/BaseUI.h>
#include <algorithm>
#include <iostream>


void UIManager::Destroy(BaseUI* BaseUIRef)
{
	const std::ranges::borrowed_iterator_t<std::vector<std::shared_ptr<BaseUI> > &> ToDestroy = std::ranges::find_if(UIList,
		[BaseUIRef](const std::shared_ptr<BaseUI> &ptr)
		{
			return ptr.get() == BaseUIRef;
		});
	if (ToDestroy != UIList.end())
	{
		ToDestroy->get()->RemoveFromParent();
		UIList.erase(ToDestroy);
	}
	else
	{
		std::cout<< "";
	}
}
