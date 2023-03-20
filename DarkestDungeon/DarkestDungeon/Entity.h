#pragma once
#include "Engine.h"

class Entity
{
public:
	Entity();
	virtual ~Entity();

	void SetName(const std::wstring& name) { mName = name; }
	std::wstring& GetName() { return mName; }
private:
	std::wstring mName;
};

