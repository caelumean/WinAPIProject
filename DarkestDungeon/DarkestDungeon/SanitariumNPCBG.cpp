#include "SanitariumNPCBG.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

SanitariumNPCBG::SanitariumNPCBG()
{
}

SanitariumNPCBG::~SanitariumNPCBG()
{
}

void SanitariumNPCBG::Initialize()
{
	//D:\WinAPIProject\DarkestDungeon\Resources\Town\sanitarium
	mImage = Resources::Load<Image>(L"SanitariumNPCBG", L"..\\Resources\\Town\\sanitarium\\sanitarium_character_bg.bmp");
	GameObject::Initialize();
}

void SanitariumNPCBG::Update()
{
	GameObject::Update();
}

void SanitariumNPCBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 100, pos.y + 120, 1200, 650
		, mImage->GetHdc(), 0, 0, 1395, 776, RGB(255, 0, 255));
}

void SanitariumNPCBG::Release()
{
	GameObject::Release();
}
