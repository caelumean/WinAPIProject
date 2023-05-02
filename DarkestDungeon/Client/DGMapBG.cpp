#include "DGMapBG.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"


DGMapBG::DGMapBG()
{
}

DGMapBG::~DGMapBG()
{
}

void DGMapBG::Initialize()
{
	mImage = Resources::Load<Image>(L"DGMap", L"..\\Resources\\Dugeon\\InfoUI\\Map.bmp");
	//D:\WinAPIProject\DarkestDungeon\Resources\Dugeon\map_icons
	MapIcons[0] = Resources::Load<Image>(L"Room_Entrance", L"..\\Resources\\Dugeon\\map_icons\\room_entrance.bmp");
	MapIcons[1] = Resources::Load<Image>(L"Hall_1", L"..\\Resources\\Dugeon\\map_icons\\hall_clear.bmp");
	MapIcons[2] = Resources::Load<Image>(L"Hall_2", L"..\\Resources\\Dugeon\\map_icons\\hall_clear.bmp");
	MapIcons[3] = Resources::Load<Image>(L"Hall_3", L"..\\Resources\\Dugeon\\map_icons\\hall_clear.bmp");
	MapIcons[4] = Resources::Load<Image>(L"Hall_4", L"..\\Resources\\Dugeon\\map_icons\\hall_clear.bmp");
	MapIcons[5] = Resources::Load<Image>(L"Hall_5", L"..\\Resources\\Dugeon\\map_icons\\hall_clear.bmp");
	MapIcons[6] = Resources::Load<Image>(L"Room_Battle", L"..\\Resources\\Dugeon\\map_icons\\room_battle.bmp");

	GameObject::Initialize();
}

void DGMapBG::Update()
{
	GameObject::Update();
}

void DGMapBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	//MapBG
	TransparentBlt(hdc, pos.x + 800, pos.y + 650, 600, 250
		, mImage->GetHdc(), 0, 0, 720, 360, RGB(255, 0, 255));

	//Map
	TransparentBlt(hdc, pos.x + 915, pos.y + 749, 45, 40
		, MapIcons[0]->GetHdc(), 0, 0, 64, 64, RGB(255, 0, 255));

	TransparentBlt(hdc, pos.x + 960, pos.y + 757, 20, 20
		, MapIcons[1]->GetHdc(), 0, 0, 24, 24, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 980, pos.y + 757, 20, 20
		, MapIcons[2]->GetHdc(), 0, 0, 24, 24, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 1000, pos.y + 757, 20, 20
		, MapIcons[3]->GetHdc(), 0, 0, 24, 24, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 1020, pos.y + 757, 20, 20
		, MapIcons[4]->GetHdc(), 0, 0, 24, 24, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 1040, pos.y + 757, 20, 20
		, MapIcons[5]->GetHdc(), 0, 0, 24, 24, RGB(255, 0, 255));

	TransparentBlt(hdc, pos.x + 1060, pos.y + 749, 45, 40
		, MapIcons[6]->GetHdc(), 0, 0, 64, 64, RGB(255, 0, 255));

	

}

void DGMapBG::Release()
{
	GameObject::Release();
}
