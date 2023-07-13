#pragma once
class MainScene : public Scene
{
public:
	MainScene();
	~MainScene();

	virtual void Update() override;
	virtual void Render() override;
	void PostRender();

	int _main_OnAir = 1;

private:
	shared_ptr<RectCollider> _col;
	shared_ptr<Transform> _trans;

	
};

