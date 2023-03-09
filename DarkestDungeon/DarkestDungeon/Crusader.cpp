#include "Crusader.h"
#include "Time.h"
#include "SceneManager.h"
#include "Input.h"
#include "yaResources.h"
#include "Transform.h"

Crusader::Crusader()
{
}

Crusader::~Crusader()
{
}

void Crusader::Initialize()
{
	mImage = Resources::Load<Image>(L"Heroes", L"..\\Resources\\Heroes\\crusader\\crusader_defend.bmp");
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

	if (Input::GetKeyState(eKeyCode::W) == eKeyState::Pressed)
	{
		pos.y -= 100.0f * Time::DeltaTime();
	}

	if (Input::GetKeyState(eKeyCode::S) == eKeyState::Pressed)
	{
		pos.y += 100.0f * Time::DeltaTime();
	}
	tr->SetPos(pos);
}


void Crusader::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	// 50 200
	BitBlt(hdc, pos.x + 50, pos.y + 200, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
}

void Crusader::Release()
{
	GameObject::Release();
}
