#pragma once

/*
������(Stage Coach)
���尣(Blacksmith)
���(Guild)
���� ������(Survivalist)
����(Tavern)
������(Abbey)
����(Sanitarium)
����� ����(Nomad Wagon)
����(Graveyard)
������ ���(Ancestor's Memoirs)
����(Provision)
���� ����(SelectDugeon)
*/
enum class eSceneType
{
	Title,
	Town,
	StageCoach,
	Blacksmith,
	Guild,
	Survivalist,
	Tavern,
	Abbey,
	Sanitarium,
	NomadWagon,
	Graveyard,
	Memoirs,
	SelectDugeon,
	Provision,
	RuinsEntrance,
	RuinsPassage,
	RuinsBattle,
	Ending,
	End
};


enum class eLayerType
{
	BackGround,
	Sky,
	Shadow,
	Building,
	NPC,
	Monster,
	Player,
	Effect,
	Item,
	UI1,
	UI2,
	DungeonObj,
	Text,
	End=16,
};

enum class eComponentType
{
	Transform,
	SpriteRenderer,
	Animator,
	Collider,
	Audio,
	End,
};