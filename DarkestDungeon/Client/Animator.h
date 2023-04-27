#pragma once
#include "Component.h"
#include "Animation.h"
#include "Image.h"

// Animator�� Component�̱� ������ Component�� ��ӹ޴´�.
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

		// �ڵ� �����̰� ����ǰԲ� �Ҷ� � ������ ����� ?
		// �Լ� ������
		// �Լ� �����Ͱ� ���������� ���� ���Ƽ� �����ϴ�
		// STL�� functional�̶�� �Լ��� �ִ�.
		// �Լ� �����͸� Ŭ������ �� ��� ���ϰ� ���� �ְ� �������.
		//void(*name)(int, int);
		std::function<void()> mEvent;
	};
	struct Events
	{
		// ���� ó�� �ִϸ��̼��� ���۵� �� ���;��ϴ� event
		Event mStartEvent;
		// �ִϸ��̼��� �� �������� �� ������ �� ȣ�� �Ǵ� �Լ�
		Event mCompleteEvent;
		// �ִϸ��̼��� ��ȯ�� �� ȣ��Ǵ� �Լ�
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

	//�ϼ��� ��������Ʈ ��Ʈ�� �����ؼ� �ִϸ��̼� �����ϴ� �Լ�
	void CreateAnimation(const std::wstring& name
		, Image* sheet
		, Vector2 leftTop
		, UINT coulmn, UINT row, UINT spriteLength
		, Vector2 offset, float duration);

	// ������ ����ִ� ��������Ʈ���� �̿��ؼ� �ִϸ��̼� �������ִ� �Լ�
	void CreateAnimations(const std::wstring& path, Vector2 offset, float duration);

	// ���� ���ϴ� �̹��� ã�ƿ� �� �ְ�
	Animation* FindAnimation(const std::wstring& name);
	// �ִϸ��̼� Paly
	// �ѹ��� ����ϰ� ���ų� �� ����Ұų� loop�ɼ�
	void Play(const std::wstring& name, bool loop);

	Events* FindEvents(const std::wstring& name);
	std::function<void()>& GetStartEvent(const std::wstring& name);
	std::function<void()>& GetCompleteEvent(const std::wstring& name);
	std::function<void()>& GetEndEvent(const std::wstring& name);
	bool IsComplte() { return mActiveAnimation->IsComplete(); }


private:
	// �����͸� ���� ã���� ���� �ڷᱸ�� Map
	std::map<std::wstring, Animation*> mAnimations;
	std::map<std::wstring, Events*> mEvents;

	Animation* mActiveAnimation;
	Image* mSpriteSheet;
	bool mbLoop;
};
