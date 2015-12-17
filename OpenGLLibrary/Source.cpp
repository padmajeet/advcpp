#include <iostream>
using namespace std;

// Implementation
class OpenGL : public OS// LINUX OS
{
public:
	void DrawCircle() override
	{
		cout << "Circle - OpenGL" << endl;
	}
	void DrawRectangle() override
	{
		cout << "Rectangle - OpenGL" << endl;
	}
	void DrawPath() override
	{
		cout << "Path - OpenGL" << endl;
	}

	void DrawBezier() override
	{
		cout << "Bezier - OpenGL" << endl;
	}
};