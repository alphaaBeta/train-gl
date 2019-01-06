#include "Group.h"

void Group::draw()
{
	for (const auto &model : _modelList)
	{
		model->render();
	}
}
