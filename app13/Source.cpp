#include <algorithm>
#include <random>
#include <iostream>
#include <vector>
#include <tuple>
#include <string>
using namespace std;
#include <conio.h>

//template<typename I>
//auto slide(I f, I l, I p) -> pair < I, I >
//{
//	if (p < f) return{ p, rotate(p, f, l) };
//	if (l < p) return{ rotate(f, l, p), p };
//	return{ f, l };
//}
//
//template<typename I, typename S>
//auto gather(I f, I l, I p, S s) -> pair<I,I>
//{
//	return { stable_partition(f, p, not1(s), stable_partition(p, l, s)) };
//	// stable_sort
//	// nth_element
//}

//class Point
//{
//private:
//	int x_, y_;
//public:
//	Point() = default;
//	Point(int x, int y) : x_(x), y_(y) { }
//	
//	int GetX() const { return x_; }
//	int GetY() const { return y_; }
//
//	bool operator == (/* Point *this = &lhs */ const Point& rhs)
//	{
//		return this->x_ == rhs.x_ && this->y_ == rhs.y_;
//	}
//};

//class FindByY // Functor
//{
//	int y_;
//public:
//	FindByY(int value) : y_(value)
//	{
//	}
//	bool operator() (const Point& lhs)
//	{
//		return lhs.GetY() == y_;
//	}
//};

//class FindByX // Functor
//{
//	int x_;
//public:
//	FindByX(int value) : x_(value)
//	{
//	}
//	bool operator() (const Point& lhs)
//	{
//		return lhs.GetX() == x_;
//	}
//};

//vector<string::iterator> find_all(string& s, char c) // find all occurrences of c in s
//{
//	vector<string::iterator> res;
//	for (auto p = begin(s); p != end(s); ++p)
//		if (*p == c)
//			res.push_back(p);
//	return res;
//}
//
//void main()
//{
//	//vector<char> m{ 'a', 'b', 'a' };
//	string m { "Mary had a little lamb" };
//	for (auto p : find_all(m, 'a'))
//		cout << *p << " ";
//	cout << endl ;
//}

//class Between
//{
//	int min, max;
//public:
//	Between(int min, int max) : min(min), max(max)
//	{
//	}
//	bool operator() (int item)
//	{
//		return (item > min && item < max);
//	}
//};

tuple<string,int, double, char> F1()
{
	return make_tuple("hello", 10, 90.4, 'h');
}

tuple<string, int, double> F2()
{
	return make_tuple("hello", 10, 90.4 );
}

tuple<string, int> F3()
{
	return make_tuple("hello", 10);
}


void main()
{
	auto t = F1();
	cout << get<0>(t) << endl;
	cout << get<1>(t) << endl;
	cout << get<2>(t) << endl;
	cout << get<3>(t) << endl;
}
void main()
{

	// example 4
	//vector<int> v{ 1, 2, 3, 4, 5, 3 };
	//auto iter =  find_if(begin(v), end(v), Between(3, 6));
	//cout << *iter << endl;



	// example 3
//	vector<Point> v{ Point(10, 10), Point(120, 120), Point(30, 30) };
//	vector<Point>::iterator iter = find_if(begin(v), end(v), FindByX(120)); // return iterators
////	iter = find_if(begin(v), end(v), FindByX(30)); // return iterators
//	if (iter == end(v))
//		cout << "Point not found" << endl;
//	else
//		cout << "Point found" << endl;

	// example 2
	//vector<Point> v{ Point(10,10), Point(20,20), Point(30,30) };
	//vector<Point>::iterator iter = find(begin(v), end(v), Point(120,20)); // return iterators
	//if (iter == end(v))
	//	cout << "Point not found";
	//else
	//	cout << "Point found";

	// example: 1
	//vector<int> v{ 1, 2, 3, 4, 5, 3 };
	//vector<int>::iterator iter = find(begin(v), end(v), 3); // return iterators
	//iter = find(iter + 1, end(v), 3); // return iterators

	//if (iter == end(v))
	//	cout << "Number not found";
	//else
	//	cout << "Number found";

	//cout << endl;


	//int arr[] = { 1, 2, 3, 4, 5, 6 };
	//slide(begin(arr) + 4, begin(arr) + 6, begin(arr) + 1);
	//for (int number : arr)
	//	cout << number << " ";
	//cout << endl;
	//slide(begin(arr) + 1, begin(arr) + 3, begin(arr) + 6);
	//for (int number : arr)
	//	cout << number << " ";
	//cout << endl;


	//while (true)
	//{
	//	int winning[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0 };
	//	int numbers[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0 };

	//	std::random_device random_device;
	//	std::mt19937 g ( random_device() );

	//	// shuffle is an algorithm
	//	shuffle(begin(numbers), end(numbers), g);

	//	for (int number : numbers)
	//		cout << number << " "; 

	//	cout << endl;
	//	_getch();
	//	//int numbers[4][4]; 
	//}
}