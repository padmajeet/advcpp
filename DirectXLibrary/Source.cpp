#include <iostream>
using namespace std;

class DirectX : public OS// Windows OS
{
public:
	void DrawCircle() override
	{
		cout << "Circle - DirectX" << endl;
	}
	void DrawRectangle() override
	{
		cout << "Rectangle - DirectX" << endl;
	}
	void DrawPath() override
	{
		cout << "Path - DirectX" << endl;
	}
	void DrawBezier() override
	{
		cout << "Bezier - DirectX" << endl;
	}
};