#pragma once
#include "Component.h"
#include "Animation.h"
#include "Image.h"

// Animator가 Component이기 때문에 Component를 상속받는다.
class Animator : public Component
{
public:
	struct Event
	{
		void operator=(std::function<void()> func)
		{
			mEvent = std::move(func);
		}
		void operator()()
		{
			if (mEvent)
				mEvent();
		}

		// 코드 뭉탱이가 실행되게끔 할때 어떤 문법이 쉬울까 ?
		// 함수 포인터
		// 함수 포인터가 문법적으로 쓸게 많아서 불편하다
		// STL에 functional이라는 함수가 있다.
		// 함수 포인터를 클래스로 잘 묶어서 편하게 쓸수 있게 만들었다.
		//void(*name)(int, int);
		std::function<void()> mEvent;
	};
	struct Events
	{
		// 제일 처음 애니메이션이 시작될 때 나와야하는 event
		Event mStartEvent;
		// 애니메이션이 한 프레임이 다 돌았을 때 호출 되는 함수
		Event mCompleteEvent;
		// 애니메이션이 전환될 때 호출되는 함수
		Event mEndEvent;

		//mStartEvent();
		//mStartEvent = test;
	};
	Animator();
	~Animator();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	//완성된 스프라이트 시트를 지정해서 애니메이션 제작하는 함수
	void CreateAnimation(const std::wstring& name
		, Image* sheet
		, Vector2 leftTop
		, UINT coulmn, UINT row, UINT spriteLength
		, Vector2 offset, float duration);

	// 폴더에 들어있는 스프라이트들을 이용해서 애니메이션 제작해주는 함수
	void CreateAnimations(const std::wstring& path, Vector2 offset, float duration);

	// 내가 원하는 이미지 찾아올 수 있게
	Animation* FindAnimation(const std::wstring& name);
	// 애니메이션 Paly
	// 한번만 재생하고 말거냐 더 재생할거냐 loop옵션
	void Play(const std::wstring& name, bool loop);

	Events* FindEvents(const std::wstring& name);
	std::function<void()>& GetStartEvent(const std::wstring& name);
	std::function<void()>& GetCompleteEvent(const std::wstring& name);
	std::function<void()>& GetEndEvent(const std::wstring& name);
	bool IsComplte() { return mActiveAnimation->IsComplete(); }


private:
	// 데이터를 빨리 찾을때 쓰는 자료구조 Map
	std::map<std::wstring, Animation*> mAnimations;
	std::map<std::wstring, Events*> mEvents;

	Animation* mActiveAnimation;
	Image* mSpriteSheet;
	bool mbLoop;
};

