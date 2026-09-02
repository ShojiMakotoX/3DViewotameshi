#include "TestScene.h"
#include "Player.h"
#include "Ground.h"
#include "Engine\\Camera.h"
#include "Engine\\Text.h"
#include "Food.h"
#include "Enemy.h"

namespace
{
	int myScore = 0;
	int myEsa;

	Ground* pGround;
	const int CAMERA_HEIGHT = 8.0f;
	XMFLOAT3 START_POS = { 15.0f,0.75f,0.5f };
	const float END_POS_X = 43.0f;
}

//コンストラクタ
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
{
}

//初期化
void TestScene::Initialize()
{	
	//pWp = Instantiate<Weapon>(this);
	pPlayer_ = Instantiate <Player>(this);
	pGround = Instantiate<Ground>(this);
	//Enemy* eEnemy = Instantiate<Enemy>(this);
	pPlayer_->SetGround(pGround);
	//eEnemy->SetGround(pGround);
	//myEsa = pGround->GetEsaCount();

	Camera::SetPosition({pPlayer_->GetPosition().x,pPlayer_->GetPosition().y+CAMERA_HEIGHT,-22});
	Camera::SetTarget({ pPlayer_->GetPosition().x,pPlayer_->GetPosition().y + CAMERA_HEIGHT,0 });

	pText_ = new Text;
	pText_ -> Initialize();

}

//更新
void TestScene::Update()
{
	if (pPlayer_->GetPosition().x > START_POS.x && pPlayer_->GetPosition().x < END_POS_X)
	{
		Camera::SetPosition({ pPlayer_->GetPosition().x,pPlayer_->GetPosition().y + CAMERA_HEIGHT,-22 });
		Camera::SetTarget({ pPlayer_->GetPosition().x,pPlayer_->GetPosition().y + CAMERA_HEIGHT,0 });

	}
}

//描画
void TestScene::Draw()
{
	std::string scrText;
	std::string scrText2;
	scrText = "SCORE:" + std::to_string(myScore);
	scrText2 = "ESA:" + std::to_string(myEsa);
	pText_->Draw(20, 20, scrText.c_str());
	pText_->Draw(1000, 20, scrText2.c_str());
}
//開放
void TestScene::Release()
{
	pText_->Release();//テキスト開放
}

void TestScene::AddScore(int score)
{
	myScore += score;
}

void TestScene::DeleteEsa(int esa)
{
	myEsa -= esa;
	printf("myEsa = %d\n", myEsa);
}

