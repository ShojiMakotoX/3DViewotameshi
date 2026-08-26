#include "Enemy.h"
#include "Ground.h"
#include "Player.h"
#include "Engine\\Model.h"

Enemy::Enemy(GameObject* parent)
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Enemy.fbx");
	Model::SetAnimFrame(hModel_, 0, 67, 1.0);
	transform_.position_ = { 3.0f,1.0f,5.0f };
}

void Enemy::Update()
{
	
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
}
