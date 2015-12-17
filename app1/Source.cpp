#include <iostream>
#include <array> // statically allocated array
#include <vector> // dynamically allocated array
#include <list>
#include <assert.h>
using namespace std;

template<typename T>
class mylinkedlist
{
private:
	class Node
	{
	public:
		T data;
		Node *next = nullptr;
	};
	Node *head = nullptr, *last = nullptr;
public:
	mylinkedlist(initializer_list<T> list)
	{
		for (T item : list)
			add(item);
	}
	void add(T item)
	{
		Node *newNode = new Node; // dynamic object live longer
		newNode->data = item;
		if (head == nullptr)
			head = last = newNode; 
		else
		{
			last->next = newNode;
			last = last->next;
		}
	}

	class iterator
	{
		Node *_ptr;
	public:
		iterator(Node *ptr) : _ptr(ptr) { }
		bool operator != ( /* iterator *this = &beginit */ const iterator &endit)
		{
			return this->_ptr != endit._ptr;
		}
		void operator++(/* iterator *this = &beginit */) // pre
		{
			_ptr = _ptr->next;
		}
		void operator++(/* iterator *this = &beginit */ int n) // post
		{
			_ptr = _ptr->next;
		}
		T operator*(/* iterator *this = &beginit */)
		{
			return _ptr->data;
		}
	};

	iterator begin(/* mylinkedlist *this */)
	{
		return iterator(this->head);
	}

	iterator end(/* mylinkedlist *this */)
	{
		return iterator(nullptr);
	}
};



template<typename T, size_t size>
class mycollection
{
	T items[size];
public:
	mycollection(initializer_list<T> list)
	{
		assert(size >= list.size(), "Size must be same");

		int i = 0;
		for (T item : list)
		{
			items[i] = item;
			i++;
		}
	}

	// nested class
	class iterator // this class object is the solution of the problem 
	{
		int _index;  // data members
		mycollection *_mc;  // data members
	public:
		iterator(int index, mycollection *mc = nullptr) : _index(index), _mc(mc)
		{
		}

		bool operator != (/* iterator *this = &beginit */ const iterator &endit)
		{
			return this->_index < endit._index;
		}

		T operator*(/* iterator *this = &beginit */)
		{
			return this->_mc->items[this->_index];
		}

		void operator++(/* iterator *this = &beginit */)  // pre
		{
			this->_index++;
		}

		void operator++(/* iterator *this = &beginit */ int n) // post
		{
			this->_index++;
		}
	};

	iterator begin(/* mycollection *this */)
	{
		return iterator(0, this);
	}

	iterator end(/* mycollection *this */)
	{
		return iterator(size);
	}
};

int main()
{
	//int a[] = { 1, 2, 3, 4, 5}; // c-statically allocated array

	//array<int, 5> a = { 1, 2, 3, 4, 5 }; // c++ statically allocated array

	//vector<int> a{ 1, 2, 3, 4, 5 }; // c++ dynamically allocated array

	//list<int> a{ 1, 2, 3, 4, 5 }; // c++ dynamically allocated linked list

	//mycollection<int, 10> mc{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	mylinkedlist<int> ml{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (int item : ml) // range-for
		cout << item << endl ;

	// expansion of range-for
	// beginit.operator != ( end(mc) ) // jmp address_of_function
	// beginit.operator++() // jmp address_of_function
	for (auto beginit = ml.begin(); beginit != ml.end(); beginit++)
		cout << *beginit << endl;  // beginit.operator* ( ) // jmp address_of_function

	// mc.begin()  
	// mc.end()
	// beginit.operator != ( end(mc) ) 
	// beginit.operator++()
	//for (auto beginit = begin(mc); beginit != end(mc); beginit++)
	//	cout << *beginit << endl;  // beginit.operator* ( ) 

	// for loop or range-for can traverse any collection of items
	// without worrying about the internal representation of the collection
	// but only in sequential order => iterator

	return 0;
}