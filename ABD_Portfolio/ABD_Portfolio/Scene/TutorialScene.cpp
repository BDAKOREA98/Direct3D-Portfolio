#include "Framework.h"
#include "TutorialScene.h"

TutorialScene::TutorialScene()
{    
    cube1 = new Cube({ 1.0f, 0.0f, 0.0f, 1.0f });
    cube2 = new Cube({ 0.0f, 1.0f, 0.0f, 1.0f });

    //cube2->translation.x = 3;
    //cube2->rotation.x = 3;
    //cube2->scale.x = 3;

    //;cube2->SetParent(cube1);
}

TutorialScene::~TutorialScene()
{
    delete cube1;
    delete cube2;
}

void TutorialScene::Update()
{
    cube1->Update();
    cube2->Update();

    //cube1->rotation.y += 0.0001f;


    if (KEY_PRESS(VK_LEFT))
        cube1->translation += cube1->Left() * Time::Delta();

    if (KEY_PRESS(VK_RIGHT))
        cube1->translation += cube1->Right() * Time::Delta();

    if (KEY_PRESS(VK_UP))
        cube1->translation += cube1->Up() * Time::Delta();

    if (KEY_PRESS(VK_DOWN))
        cube1->translation += cube1->Down() * Time::Delta();

    if (KEY_PRESS('Q'))
        cube1->rotation.z += Time::Delta();

    if (KEY_PRESS('E'))
        cube1->rotation.z -= Time::Delta();
}

void TutorialScene::PreRender()
{
}

void TutorialScene::Render()
{
    cube1->Render();
    cube2->Render();
}

void TutorialScene::PostRender()
{
    cube1->Debug();
    cube2->Debug();
}
