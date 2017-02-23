#include"stdafx.h"

#include"ObjectMGR.h"

class ObjectMGR::ObjectType
{
private:
	const char *obj[NUM] =
	{
		"B",
		"O",
		"C"
	};
public:
	ObjectType() {}
	const char* operator[](const int &index)
	{
		return this->obj[index];
	}

	int Get(const string &type)
	{
		auto beg = begin(this->obj);
		auto last = end(this->obj);

		auto itr = find(beg, last, type);

		return distance(beg, itr);
	}
};


ObjectMGR::ObjectMGR()
{
	this->builder.Register<BackGroundClass>(ObjectType()[B]);
	this->builder.Register<Object>(ObjectType()[O]);
	this->builder.Register<CellClass>(ObjectType()[C]);
}

ObjectMGR::~ObjectMGR()
{}

void ObjectMGR::Regist(const BaseObject *obj)
{
	//	this->objects.push_back(make_unique<ObjectClass>(*obj));
}

void ObjectMGR::LoadObject(const string &file_name)
{
	const string pass_name = "figure\\";

	string line;
	ifstream ifs(file_name);

	string obj_type;
	ObjCoord coord;
	string fig_name;

	while (ifs >> obj_type >> coord.x >> coord.y >> fig_name)
	{
		auto obj = this->builder.Create(obj_type);
		obj->Init(coord, pass_name + fig_name);

		auto type_index = ObjectType().Get(obj_type);

		switch (type_index)
		{
		case B:
			background = move(obj);
			break;

		default:
			this->objects.push_back(move(obj));
			break;
		}
	}
}

void ObjectMGR::UpDate()
{
	this->PreFunc(&BaseObject::UpDate);
}

void ObjectMGR::Draw()const
{
	this->PreFunc(&BaseObject::Draw);
}

void ObjectMGR::PreFunc(void (BaseObject::*func)())
{
	(*background.*func)();

	for (auto &i : this->objects)
	{
		(*i.*func)();
	}
}

void ObjectMGR::PreFunc(void (BaseObject::*func)()const)const
{
	(*background.*func)();

	for (auto &i : this->objects)
	{
		(*i.*func)();
	}
}