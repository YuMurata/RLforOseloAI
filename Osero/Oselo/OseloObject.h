#pragma once

#include"stdafx.h"

#include"ObjectIF.h"
#include"RateClass.h"
#include"BoardInfo.h"
#include"Object.h"
#include"CellMGR.h"

#include<vector>

class OseloObject:public ObjectIF,RateClass,BoardInfo
{
private:
	Object board;
	CellMGR cells;
	std::vector<int> win;

	CellCoord Mouse2Cell(const MouseCoord &coord);

public:
	OseloObject(const CellNum &cell_num, const int &current_turn);
	
	~OseloObject();

	void Put(const int &color);

	virtual void Init();

	virtual void Draw();

	virtual void UpDate(const Input &input);
};