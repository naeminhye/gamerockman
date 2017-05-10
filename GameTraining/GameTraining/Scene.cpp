#include "Scene.h"

Scene* Scene::curScene = 0;

void Scene::changeScene(Scene * scene)
{
	if (curScene != 0)
		delete curScene;
	curScene = scene;
	curScene->init();
}

void Scene::init()
{
}

void Scene::update()
{
}

void Scene::render()
{
}

Scene::Scene()
{
}


Scene::~Scene()
{
}
