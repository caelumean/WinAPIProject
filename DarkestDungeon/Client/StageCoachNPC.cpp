#include "StageCoachNPC.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"

StageCoachNPC::StageCoachNPC()
{
}

StageCoachNPC::~StageCoachNPC()
{
}

void StageCoachNPC::Initialize()
{
	mImage = Resources::Load<Image>(L"StageCoachNPC", L"..\\Resources\\Town\\stagecoach\\stagecoach_character.bmp");
	GameObject::Initialize();
}

void StageCoachNPC::Update()
{
	GameObject::Update();
}

void StageCoachNPC::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 100, pos.y + 220, 600, 600
		, mImage->GetHdc(), 0, 0, 811, 757, RGB(255, 0, 255));
}

void StageCoachNPC::Release()
{
	GameObject::Release();
}
