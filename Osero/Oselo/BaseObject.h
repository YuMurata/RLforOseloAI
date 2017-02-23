#pragma once

#include"stdafx.h"

#include"RateClass.h"

#include<Coordinate.h>

using namespace std;

typedef TCoordinate<double> ObjCoord;
typedef TCoordinate<int> GraphSize;

class BaseObject
	:public RateClass
{
protected:
	ObjCoord coordinate;
	GraphSize graph_size;

	int handle;
	
public:
//Constructor
	BaseObject();
	BaseObject(const ObjCoord &obj, const string &file_name);

	~BaseObject();

//Init

	//
	void Init(const ObjCoord &obj, const string &file_name);

//Draw

	//
	virtual void Draw()const;

//UpDate

	//
	virtual void UpDate() = 0;


//Set

	//
	void SetCoord(const ObjCoord &obj);

	//
	void SetGraphSize();
	
//Get

	//
	ObjCoord GetCoord()const;

	//
	GraphSize GetGraphSize()const;
};