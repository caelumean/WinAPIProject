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

		// loop가 참이고 IsComplete가 참이라면
		// 다시 리셋 시켜야된다.
		// 싹 돌다가 끝에 도착했다는 뜻
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
	// 가로 , 높이 ,파일의 갯수
	UINT width = 0;
	UINT height = 0;
	UINT fileCount = 0;

	std::filesystem::path fs(path);
	std::vector<Image*> images = {};

	// 내 현재 경로에 파일들을 순회할 수 있는 경로.
	for (const auto& p : std::filesystem::recursive_directory_iterator(path))
	{
		std::wstring fileName = p.path().filename();
		std::wstring fullName = path + L"\\" + fileName;

		// 파일 경로에서 .png제외
		const std::wstring ext = p.path().extension();
		if (ext == L".png")
			continue;
		// fileName이 key이고 fullName이 경로
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
	// parent_path : 부모 경로
	// filename : 파일 이름
	std::wstring key = fs.parent_path().filename();
	key += fs.filename();
	mSpriteSheet = Image::Create(key, width * fileCount, height);

	// 이미지 갯수만큼 반복문을 돌린다.
	int index = 0;
	for (Image* image : images)
	{
		// 절반만큼만 가면 되니까 
		// (넓이 - 이미지 넓이)/2 하면 된다.
		// 높이또한 마찬가지이다.
		// 높이는 위 아래로 뺀 값을 더해주면 중간에 온다.
		int centerX = (width - image->GetWidth()) / 2;
		int centerY = (height - image->GetHeight());


		// 이미지를 복사해주는 것
		// int x1 int y1은 좌표이다
		BitBlt(mSpriteSheet->GetHdc()
			, width * index + centerX
			, 0 + centerY
			, image->GetWidth(), image->GetHeight()
			, image->GetHdc(), 0, 0, SRCCOPY);
		index++;
	}


	// 이제 다시 CreateAnimation을 호출하면 된다.
	// file name이 key로 들어가 있고 sheet는 mSpriteSheet 
	// leftTop은 0,0이기 때문에 Vector2::Zero
	// 이미지 갯수는 index++하면 됨
	// row는 우선 1로
	// 실제 이미지 사용될 갯수 index
	// offset : 두 변수 또는 데이터 구조의 메모리 주소 사이의 거리
	//			다음 이미지와의 거리?
	// duration : 단위로 측정된 시간의 길이.
	CreateAnimation(key, mSpriteSheet, Vector2::Zero, index, 1, index, offset, duration);
}

Animation* Animator::FindAnimation(const std::wstring& name)
{
	std::map<std::wstring, Animation*>::iterator iter
		= mAnimations.find(name);

	// map안에 없는 것
	if (iter == mAnimations.end())
		return nullptr;
	// 아니라면 iterator의 second
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
