#include "MemoirsNPCBG.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"

MemoirsNPCBG::MemoirsNPCBG()
{
}

MemoirsNPCBG::~MemoirsNPCBG()
{
}

void MemoirsNPCBG::Initialize()
{
	mImage = Resources::Load<Image>(L"MemoirsNPCBG", L"..\\Resources\\Town\\memoirs\\memoirs_character_bg.bmp");
	GameObject::Initialize();
}

void MemoirsNPCBG::Update()
{
	GameObject::Update();
}

void MemoirsNPCBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 100, pos.y + 120, 1200, 650
		, mImage->GetHdc(), 0, 0, 1395, 776, RGB(255, 0, 255));
}

void MemoirsNPCBG::Release()
{
	GameObject::Release();
}
