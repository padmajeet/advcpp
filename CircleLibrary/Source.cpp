#include <memory>
#include <string>
using namespace std;

#include "..\CommonLibrary\CommonLibrary.h" // for compiler 

#pragma comment ( lib, "..\\CommonLibrary\\Debug\\CommonLibrary.lib") // for library

class Circle : public Shape
{
public:
	void Draw() override
	{
		pos->DrawCircle();
	}
};

class CircleFactory : public ShapeFactory
{
public:
	// CircleFactory ( CircleFactory *this = &cf )
	//   : ShapeFactory ( value of this = &cf ) ;
	// { }

	string GetName()
	{
		return "Circle";
	}
	unique_ptr<Shape> Create()
	{
		return unique_ptr<Shape>(new Circle());
	}
};
CircleFactory cf;