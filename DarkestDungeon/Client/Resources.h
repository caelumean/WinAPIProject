#pragma once
#include "yaResource.h"
// yaResource를 관리해주는 Class 

class Resources
{
public:
	template<typename T>
	static T* Find(const std::wstring& key)
	{
		// 리소스맵에서 데이터를 탐색한다 데이터가 있다면 해당데이터를 반환하고
		// 데이터가 없다면 end를 반환해준다.
		// iterator란 무엇인가?
		// handle과 마찬가지로 직접접근을 못하게 한다.
		// 그래서 자기 정보는 변경 못하게 하기 위함이다.
		std::map<std::wstring, Resource*>::iterator iter = mResources.find(key);

		//찾고자 하는 데이터가 존재한다면
		//해당타입으로 형변환하여 반환
		// end가 아니라는 건 데이터가 있다는 뜻이다.
		if (iter != mResources.end())
		{
			return dynamic_cast<T*>(iter->second);
		}

		//데이터 없다면 널을 반환
		return nullptr;
	}

	template<typename T>
	static T* Load(const std::wstring& key, const std::wstring& path)
	{
		// 키 값으로 탐색
		T* resource = Resources::Find<T>(key);
		if (resource != nullptr)
		{
			return resource;
		}

		resource = new T();

		// 해당 리소스가 없다면
		if (FAILED(resource->Load(path)))
		{
			// 실패했다면 assert건다.
			assert(false);
			return nullptr;
		}

		// 키 입력해주고 경로 세팅해준다.
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
			// pair.second : 두 번째인자를 반환한다.
			// 여기서 두번째 인자는 (key,resource)에서 resource이다
			delete pair.second;
			pair.second = nullptr;
		}
	}
private:
	// Map은 map<key type,value type>이름 이렇게 구성이 되어있다.
	// 여기서 Key는 std::wstring value는 Resource*
	// value : 실제 사용될 저장 데이터
	// key : 단순하게 빨리 찾기 위해 정렬하기 위한 용도로만 사용되는 것이다.
	static std::map<std::wstring, Resource*> mResources;
};

