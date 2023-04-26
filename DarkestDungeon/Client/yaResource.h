#pragma once
#include "Entity.h"

// 순수가상함수를 하나라도 포함하고 있다면 
// 추상클래스가 된다.
// 그래서 메모리할당 자체가 안된다.
// 오로지 상속만 받아서 사용하라.
class Resource
{
public:
	Resource();
	//virtual 이라는 순수가상함수를 하나라도 포함하고 있기때문에
	// 추상클래스가 된다.
	virtual ~Resource();

	//폴더 경로
	// = 0(순수가상함수) 을 붙이면 얘를 상속받는 모든 애들들은 필수적으로 구현해줘야 한다.
	virtual HRESULT Load(const std::wstring& path) = 0;

	// wstring에 &(참조)를 안붙이면 값이 복사되기때문에
	// 예를 들어 문자열이 120글자면 내부에서 for문을 계속 돌려서 넘기기 때문에
	// 참조를 붙여서 주소로 넘겨야 한다.
	const std::wstring& GetKey() { return mKey; }
	const std::wstring& GetPath() { return mPath; }
	void SetKey(const std::wstring& key) { mKey = key; }
	void SetPath(const std::wstring& path) { mPath = path; }

private:
	// wstring은 문자열 자료형이다
	std::wstring mKey;
	std::wstring mPath;

};

