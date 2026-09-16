#include "Title.h"
#include "Engine\\Input.h"
#include "Engine\\SceneManager.h"



Title::Title(GameObject* parent)
	:GameObject(parent,"Title")
{
}

void Title::Initialize()
{
}

void Title::Update()
{
	if (Input::IsKey(DIK_SPACE))
	{

	}
}

void Title::Draw()
{
	
}

void Title::Release()
{
}
