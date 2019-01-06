#pragma once
#include "Primitive.h"
class Group : public Model
{
private:
	std::vector<Model*> _modelList;

public:
	void draw() override;
	void addModel(Model &model);
};

