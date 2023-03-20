#include "BlacksmithNPC.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

BlacksmithNPC::BlacksmithNPC()
{
}

BlacksmithNPC::~BlacksmithNPC()
{
}

void BlacksmithNPC::Initialize()
{
	//D:\WinAPIProject\DarkestDungeon\Resources\Town\abbey
	mImage = Resources::Load<Image>(L"BlacksmithNPC", L"..\\Resources\\Town\\blacksmith\\blacksmith_character.bmp");
	GameObject::Initialize();
}

void BlacksmithNPC::Update()
{
	GameObject::Update();
}

void BlacksmithNPC::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	TransparentBlt(hdc, pos.x + 100, pos.y + 220, 600, 600
		, mImage->GetHdc(), 0, 0, 865, 760, RGB(255, 0, 255));
}

void BlacksmithNPC::Release()
{
	GameObject::Release();
}
