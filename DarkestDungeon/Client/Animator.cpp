#include "Animator.h"
#include "Resources.h"

Animator::Animator()
	: Component(eComponentType::Animator)
	, mActiveAnimation(nullptr)
	, mSpriteSheet(nullptr)
	, mbLoop(false)
{
}

Animator::~Animator()
{
	for (auto animation : mAnimations)
	{
		delete animation.second;
		animation.second = nullptr;
	}
	for (auto events : mEvents)
	{
		delete events.second;
		events.second = nullptr;
	}
}

void Animator::Initialize()
{

}

void Animator::Update()
{
	if (mActiveAnimation)
	{
		mActiveAnimation->Update();

		// loop�� ���̰� IsComplete�� ���̶��
		// �ٽ� ���� ���Ѿߵȴ�.
		// �� ���ٰ� ���� �����ߴٴ� ��
		if (mActiveAnimation->IsComplete())
		{
			Animator::Events* events
				= FindEvents(mActiveAnimation->GetName());

			if (events != nullptr)
				events->mCompleteEvent();
		}
		if (mbLoop && mActiveAnimation->IsComplete())
			mActiveAnimation->Reset();
	}
}

void Animator::Render(HDC hdc)
{
	if (mActiveAnimation)
	{
		mActiveAnimation->Render(hdc);
	}
}

void Animator::Release()
{
}

void Animator::CreateAnimation(const std::wstring& name
	, Image* sheet, Vector2 leftTop
	, UINT coulmn, UINT row, UINT spriteLength
	, Vector2 offset, float duration)
{
	Animation* animation = FindAnimation(name);

	if (animation != nullptr)
		return;

	animation = new Animation();
	animation->Create(sheet, leftTop, coulmn, row, spriteLength, offset, duration);
	animation->SetAnimationName(name);
	animation->SetAnimator(this);

	mAnimations.insert(std::make_pair(name, animation));
	Events* event = new Events();
	mEvents.insert(std::make_pair(name, event));
}

void Animator::CreateAnimations(const std::wstring& path, Vector2 offset, float duration)
{
	// ���� , ���� ,������ ����
	UINT width = 0;
	UINT height = 0;
	UINT fileCount = 0;

	std::filesystem::path fs(path);
	std::vector<Image*> images = {};

	// �� ���� ��ο� ���ϵ��� ��ȸ�� �� �ִ� ���.
	for (const auto& p : std::filesystem::recursive_directory_iterator(path))
	{
		std::wstring fileName = p.path().filename();
		std::wstring fullName = path + L"\\" + fileName;

		// ���� ��ο��� .png����
		const std::wstring ext = p.path().extension();
		if (ext == L".png")
			continue;
		// fileName�� key�̰� fullName�� ���
		Image* image = Resources::Load<Image>(fileName, fullName);
		images.push_back(image);

		if (width < image->GetWidth())
		{
			width = image->GetWidth();
		}
		if (height < image->GetHeight())
		{
			height = image->GetHeight();
		}
		fileCount++;
	}
	// parent_path : �θ� ���
	// filename : ���� �̸�
	std::wstring key = fs.parent_path().filename();
	key += fs.filename();
	mSpriteSheet = Image::Create(key, width * fileCount, height);

	// �̹��� ������ŭ �ݺ����� ������.
	int index = 0;
	for (Image* image : images)
	{
		// ���ݸ�ŭ�� ���� �Ǵϱ� 
		// (���� - �̹��� ����)/2 �ϸ� �ȴ�.
		// ���̶��� ���������̴�.
		// ���̴� �� �Ʒ��� �� ���� �����ָ� �߰��� �´�.
		int centerX = (width - image->GetWidth()) / 2;
		int centerY = (height - image->GetHeight());


		// �̹����� �������ִ� ��
		// int x1 int y1�� ��ǥ�̴�
		BitBlt(mSpriteSheet->GetHdc()
			, width * index + centerX
			, 0 + centerY
			, image->GetWidth(), image->GetHeight()
			, image->GetHdc(), 0, 0, SRCCOPY);
		index++;
	}


	// ���� �ٽ� CreateAnimation�� ȣ���ϸ� �ȴ�.
	// file name�� key�� �� �ְ� sheet�� mSpriteSheet 
	// leftTop�� 0,0�̱� ������ Vector2::Zero
	// �̹��� ������ index++�ϸ� ��
	// row�� �켱 1��
	// ���� �̹��� ���� ���� index
	// offset : �� ���� �Ǵ� ������ ������ �޸� �ּ� ������ �Ÿ�
	//			���� �̹������� �Ÿ�?
	// duration : ������ ������ �ð��� ����.
	CreateAnimation(key, mSpriteSheet, Vector2::Zero, index, 1, index, offset, duration);
}

Animation* Animator::FindAnimation(const std::wstring& name)
{
	std::map<std::wstring, Animation*>::iterator iter
		= mAnimations.find(name);

	// map�ȿ� ���� ��
	if (iter == mAnimations.end())
		return nullptr;
	// �ƴ϶�� iterator�� second
	return iter->second;
}

void Animator::Play(const std::wstring& name, bool loop)
{
	if (mActiveAnimation != nullptr)
	{
		Animator::Events* prevEvents
			= FindEvents(mActiveAnimation->GetName());

		if (prevEvents != nullptr)
			prevEvents->mEndEvent();
	}

	mActiveAnimation = FindAnimation(name);
	mActiveAnimation->Reset();
	mbLoop = loop;

	Animator::Events* events
		= FindEvents(mActiveAnimation->GetName());

	if (events != nullptr)
		events->mStartEvent();
}

Animator::Events* Animator::FindEvents(const std::wstring& name)
{
	std::map<std::wstring, Events*>::iterator iter
		= mEvents.find(name);

	if (iter == mEvents.end())
		return nullptr;

	return iter->second;
}

std::function<void()>& Animator::GetStartEvent(const std::wstring& name)
{
	Animation* animation = FindAnimation(name);

	Animator::Events* events
		= FindEvents(animation->GetAnimationName());

	return events->mStartEvent.mEvent;
}

std::function<void()>& Animator::GetCompleteEvent(const std::wstring& name)
{

	Animation* animation = FindAnimation(name);

	Animator::Events* events
		= FindEvents(animation->GetAnimationName());

	return events->mCompleteEvent.mEvent;
}

std::function<void()>& Animator::GetEndEvent(const std::wstring& name)
{
	Animation* animation = FindAnimation(name);

	Animator::Events* events
		= FindEvents(animation->GetAnimationName());

	return events->mEndEvent.mEvent;
}
