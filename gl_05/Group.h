#pragma once
#include "Primitive.h"
class Group :
	public Model
{
	std::vector<Model*> _modelList;

	void draw() override;
};

