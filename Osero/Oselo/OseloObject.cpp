#include"stdafx.h"

#include"OseloObject.h"

typedef TCoordinate<int> ScreenSize;

CellCoord OseloObject::Mouse2Cell(const MouseCoord &coord)
{
	auto cell = (coord - this->rate*this->board_offset) / (this->board_cell_size*(Rate)this->rate);

	return cell;
}


OseloObject::OseloObject(const CellNum &cell_num, const int &current_turn)
		:cells(cell_num, current_turn)
	{}

OseloObject::~OseloObject() {}

	void OseloObject::Put(const int &color)
	{
		this->cells.PutPieceAt(ObjCoord(0, 0), color);
	}

	void OseloObject::Init()
	{
		const string pass = "figure\\";
		ObjCoord coord(0, 0);

		this->board.Init(coord, pass + "board.png");

		ScreenSize ss;
		int dummy;

		GetScreenState(&ss.x, &ss.y, &dummy);

		SetRate(((Rate)ss / (Rate)this->board.GetGraphSize()));

		this->board.SetRate(this->rate);
		this->cells.SetRate(this->rate);

		this->cells.Init();
	}

	void OseloObject::Draw()
	{
		this->board.Draw();
		this->cells.Draw();
	}

	void OseloObject::UpDate(const Input &input)
	{
		auto coord = Mouse2Cell(input.GetMouseCoord());

		if (input.GetMouseInPut(MOUSE_INPUT_LEFT))
		{
			auto win = this->cells.PutReal(coord);
			if (win != BoardClass::Cell_Empty)
			{
				this->win.push_back(win);
				this->cells.Init();
			}
		}
		else
		{
			this->cells.PutFake(coord);
		}
		this->cells.UpDate();
	}