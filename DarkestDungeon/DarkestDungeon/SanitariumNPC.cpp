#include "SanitariumNPC.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

SanitariumNPC::SanitariumNPC()
{
}

SanitariumNPC::~SanitariumNPC()
{
}

void SanitariumNPC::Initialize()
{
	//D:\WinAPIProject\DarkestDungeon\Resources\Town\sanitarium
	mImage = Resources::Load<Image>(L"SanitariumNPC", L"..\\Resources\\Town\\sanitarium\\sanitarium_character.bmp");
	GameObject::Initialize();
}

void SanitariumNPC::Update()
{
	GameObject::Update();
}

void SanitariumNPC::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	TransparentBlt(hdc, pos.x + 100, pos.y + 220, 600, 600
		, mImage->GetHdc(), 0, 0, 811, 757, RGB(255, 0, 255));
}

void SanitariumNPC::Release()
{
	GameObject::Release();
}
