#include"stdafx.h"

#include"CellClass.h"

CellClass::CellClass() {}

CellClass::~CellClass() {}

void CellClass::Init(const CellCoord &coord, const int &handle, const Rate &rate)
{
	this->cell_coord = coord;
	this->handle = handle;
	SetRate(rate);
	SetGraphSize();
}

void CellClass::AssociateBoard()
{
	auto offset = (Rate)this->board_offset + (Rate)this->offset*(Rate)0.1;

	this->coordinate = (this->rate - this->d_rate)*((ObjCoord)this->cell_coord*this->board_cell_size + offset);
}

void CellClass::UpDate()
{
	this->AssociateBoard();
}

void CellClass::Set(const int &x, const int &y)
{

}