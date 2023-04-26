#pragma once
#include "yaResource.h"
// yaResource�� �������ִ� Class 

class Resources
{
public:
	template<typename T>
	static T* Find(const std::wstring& key)
	{
		// ���ҽ��ʿ��� �����͸� Ž���Ѵ� �����Ͱ� �ִٸ� �ش絥���͸� ��ȯ�ϰ�
		// �����Ͱ� ���ٸ� end�� ��ȯ���ش�.
		// iterator�� �����ΰ�?
		// handle�� ���������� ���������� ���ϰ� �Ѵ�.
		// �׷��� �ڱ� ������ ���� ���ϰ� �ϱ� �����̴�.
		std::map<std::wstring, Resource*>::iterator iter = mResources.find(key);

		//ã���� �ϴ� �����Ͱ� �����Ѵٸ�
		//�ش�Ÿ������ ����ȯ�Ͽ� ��ȯ
		// end�� �ƴ϶�� �� �����Ͱ� �ִٴ� ���̴�.
		if (iter != mResources.end())
		{
			return dynamic_cast<T*>(iter->second);
		}

		//������ ���ٸ� ���� ��ȯ
		return nullptr;
	}

	template<typename T>
	static T* Load(const std::wstring& key, const std::wstring& path)
	{
		// Ű ������ Ž��
		T* resource = Resources::Find<T>(key);
		if (resource != nullptr)
		{
			return resource;
		}

		resource = new T();

		// �ش� ���ҽ��� ���ٸ�
		if (FAILED(resource->Load(path)))
		{
			// �����ߴٸ� assert�Ǵ�.
			assert(false);
			return nullptr;
		}

		// Ű �Է����ְ� ��� �������ش�.
		resource->SetKey(key);
		resource->SetPath(path);
		mResources.insert(std::make_pair(key, resource));

		return dynamic_cast<T*>(resource);

	}
	template <typename T>
	static void Insert(const std::wstring& key, T* resource)
	{
		mResources.insert(std::make_pair(key, resource));
	}

	static void Release()
	{
		for (auto pair : mResources)
		{
			// pair.second : �� ��°���ڸ� ��ȯ�Ѵ�.
			// ���⼭ �ι�° ���ڴ� (key,resource)���� resource�̴�
			delete pair.second;
			pair.second = nullptr;
		}
	}
private:
	// Map�� map<key type,value type>�̸� �̷��� ������ �Ǿ��ִ�.
	// ���⼭ Key�� std::wstring value�� Resource*
	// value : ���� ���� ���� ������
	// key : �ܼ��ϰ� ���� ã�� ���� �����ϱ� ���� �뵵�θ� ���Ǵ� ���̴�.
	static std::map<std::wstring, Resource*> mResources;
};

