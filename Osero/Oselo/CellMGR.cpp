#include"stdafx.h"

#include"CellMGR.h"

using namespace std;

CellMGR::CellMGR(const CellNum &cell_num, const int &current_turn)
	:oselo_obj(cell_num, current_turn), cell_num(cell_num), init_turn(current_turn)
{
	const string pass = "figure\\";

	this->handle[BoardClass::Cell_BLACK] = LoadGraph((pass + "black.png").data());
	this->handle[BoardClass::Cell_WHITE] = LoadGraph((pass + "white.png").data());
}

CellMGR::~CellMGR() {}

void CellMGR::Init()
{

	auto init = this->oselo_obj.Init();

	CellClass obj;
	obj.Init(CellCoord(0, 0), -1, this->rate);

	this->cells.clear();
	this->cells.resize(this->cell_num.y);

	for (auto &i : this->cells)
	{
		i.resize(this->cell_num.x);
	}

	for (auto &i : this->cells)
	{
		for (auto &j : i)
		{
			j.reset(new CellClass(obj));
		}
	}

	this->fake.reset(new CellClass(obj));

	auto func = [&](const CellCoord &coord, const int &color)
	{
		this->PutPieceAt(coord, color);
	};

	init.first.Addopt(func);
	init.second.Addopt(func);
}

void CellMGR::Draw()
{
	this->fake->Draw();

	for (auto &i : this->cells)
	{
		for (auto &j : i)
		{
			j->Draw();
		}
	}
}

void CellMGR::UpDate()
{
	this->fake->UpDate();
	for (auto &i : this->cells)
	{
		for (auto &j : i)
		{
			j->UpDate();
		}
	}
}