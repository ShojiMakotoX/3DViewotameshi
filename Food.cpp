#include "Food.h"
#include "Engine\\Model.h"

Food::Food()
	:GameObject(nullptr,"Food"),type_(FOODTYPE_NORMAL),hModel_(-1),score_(0)
{
}

Food::~Food()
{
}

void Food::Initialize()
{
	if (type_ = FoodType::FOODTYPE_NORMAL)
	{
		hModel_ = Model::Load("item.fbx");
	}
	else if (type_ = FoodType::FOODTYPE_POWER)
	{
		hModel_ = Model::Load("bigitem.fbx");
	}
}

void Food::Update()
{
}

void Food::Draw()
{
}

void Food::Release()
{
}

void Food::OnCollision(GameObject* pTarget)
{
}
