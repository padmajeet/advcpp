#include <iostream>
#include <vector> // manages dynamically growing array
#include <list> // linked list of nodes
using namespace std;

// without tempalte
//class Stack
//{
//	vector<int> items;
//public:
//	void Push(int item)
//	{
//		items.push_back(item);
//	}
//	int Pop()
//	{
//		int lastItem = items[items.size() - 1];
//		items.pop_back();
//		return lastItem;
//	}
//};


//template<typename TCollection>
//class Stack
//{
//	TCollection items;
//public:
//	void Push(int item)
//	{
//		items.push_back(item);
//	}
//	int Pop()
//	{
//		int lastItem = items[items.size() - 1];
//		items.pop_back();
//		return lastItem;
//	}
//};

class Abstraction
{
public:
	virtual void push_back(int item) = 0 ;
	virtual void pop_back() = 0 ;
	virtual int operator[](int index) = 0;
	virtual unsigned int size() = 0;
};

class Stack
{
	Abstraction *items = nullptr ;
public:
	void SetCollection(Abstraction *collection)
	{
		if ( this->items == nullptr)
			this->items = collection;
		else
		{
			// copy from old collection to new
			// set the new collecton address in items
		}
	}
	void Push(int item)
	{
		items->push_back(item);
	}
	int Pop()
	{
		int lastItem = items->operator[] (items->size() - 1);
		items->pop_back();
		return lastItem;
	}
};


//class Stack : private vector<int>
//{
//public:
//	void Push(/* Stack *this */ int item)
//	{
//		this->push_back(item);
//	}
//	int Pop()
//	{
//		int lastItem = (*this)[this->size() - 1];
//		this->pop_back();
//		return lastItem;
//	}
//};

class myvector : public vector<int>, public Abstraction
{
public:
	void push_back(int item) override
	{
		vector<int>::push_back(item);
	}
	void pop_back() override
	{
		vector<int>::pop_back();
	}
	int operator[] (int index) override
	{
		return vector<int>::operator[] (index);
	}
	unsigned int size() override
	{
		return vector<int>::size();
	}
};

class mylist : public list<int>, public Abstraction
{
public:
	void push_back(int item) override
	{
		list<int>::push_back(item);
	}
	void pop_back() override
	{
		list<int>::pop_back();
	}
	int operator[] (int index) override
	{
		return 10;
	}
	unsigned int size() override
	{
		return list<int>::size();
	}
};
void main()
{
	//Stack<list<int>> s1;
	Stack s1;

	myvector v1;
	s1.SetCollection(&v1);
	s1.Push(100);
	s1.Push(200);
	s1.Push(300);

	mylist l1;
	s1.SetCollection(&l1);
	s1.Push(400);
	s1.Push(500);
	s1.Push(600);


	s1.Push(400);
	cout << s1.Pop() << endl;

	//Stack<vector<int>> s2;
	//s2.Push(100);
	//s2.Push(200);
	//s2.Push(300);
	//s2.Push(400);
	//cout << s2.Pop() << endl;

	//Stack s1;
	//s1.Push(100);
	//s1.Push(200);
	//s1.Push(300);
	//s1.Push(400);
	//cout << s1.Pop() << endl;
}
