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
	Play,
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
	Enemy,
	Player,
	Effect,
	Item,
	UI,
	Text,
	End,
};

enum class eComponentType
{
	Transform,
	Collider,
	SpriteRenderer,
	Animator,
	Audio,
	End,
};


enum class eJob
{
	Crusader,
	Vestal,
	PlagueDoctor,
	Highwayman
};