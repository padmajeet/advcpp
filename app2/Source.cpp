#include <iostream>
#include <memory> // unique_ptr<>
using namespace std;

/* IteratorInterface VTable
&IteratorInterface::operator!=(const IteratorInterface* endit)
&IteratorInterface::operator++()
&IteratorInterface::operator*()
*/
class IteratorInterface
{
	// *vptr 
public:
	virtual bool operator != (const IteratorInterface* endit) = 0;
	virtual void operator ++() = 0;
	virtual int operator*() = 0;
};

/* CollectionInterface VTable
&CollectionInterface::begin() // offset : 0
&CollectionInterface::end() // offset : 4
*/
class CollectionInterface // Interface for each collection
{
	// *vptr 
public:
	virtual unique_ptr<IteratorInterface> begin() = 0; // virtual tells the compiler not to do early binding
	virtual unique_ptr<IteratorInterface> end() = 0; // virtaul tells the compiler not to do early binding
};

unique_ptr<CollectionInterface> GetObject(); // declaration
int main()
{
	unique_ptr<CollectionInterface> collection = GetObject(); // either hold address myarray object or mylinkedlist object
	for (auto beginit = collection->begin(); beginit->operator != ( collection->end().get() ); beginit->operator++() )
		cout << beginit->operator*() << endl;

	
	// instead of previous use this also
	//CollectionInterface &collection = *GetObject(); // either hold address myarray object or mylinkedlist object
	//for (auto &beginit = *(collection.begin()); beginit !=collection.end(); beginit++)
	//	cout << *beginit<< endl;



	//CollectionInterface &rcollection = *GetObject(); // either hold address myarray object or mylinkedlist object
	//for (auto &beginit = *rcollection.begin(); beginit != rcollection.end(); beginit++)
	//	cout << *beginit << endl;

	// whenever compiler sees that we are using pointer to virtual function, the compiler
	// goes for late binding
	// For each call 5 instructions are generated
	// collection->begin()
	// 1. get value collection pointer => &of object
	// 2. get the vptr value from the object => &of object's class vtable
	// 3. add offset of begin(0) + &vtable => new address
	// 4. get value from new address => &of actual function
	// 5. call the actual function ( pass &of object obtained in 1st instr)

	return 0;
}

// DLL or Shared Object (library)
/* myarray VTable
&myarray::begin() // offset : 0
&myarray::end() // offset : 4
*/
class myarraydjfkdsjkfjskdljfksdjkfjdskfjskdjfkdsj : public CollectionInterface
{
private:
	int items[3];
public:
	myarraydjfkdsjkfjskdljfksdjkfjdskfjskdjfkdsj() //: vptr ( &myarray vtable) { }
	{
		items[0] = 1; items[1] = 2; items[2] = 3;
	}

	class iterator : public IteratorInterface
	{
		int _index;
		myarraydjfkdsjkfjskdljfksdjkfjdskfjskdjfkdsj *_arr;
	public:
		iterator(int index, myarraydjfkdsjkfjskdljfksdjkfjdskfjskdjfkdsj *arr = nullptr) : _index(index), _arr(arr) { }

		bool operator != (const IteratorInterface* endit) override 
		{ 
			return (this->_index < static_cast<const iterator*>(endit)->_index);
		}

		void operator ++() override 
		{ 
			this->_index++;
		}

		int operator*() override 
		{
			return this->_arr->items[this->_index];
		}
	};

	unique_ptr<IteratorInterface> begin() override
	{
		return unique_ptr<IteratorInterface>(new iterator(0, this)); // long-lived
	}

	unique_ptr<IteratorInterface> end() override
	{
		return unique_ptr<IteratorInterface>(new iterator(3)); // long-lived
	}
};


// DLL or Shared Object (library)
/* mylinkedlist VTable
&mylinkedlist::begin() // offset : 0
&mylinkedlist::end() // offset : 4
*/
class mylinkedlist : public CollectionInterface
{
private:
	class Node { public: int data; Node *next = nullptr; };
	Node *head;
public:
	mylinkedlist() // : vptr ( &of mylinkedlist vtable)
	{
		head = new Node(); head->data = 11;
		head->next = new Node(); head->next->data = 12;
		head->next->next = new Node(); head->next->next->data = 13;
	}

	class iterator : public IteratorInterface
	{
		Node *_ptr;
	public:
		iterator(Node *ptr) : _ptr(ptr) { }

		bool operator != (const IteratorInterface *endit)
		{
			return this->_ptr != static_cast<const iterator*>(endit)->_ptr;
		}

		void operator ++() override
		{
			_ptr= _ptr->next;
		}

		int operator*() override
		{
			return _ptr->data;
		}
	};
	unique_ptr<IteratorInterface> begin() override
	{
		return unique_ptr<IteratorInterface>(new iterator(head));
	}

	unique_ptr<IteratorInterface> end() override
	{
		return unique_ptr<IteratorInterface>(new iterator(nullptr));
	}
};

unique_ptr<CollectionInterface> GetObject()
{
	return unique_ptr<CollectionInterface>(new mylinkedlist());
}