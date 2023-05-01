#include "RuinsPassageBG.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"

RuinsPassageBG::RuinsPassageBG()
{
}

RuinsPassageBG::~RuinsPassageBG()
{
}

void RuinsPassageBG::Initialize()
{
	mImage = Resources::Load<Image>(L"RuinsePassageBG", L"..\\Resources\\Dugeon\\Ruins\\Ruins_Passage_2.bmp");
	GameObject::Initialize();
}

void RuinsPassageBG::Update()
{
	GameObject::Update();
}

void RuinsPassageBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x - 1, pos.y - 1, 2800, 650
		, mImage->GetHdc(), 0, 0, 2800, 455, RGB(255, 0, 255));
}

void RuinsPassageBG::Release()
{
	GameObject::Release();
}
