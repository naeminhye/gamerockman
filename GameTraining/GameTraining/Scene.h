#pragma once
class Scene
{
public:
	static Scene* curScene;

	static void changeScene(Scene* scene);
	virtual void init();
	virtual void update();
	virtual void render();

	/* CONSTRUCTOR & DESTRUCTOR */
	Scene();
	~Scene();

};

