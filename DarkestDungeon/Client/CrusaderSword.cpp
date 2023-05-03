#include "CrusaderSword.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"

CrusaderSword::CrusaderSword()
{
}

CrusaderSword::~CrusaderSword()
{
}

void CrusaderSword::Initialize()
{
	mImage = Resources::Load<Image>(L"CrusaderSword", L"..\\Resources\\Heroes\\crusader\\crusader_sword.bmp");
}

void CrusaderSword::Update()
{
	GameObject::Update();
}

void CrusaderSword::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 620, pos.y + 200, 600, 400
		, mImage->GetHdc(), 0, 0, 619, 580, RGB(255, 0, 255));
}

void CrusaderSword::Release()
{
	GameObject::Release();
}
