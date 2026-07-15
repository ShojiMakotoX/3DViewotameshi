#include "Ground.h"
#include "Engine\\Model.h"
#include "Engine\\CsvReader.h"
namespace
{
	using std::vector;
	

	/*vector<vector<int>>mapData
	{
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,1,0,1,0,0,0,0,1,1},
		{1,0,0,0,0,0,1,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,1,0,0,0,0,0,1,0,1},
		{1,1,1,1,1,1,1,1,1,1},
	};*/

}
Ground::Ground(GameObject* parent)
	:GameObject(parent,"Ground"), hModel_(-1),mapWidth_(-1),mapHeight_(-1)
{
	CsvReader csvData;
	csvData.Load("map.csv");//CsVファイル読み込み

	mapWidth_ = csvData.GetWidth();//列数を取得
	mapHeight_ = csvData.GetHeight();//行数を取得


	mapData_ = vector<vector<int>>(mapHeight_,vector<int>(mapWidth_,0));

	for (int x = 0;x < mapWidth_;x++)
	{
		for (int y = 0;y < mapHeight_;y++)
		{
			mapData_[y][x] = csvData.GetValue(x, y);
		}
	}

	for (int x = 0;x < mapWidth_;x++)
	{
		for (int y = 0;y < mapHeight_;y++)
		{
			objMap_[y+mapHeight_-1][x] = csvData.GetValue(x, y+mapHeight_-1);
		}
	}
}

void Ground::Initialize()
{
	hModel_ = Model::Load("masu2.fbx");//1025だとうまく読み込めない可能性あり

	hModelt_ = Model::Load("Block.fbx");
	hModeli_ = Model::Load("item.fbx");
	
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
			if (objMap_[j][i] == 1||objMap_[j][i]==2)
			{
				Transform tr;
				tr.position_ = { -9.0f + i * 2.0f ,0.0f,9.0f - j * 2.0f };
				Model::SetTransform(hModelt_, tr);
				Model::Draw(hModelt_);
			}
			
		}
	}
}

void Ground::Release()
{
}
