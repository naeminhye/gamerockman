#pragma once
#include "MGMTexture.h"
#include "Camera.h"
#include <fstream>
using namespace std;

class TileMap
{
public:
	int rowCount, colCount, colTileSheetCount;
	MGMTexture* tileSheet;
	int** matrix;

	void init(char* tileSheetPath, char* matrixPath);
	void renderTile(int rowIndex, int colIndex);
	void renderTiles(int rowBegin, int rowEnd, int colBegin, int colEnd);
	virtual void render();

	/* CONSTRUCTOR & DESTRUCTOR */	
	TileMap();
	~TileMap();

};

