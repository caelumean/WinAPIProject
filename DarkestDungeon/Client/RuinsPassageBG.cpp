#include "RuinsPassageBG.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"
#include "Camera.h"

RuinsPassageBG::RuinsPassageBG()
{
}

RuinsPassageBG::~RuinsPassageBG()
{
}

void RuinsPassageBG::Initialize()
{
	mImage = Resources::Load<Image>(L"RuinsPassageBG", L"..\\Resources\\Dugeon\\Ruins\\Ruins_Passage.bmp");
	tr = AddComponent<Transform>();
	GameObject::Initialize();
}

void RuinsPassageBG::Update()
{
	GameObject::Update();
	
}

void RuinsPassageBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	pos = Camera::CalculatePos(pos);
	pos.x -= mImage->GetWidth() / 28;
	pos.y -= mImage->GetHeight() / 400;

	BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
}

void RuinsPassageBG::Release()
{
	GameObject::Release();
}
