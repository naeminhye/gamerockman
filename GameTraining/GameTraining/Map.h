#pragma once
#include "TileMap.h"
#include"BaseObject.h"
#include"QuadTree.h"
#include"Sprite.h"
#include "Stage.h"
#include"List.h"
#include"OuterSpace.h"
class Map :
	public TileMap
{
public:
	QuadTree* quadtree;
	BaseObject** objects;
	int nObject;
	List<Stage*> stages;
	//List<OuterSpace*> spaces;
	void init(char* tileSheetPath, char* matrixPath,char* objectsPath,char* quadTreePath);
	void initStage(char* stagePath);

#pragma region STAGES

	bool onStageChangeNext; // ==true thi cho moi thu dung yen
	bool onStageChangePrev;
	
	static bool onStageChangeByDoor; // Dung vo Door tu ben trai thi ...

	void updateStageChangeNext();
	void updateStageChangePrev();

	void updateStageChangeByDoor();

	virtual Stage* findNextStageOnDoor();

#pragma endregion

	void readObjects(char* objectsPath);
	void update();
	void render();
	Map();
	~Map();
};

