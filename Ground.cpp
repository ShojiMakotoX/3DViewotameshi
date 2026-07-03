#include "Ground.h"
#include "Engine\\Model.h"

Ground::Ground(GameObject* parent)
	:GameObject(parent),ground(-1)
{
}

void Ground::Initialize()
{
	ground = Model::Load("masu.fbx");//1025だとうまく読み込めない可能性あり

}

void Ground::Update()
{
}

void Ground::Draw()
{
	Model::SetTransform(ground, transform_);
	Model::Draw(ground);
}

void Ground::Release()
{
}
