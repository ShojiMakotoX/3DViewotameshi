#include "Ground.h"
#include "Engine\\Model.h"

namespace
{
	int model_t = -1;
}
Ground::Ground(GameObject* parent)
	:GameObject(parent),ground(-1)
{
}

void Ground::Initialize()
{
	ground = Model::Load("masu.fbx");//1025だとうまく読み込めない可能性あり

	model_t = Model::Load("Block.fbx");

}

void Ground::Update()
{
}

void Ground::Draw()
{
	Model::SetTransform(ground, transform_);
	Model::Draw(ground);

	Model::SetTransform(model_t, transform_);
	Model::Draw(model_t);
}

void Ground::Release()
{
}
