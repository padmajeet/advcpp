#include <iostream>
#include <map>
#include <memory>
#include <string>
using namespace std;

class Class
{
public:
};
class Factory // abstraction
{
public:
	static map<string, Factory*> factories; // decl
	Factory(/* Factory *this = &c1f, &c2f */ const string &name)
	{
		factories[name] = this; 
		// key (c1) - value (&c1f)
		// key (c2) - value (&c2f)
	}
	virtual unique_ptr<Class> Create() = 0; // pure-virtual (abstract)
};
map<string, Factory*> Factory::factories; // def

void Fun(const string &s)
{
	Factory *factory = Factory::factories[s];
	unique_ptr<Class> c = factory->Create();
}

void main()
{
	string str;
	cin >> str;
	Fun(str);
}

class Class1 : public Class
{
};
class Class1Factory : public Factory
{
public:
	Class1Factory(/* Circle1Factory *this = &c1f */ const string& name /* = c1 */) 
		: Factory(/* value of this = &c1f*/ name) { }

	unique_ptr<Class> Create() override
	{
		return unique_ptr<Class>(new Class1());
	}
};
Class1Factory c1f("c1"); 
// 1. memory is allocated for the object (c1f)
// 2. Class1Factory (&c1f, "c1")

class Class2 : public Class
{
};
class Class2Factory : public Factory
{
public:
	Class2Factory(/* Circle2Factory *this = &c2f */ const string& name /* = c2 */)
		: Factory(/* value of this = &c2f*/ name) { }

	unique_ptr<Class> Create() override
	{
		return unique_ptr<Class>(new Class2());
	}
};
Class2Factory c2f("c2");
// 1. memory is allocated for the object (c2f)
// 2. Class1Factory (&c2f, "c2")