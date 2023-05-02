#pragma once

/*
역마차(Stage Coach)
대장간(Blacksmith)
길드(Guild)
생존 전문가(Survivalist)
여관(Tavern)
수도원(Abbey)
요양원(Sanitarium)
유목민 마차(Nomad Wagon)
무덤(Graveyard)
선조의 기억(Ancestor's Memoirs)
공급(Provision)
던전 선택(SelectDugeon)
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