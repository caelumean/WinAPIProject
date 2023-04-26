#pragma once
#include "Engine.h"

class Entity
{
public:
	Entity();
	// 상속받아 쓸 거기 때문에 virtual 붙여줘야한다.
	// 안붙여주면 부모클래스 형태로 보관하고 있을 때 
	// 자식 클래스꺼의 소멸자가 호출이 안된다.
	virtual ~Entity();

	void SetName(const std::wstring& name) { mName = name; }
	std::wstring& GetName() { return mName; }
	void SetID(UINT64 id) { mID = id; }
	UINT64 GetID() { return mID; }

private:
	// 클래스의 이름
	// 만들어지 객체의 이름을 셋팅할 수 있게끔
	std::wstring mName;
	UINT64 mID;
};

