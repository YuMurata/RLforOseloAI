#include"stdafx.h"

#include"CellMGR.h"

void CellMGR::PutPieceAt(const CellCoord &coord, const int &color)
{
	PutState put_state(color);
	put_state.Add(this->oselo_obj.PutPieceAt(coord, color));

	auto func = [&](const CellCoord &coord, const int &color)
	{
		auto &obj = this->cells[coord.y][coord.x];

		obj->Init(coord, this->handle[color], this->rate);
	};

	put_state.Addopt(func);

}

void CellMGR::PutFake(const CellCoord &coord)
{
	auto color = this->oselo_obj.GetCurrent();
	PutState dummy(color);
	auto cell_handle = -1;


	if (this->oselo_obj.CheckInside(coord) && this->oselo_obj.CheckPut(coord, color, &dummy))
	{
		cell_handle = this->handle[color];
	}

	this->fake->Init(coord, cell_handle, this->rate);
}

int CellMGR::PutReal(const CellCoord &coord)
{
	auto color = this->oselo_obj.GetCurrent();
	auto put_state = this->oselo_obj.Put(coord, color);

	auto func = [&](const CellCoord &coord, const int &color)
	{
		auto &obj = this->cells[coord.y][coord.x];

		obj->Init(coord, this->handle[color], this->rate);
	};

	put_state.Addopt(func);

	if (!put_state.Empty())
	{
		this->oselo_obj.ChangeTurn();

		if (!this->oselo_obj.CheckPutable(this->oselo_obj.GetCurrent()))
		{
			this->oselo_obj.ChangeTurn();
		}

		if (this->oselo_obj.CheckFinish())
		{
			return this->oselo_obj.Win();
		}
	}

	return BoardClass::Cell_Empty;
}
