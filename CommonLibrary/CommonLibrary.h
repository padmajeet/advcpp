#include <memory>
#include <vector>
using namespace std;

class OS // abstraction
{
public:
	virtual void DrawCircle() = 0;
	virtual void DrawRectangle() = 0;
	virtual void DrawPath() = 0;
	virtual void DrawBezier() = 0;
};

class __declspec(dllexport) Shape // abstraction
{
protected:
	unique_ptr<OS> pos;
	Shape();
public:
	virtual void Draw() = 0; // same for all shapes
};

class __declspec(dllexport) ShapeFactory // abstraction
{
protected:
	ShapeFactory(/* ShapeFactory *this */);
public:
	virtual string GetName() = 0;
	virtual unique_ptr<Shape> Create() = 0;
	static vector<ShapeFactory*>& GetFactories();
};