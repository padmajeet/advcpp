#include "CommonLibrary.h"

Shape::Shape()
{
}

vector<ShapeFactory*> factories;

ShapeFactory::ShapeFactory(/* ShapeFactory *this */)
{
	factories.push_back(this); // &cf and &rf
}

vector<ShapeFactory*>& ShapeFactory::GetFactories()
{
	return factories;
}
