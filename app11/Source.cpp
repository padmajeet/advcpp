#include <iostream>
using namespace std;

class Point
{
	int *items;
public:
	Point() { /*items = new int[1000]; */ }
    Point(int x) 
	{
		//items = new int[1000];
		cout << "1-arg ctor" << endl; 
	}
	Point(int x, int y) 
	{ 
		cout << "2-arg ctor" << endl;
	}
	~Point()
	{
	/*	if ( items != nullptr )
			delete items;*/
	}

	Point(const Point& p) { cout << "copy ctor" << endl; }
	void operator=(const Point& rhs) 
	{ 
		cout << "copy assignment" << endl;
		for (int i = 0; i < 100; i++)
			this->items[i] = rhs.items[i];
	}
	
	Point(Point&& p) { cout << "move ctor" << endl; }
	void operator=(Point&& rhs)
	{
		cout << "move assignment" << endl;
		this->items = rhs.items;
		rhs.items = nullptr;
	}
};

Point g_p;
//void F1(Point p) // Point p(temp object value)
//{
//	g_p = p; // operator = ( )
//}

// &p -> l-value reference
//void F(const Point& p) // Point * const p = &p1
//{
//	g_p = p; // *p // *&p1 // p1 // operator = ( )
//}
//
//// &&p -> r-value reference
//void F(Point&& p)  // Point * const p = & of an object
//{
//	g_p = move(p); // operator = ( )
//}


// &&p -> r-value reference
//template <typename T>
//void F(T&& p)  // Point * const p = & of an object
//{
//	g_p = forward<T>(p); // operator = ( )
//}


template<typename... T>
void F(T... args) // variadic templates
{
	new (&g_p) Point ( forward<T>(args)... );
}

template<typename T>
T Sum(T item)
{
	return item;
}
template<typename TFirst, typename... TRemaining>
TFirst Sum(TFirst first, TRemaining... item)
{
	TFirst  s = 0;
	s += first + Sum(item...);
	return s;
}

template<typename T1, typename T2>
auto Sum(T1 x, T2 y) -> decltype(x+y)
{
	return x + y;
}

void main()
{
	cout << Sum(10, 30.5) << endl;
	cout << Sum(10.5, 30) << endl;

	//cout << Sum(10, 20, 30, 40, 50) << endl ;
	//Point p1(10); // l-value object
	
	//F1(p1); // passing an object (passing the value of the object)

	 //F(p1); // F2( &p1 ); 

	//F(Point(10)/* r-value object*/); // F2( &p1 ); 
	//F(10, 10); // 2-arg ctor

	//F(Point(10, 10)); // 2-arg ctor and move ctor

	//Point p1(10); // 1-arg ctor
	//F(p1); // copy ctor
}
