#include "CrusaderDefend.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"

CrusaderDefend::CrusaderDefend()
{
}

CrusaderDefend::~CrusaderDefend()
{
}

void CrusaderDefend::Initialize()
{
	//D:\WinAPIProject\DarkestDungeon\Resources\Heroes\crusader
	mImage = Resources::Load<Image>(L"CrusaderDefend", L"..\\Resources\\Heroes\\crusader\\crusader_defend.bmp");
}

void CrusaderDefend::Update()
{
	GameObject::Update();
}

void CrusaderDefend::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 620, pos.y + 200, 400, 400
		, mImage->GetHdc(), 0, 0, 341, 650, RGB(255, 0, 255));
}

void CrusaderDefend::Release()
{
	GameObject::Release();
}
