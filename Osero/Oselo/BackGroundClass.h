#pragma once

#include"stdafx.h"
#include"BaseObject.h"

class BackGroundClass :public BaseObject
{
public:
	BackGroundClass() {}
	~BackGroundClass() {}

	BackGroundClass(const ObjCoord &obj, const string &file_name)
		:BaseObject(obj, file_name){}

	virtual void UpDate()
	{

	}
};