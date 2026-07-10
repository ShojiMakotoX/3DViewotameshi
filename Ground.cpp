#include "Ground.h"
#include "Engine\\Model.h"
namespace
{
	using std::vector;
	int model_t = -1;

	vector<vector<int>>mapData
	{
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1},
	};

}
Ground::Ground(GameObject* parent)
	:GameObject(parent),hModel_(-1)
{
	mapData_ = mapData;//ファイルグローバルのmapDataをコピーしてメンバ変数Mapdata_へ
}

void Ground::Initialize()
{
	hModel_ = Model::Load("masu2.fbx");//1025だとうまく読み込めない可能性あり

	model_t = Model::Load("Block.fbx");
	
}

void Ground::Update()
{
}

void Ground::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);

	for (int j = 0;j < 10;j++)
	{
		for (int i = 0;i < 10;i++)
		{
			if (mapData_[j][i] == 1)
			{
				Transform tr;
				tr.position_ = { -9.0f + i * 2.0f ,0.0f,9.0f - j * 2.0f };
				Model::SetTransform(model_t, tr);
				Model::Draw(model_t);
			}
			
		}
	}
}

void Ground::Release()
{
}
