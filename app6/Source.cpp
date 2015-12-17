#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
#include <conio.h>

mutex m;

void F1()
{
	//code

	{
		lock_guard<mutex> lg(m); // ctor (m.lock())
		// i++;
		/// ::::
	} // dtor (m.unlock())

	//code

	//code

} 

void F2()  // ctor (m.lock())
{

	lock_guard<mutex> lg(m);
	// i++;
	/// ::::

} // dtor (m.unlock())

void main()
{
	thread t1(F1);
	thread t2(F2);

	_getch();
}