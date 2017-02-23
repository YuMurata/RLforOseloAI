#pragma once

#include"stdafx.h"

#include"BaseObject.h"
#include"BackGroundClass.h"

class Object:public BaseObject
{
protected:
	ObjCoord relative;

public:
	Object();
	~Object();

	Object(const ObjCoord &obj, const string &file_name);

	void AssociateBG(const BackGroundClass &obj);

	virtual void UpDate();
};