


#include "..\CommonLibrary\CommonLibrary.h" // for compiler 

#pragma comment ( lib, "..\\CommonLibrary\\Debug\\CommonLibrary.lib") // for library

class Rectangle : public Shape
{
public:
	void Draw() override
	{
		pos->DrawRectangle();
	}
};


class RectangleFactory : public ShapeFactory
{
public:
	// RectangleFactory ( RectangleFactory *this = &rf )
	//   : ShapeFactory ( value of this = &rf ) ;
	// { }
	string GetName()
	{
		return "Rectangle";
	}
	unique_ptr<Shape> Create()
	{
		return unique_ptr<Shape>(new Rectangle());
	}
};
RectangleFactory rf;