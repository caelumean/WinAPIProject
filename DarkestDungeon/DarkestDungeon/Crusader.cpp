#include "Crusader.h"
#include "Time.h"
#include "SceneManager.h"
#include "Input.h"
#include "yaResources.h"
#include "Transform.h"

Crusader::Crusader()
	:mTime(0.0f)
	,mIdx(0)
{
}

Crusader::~Crusader()
{
}

void Crusader::Initialize()
{
	mImage = Resources::Load<Image>(L"Crusader", L"..\\Resources\\Heroes\\crusader\\crusader_Idle.bmp");
	GameObject::Initialize();
}

void Crusader::Update()
{
	GameObject::Update();

	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	if (Input::GetKeyState(eKeyCode::A) == eKeyState::Pressed)
	{
		pos.x -= 100.0f * Time::DeltaTime();
	}

	if (Input::GetKeyState(eKeyCode::D) == eKeyState::Pressed)
	{
		pos.x += 100.0f * Time::DeltaTime();
	}

	tr->SetPos(pos);
}


void Crusader::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	mTime += Time::DeltaTime();

	if (mIdx >= 12)
	{
		mIdx = 0;
	}

	if (mTime > 0.1f)
	{
		mIdx++;
		mTime = 0.0f;
	}

	TransparentBlt(hdc, pos.x, pos.y+380, 250, 300
		, mImage->GetHdc(), (400 * mIdx), 0, 400, 590, RGB(255, 0, 255));

}

void Crusader::Release()
{
	GameObject::Release();
}
