#include "Group.h"


void Group::draw()
{
	for (const auto &model : _modelList)
	{
		model->render();
	}
}

void Group::addModel(Model& model)
{
	this->_modelList.push_back(&model);
}
