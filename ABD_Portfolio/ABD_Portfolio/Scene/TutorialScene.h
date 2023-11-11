#pragma once


class TutorialScene : public Scene
{
public:
	TutorialScene();
	~TutorialScene();

	virtual void Update() override;

	virtual void PreRender() override;
	virtual void Render() override;
	virtual void PostRender() override;

private: 
	Cube* cube1;
	Cube* cube2;
};
