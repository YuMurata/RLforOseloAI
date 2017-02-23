#include"stdafx.h"

#include"BaseObject.h"

//Constructor
BaseObject::BaseObject() {}
BaseObject::BaseObject(const ObjCoord &obj, const string &file_name)
{
	Init(obj, file_name);
}

BaseObject::~BaseObject() {}

//Init

//
void BaseObject::Init(const ObjCoord &obj, const string &file_name)
{
	SetCoord(obj);

	this->handle = LoadGraph(file_name.data());

	DxLib::GetGraphSize(this->handle, &this->graph_size.x, &this->graph_size.y);

	SetRate(Rate(1, 1));
}

//Draw

//
void BaseObject::Draw()const
{
	auto left = this->coordinate.x;
	auto top = this->coordinate.y;

	auto right = left + this->graph_size.x*this->rate.x;
	auto down = top + this->graph_size.y*this->rate.y;

	DrawExtendGraphF
		(
			left, top,
			right, down,
			this->handle, TRUE
			);
}

//Set

//
void BaseObject::SetCoord(const ObjCoord &obj)
{
	this->coordinate = obj;
}

//
void BaseObject::SetGraphSize()
{
	DxLib::GetGraphSize(this->handle, &this->graph_size.x, &this->graph_size.y);
}

//Get

//
ObjCoord BaseObject::GetCoord()const
{
	return this->coordinate;
}

//
GraphSize BaseObject::GetGraphSize()const
{
	return this->graph_size;
}