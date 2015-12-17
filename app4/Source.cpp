#include <iostream>
#include <fstream>
using namespace std;

class Store
{
public:
	virtual void Save(int *items, int top) = 0;
};
class Stack
{
	int items[10], top = 0 ;
public:
	void Push(int item)
	{
		items[top] = item;
		top++;
	}
	int Pop()
	{
		top--;
		return items[top];
	}
	void Save(Store *st)
	{
		st->Save(items, top);
	}
};

class TextFile : public Store
{
public:
	void Save(int *items, int top) override
	{
		ofstream file("data.txt");
		for (int i = 0; i < top; i++)
			file << items[i] << "\n";
		file.close();
	}
};

class XmlFile : public Store
{
public:
	void Save(int *items, int top) override
	{
		ofstream file("data.xml");
		for (int i = 0; i < top; i++)
		{
			file << "<item>" << items[i] << "</item>" << "\n";
		}
		file.close();
	}
};
void main()
{
	Stack s1;
	s1.Push(100);
	s1.Push(200);
	s1.Push(300);
	s1.Push(400);
	s1.Save(&TextFile()); // save to the persistent store
	s1.Save(&XmlFile());
}