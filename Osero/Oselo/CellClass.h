#pragma once

#include"stdafx.h"

#include"Object.h"
#include"RateClass.h"
#include"BoardInfo.h"

typedef TCoordinate<int> CellCoord;

class CellClass :public Object,BoardInfo
{
private:
	CellCoord cell_coord;
	ObjCoord board_coord;

public:
	CellClass();

	~CellClass();

	void Init(const CellCoord &coord, const int &handle, const Rate &rate);

	void AssociateBoard();

	virtual void UpDate();

	void Set(const int &x, const int &y);
};