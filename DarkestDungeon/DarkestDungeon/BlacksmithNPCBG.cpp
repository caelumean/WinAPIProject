#include "BlacksmithNPCBG.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

BlacksmithNPCBG::BlacksmithNPCBG()
{
}

BlacksmithNPCBG::~BlacksmithNPCBG()
{
}

void BlacksmithNPCBG::Initialize()
{
	//D:\WinAPIProject\DarkestDungeon\Resources\Town\blacksmith
	mImage = Resources::Load<Image>(L"BlacksmithNPCBG", L"..\\Resources\\Town\\blacksmith\\blacksmith_character_bg.bmp");
	GameObject::Initialize();
}

void BlacksmithNPCBG::Update()
{
	GameObject::Update();
}

void BlacksmithNPCBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 100, pos.y + 120, 1200, 650
		, mImage->GetHdc(), 0, 0, 1395, 776, RGB(255, 0, 255));
}

void BlacksmithNPCBG::Release()
{
	GameObject::Release();
}
