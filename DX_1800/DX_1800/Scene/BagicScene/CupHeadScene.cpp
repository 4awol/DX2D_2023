#include "framework.h"
#include "CupHeadScene.h"
#include "../../Object/Obj/CupHead/CupHead.h"
#include "../../Object/Obj/CupHead/CupBG.h"
#include "../../Object/Obj/CupHead/CupMonster.h"
#include "../../Object/Obj/CupHead/Cup_Bullet.h"

CupHeadScene::CupHeadScene()
{
	_player = make_shared<CupHead>();

	_bg = make_shared<CupBG>();
	_bg->SetPosition(Vector2(CENTER.x, 100.0f));

	_monster = make_shared<CupMonster>();
}

CupHeadScene::~CupHeadScene()
{
}

void CupHeadScene::Update()
{
	_player->Update();

	_monster->Update();

	_bg->Update();

	if(_bg->GetCollider()->Block(_player->GetCollider()))
		_player->Grounded();
	else
		_player->SetIsFalling(true);

}

void CupHeadScene::Render()
{
	_monster->Render();

	_bg->Render();
	_player->Render();
}

void CupHeadScene::PostRender()
{
	_player->PostRender();
}
