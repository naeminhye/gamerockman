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
	static Map* curMap; // dia chi cua Map hien tai
	QuadTree* quadtree;
	BaseObject** objects;
	int nObject;
	List<Stage*> stages;
	int stageBegin;

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

	void readObjects(char* objectsPath); // doc loai, vi tri va so luong cua doi tuong tu file de ve len tren Map
	virtual void update();
	virtual void render();
	
	/* CONSTRUCTOR & DESTRUCTOR */
	Map();
	~Map();


	int cameraBeginX, cameraBeginY;
	int rmBeginX, rmBeginY;
};

