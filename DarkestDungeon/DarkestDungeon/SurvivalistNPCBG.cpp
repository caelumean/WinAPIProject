#include "SurvivalistNPCBG.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"


SurvivalistNPCBG::SurvivalistNPCBG()
{
}

SurvivalistNPCBG::~SurvivalistNPCBG()
{
}

void SurvivalistNPCBG::Initialize()
{
	//D:\WinAPIProject\DarkestDungeon\Resources\Town\survivalist
	mImage = Resources::Load<Image>(L"SurvivalistNPCBG", L"..\\Resources\\Town\\survivalist\\survivalist_character_bg.bmp");
	GameObject::Initialize();
}

void SurvivalistNPCBG::Update()
{
	GameObject::Update();
}

void SurvivalistNPCBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 100, pos.y + 120, 1200, 650
		, mImage->GetHdc(), 0, 0, 1395, 776, RGB(255, 0, 255));
}

void SurvivalistNPCBG::Release()
{
	GameObject::Release();
}
