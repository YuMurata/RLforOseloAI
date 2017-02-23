#pragma once

#include"stdafx.h"

#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<memory>

#include"BackGroundClass.h"
#include"Object.h"
#include"CellClass.h"
#include<Builder.h>

using namespace std;

class ObjectMGR
{
private:
	enum OBJECT_TYPE
	{
		B,
		O,
		C,
		NUM,
	};
	
	class ObjectType;

	void PreFunc(void (BaseObject::*func)());

	void PreFunc(void (BaseObject::*func)()const)const;
	
	vector<unique_ptr<BaseObject>> objects;
	unique_ptr<BaseObject> background;
	BuildClass<BaseObject> builder;

public:
	ObjectMGR();

	~ObjectMGR();
	
	void Regist(const BaseObject *obj);

	void LoadObject(const string &file_name);

	void UpDate();

	void Draw()const;
};
