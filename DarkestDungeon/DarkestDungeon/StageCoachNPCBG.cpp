#include "StageCoachNPCBG.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

StageCoachNPCBG::StageCoachNPCBG()
{
}

StageCoachNPCBG::~StageCoachNPCBG()
{
}

void StageCoachNPCBG::Initialize()
{
	//D:\WinAPIProject\DarkestDungeon\Resources\Town\stagecoach
	mImage = Resources::Load<Image>(L"StageCoachNPCBG", L"..\\Resources\\Town\\stagecoach\\stagecoach_character_bg.bmp");
	GameObject::Initialize();
}

void StageCoachNPCBG::Update()
{
	GameObject::Update();
}

void StageCoachNPCBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 100, pos.y + 120, 1200, 650
		, mImage->GetHdc(), 0, 0, 1395, 776, RGB(255, 0, 255));
}

void StageCoachNPCBG::Release()
{
	GameObject::Release();
}
