#include <vector>
#include <iostream>
using namespace std;

class Point
{
public:
	Point() { }
	Point(int x, int y)
	{
		cout << "2-arg ctor" << endl;
	}
	Point(const Point&)
	{
		cout << "copy ctor" << endl;
	}
	Point( Point&&)
	{
		cout << "move ctor" << endl;
	}
};

void main()
{
	vector<Point> v ;
	//v.push_back(Point(10, 10));
	v.emplace_back(10, 10);
}