#pragma once
#include <vector>
#include <memory>

class BaseUI;

class UIManager
{
public:

	void OnUpdate(float DeltaTime);

	void Destroy(BaseUI* BaseUIRef);

	template<typename T>
	T* Create()
	{
		auto NewUI = std::make_shared<T>(this);
		UIList.push_back(NewUI);
		NewUI->OnCreate();
		return NewUI.get();
	}

private:
	std::vector<std::shared_ptr<BaseUI>> UIList;

};
