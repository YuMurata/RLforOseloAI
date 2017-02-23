#include"stdafx.h"

#include"Object.h"

Object::Object()
{}
Object::~Object()
{}

Object::Object(const ObjCoord &obj, const string &file_name)
	:relative(obj), BaseObject(obj, file_name) {}

void Object::AssociateBG(const BackGroundClass &obj)
{
	this->coordinate = obj.GetCoord() + this->relative;
}

void Object::UpDate()
{
}