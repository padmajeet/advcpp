#include <memory>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Example*************************************************************
class object_t
{
public:
	template<typename T>
	object_t(T x) : self_(make_shared<model<T>>(move(x))) { }

	void draw(ostream& out, size_t position) const
	{
		self_->draw_(out, position);
	}

private:
	struct concept_t // abstraction
	{
		// *vptr
		virtual ~concept_t() = default;
		virtual void draw_(ostream&, size_t) const = 0;
	};

	template<typename T>
	struct model : concept_t // vtable
	{
		model(T x) : data_(move(x)) { }
		void draw_(ostream& out, size_t position) const
		{
			data_.draw(out, position);
		}

		T data_;
	};
	shared_ptr<const concept_t> self_;
};


using document_t = vector < object_t > ;

void draw(const document_t& x, ostream& out, size_t position)
{
	out << string(position, ' ') << "<document>" << endl;
	for (const auto& e : x)
		e.draw(out, position + 2);
	out << string(position, ' ') << "<document>" << endl;
}


class myclass1 // implementation
{
public:
	void draw(ostream& out, size_t position) const
	{
		out << string(position, ' ') << "myclass1" << endl;
	}
};

class myclass2
{
public:
	void draw(ostream& out, size_t position) const
	{
		out << string(position, ' ') << "myclass2" << endl;
	}
};

class myclass3
{
public:
	void draw(ostream& out, size_t position) const
	{
		out << string(position, ' ') << "myclass3" << endl;
	}
};
class myclass4
{
public:
	void draw(ostream& out, size_t position) const
	{
		out << string(position, ' ') << "myclass4" << endl;
	}
};

void main()
{
	document_t document;
	document.emplace_back(myclass1());
	document.emplace_back(myclass2());
	document.emplace_back(myclass3());
	document.emplace_back(myclass4());
	draw(document, cout, 0);
}