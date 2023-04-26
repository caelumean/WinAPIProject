#pragma once
#include "Engine.h"

class Entity
{
public:
	Entity();
	// ��ӹ޾� �� �ű� ������ virtual �ٿ�����Ѵ�.
	// �Ⱥٿ��ָ� �θ�Ŭ���� ���·� �����ϰ� ���� �� 
	// �ڽ� Ŭ�������� �Ҹ��ڰ� ȣ���� �ȵȴ�.
	virtual ~Entity();

	void SetName(const std::wstring& name) { mName = name; }
	std::wstring& GetName() { return mName; }
	void SetID(UINT64 id) { mID = id; }
	UINT64 GetID() { return mID; }

private:
	// Ŭ������ �̸�
	// ������� ��ü�� �̸��� ������ �� �ְԲ�
	std::wstring mName;
	UINT64 mID;
};

