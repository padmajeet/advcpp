#include <iostream>
#include <functional>
using namespace std;

//void F1(void(*funcptr)(int)) // will be compiled to DLL
void F1( function<void(int)> func ) // will be compiled to DLL
{
	for (int i = 1; i <= 10; i++)
	{
		//funcptr(i);
		func(i); // obj(i) ; // obj.operator() ( i ); 
	}
}
//------------------------------------------------
//void ReceiveValueOfIConsole( int i )
//{
//	cout << "Console - " << i << endl;
//}
//// Project-1 : Console App
//void main()
//{
//	F1(ReceiveValueOfIConsole);
//}
//------------------------------------------------
//void ReceiveValueOfIGUI(int i)
//{
//	cout << "Label - " << i << endl;
//}
//// Project-2 : GUI App
//void main()
//{
//	F1(ReceiveValueOfIGUI);
//}

//-------------------------------------------------
class Receiver
{
public:
	int _x;  // instance data member
	Receiver(int value) : _x(value) { }

	void ReceiveValue1(/* Receiver *this */ int i) // instance method
	{
		cout << "ReceiveValue1 - " << i << " " << this->_x << endl ;
	}

	void ReceiveValue2(/* Receiver *this */ int i) // instance method
	{
		cout << "ReceiveValue2 - " << i << " " << this->_x << endl;
	}

	void operator() (/* Receiver *this */ int i)
	{
		cout << "operator() - " << i << " " << this->_x << endl;
	}
};
void ReceiveValueOfIGUI(int i) // only 1 parameter (no this pointer)
{
	cout << "Label - " << i << endl;
}
// Project-1 : Console App
void main()
{
	Receiver obj(300);
	Receiver r1(100), r2(200);

	// case 1
	//F1(ReceiveValueOfIGUI);  // address of global function

	// case 2
	//F1(bind(&Receiver::ReceiveValue1, &r1, placeholders::_1)); 
	// address of instance method + address of object

	// case 3
	//F1(obj); // object of the class that has overloaded operator()

	F1([&obj,&r1,&r2](int i) { cout << "Lambda - " << i  << " " << obj._x << " " << r1._x << " " << r2._x << " " << endl; });


}