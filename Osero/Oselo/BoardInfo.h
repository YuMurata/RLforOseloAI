#pragma once
#include"stdafx.h"

#include<Coordinate.h>

typedef TCoordinate<int> Constant;

class BoardInfo
{
public:
	
	const Constant board_cell_size;
	const Constant board_offset;
	const Constant offset;
	const Rate d_rate;

	BoardInfo()
		:board_cell_size(Constant(33, 33)),
		board_offset(Constant(9, 8)),
		offset(Constant(3, 3)),
		d_rate(0.08, 0.05) {}

};
