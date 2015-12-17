#include <iostream>
#include <thread>
#include <memory>
using namespace std;
#include <conio.h>
#include <stdio.h>
#include <windows.h>
//
//void F1() // st1
//{
//	// statically allocated object
//	unique_ptr<int> p (new int); // RAII
//
//	//int *q = nullptr;
//	//try
//	//{
//	//	q = new int;
//	//}
//	//finally
//	//{
//	//	delete q; 
//	//}
//
//	// exception
//	// if ( ) return
//
//	//delete p;
//}

int i = 0;
//CRITICAL_SECTION cs; // C++ standard: mutex m;
// cs: owner = st2 and waiting = null

class MyCriticalSection
{
private:
	CRITICAL_SECTION cs; // C++ standard: mutex m;
public:
	MyCriticalSection()
	{
		InitializeCriticalSection(&cs);
	}
	
	void Lock()
	{
		EnterCriticalSection(&cs);
	}

	void Unlock()
	{
		LeaveCriticalSection(&cs);
	}
};

class MyCriticalSectionRAII
{
	MyCriticalSection &_cs;
public:
	MyCriticalSectionRAII(MyCriticalSection &cs) : _cs(cs)
	{
		_cs.Lock();
	}
	~MyCriticalSectionRAII()
	{
		_cs.Unlock();
	}
};

MyCriticalSection cs;

void F1() // st1
{
	//EnterCriticalSection(&cs);
	MyCriticalSectionRAII raii1(cs);
	i++;
	printf("F1: %d  ", i); // 1
	Sleep(100);
	return;
	i++;
	printf("F1: %d  ", i); // 3
	//cs.Unlock();
	//LeaveCriticalSection(&cs);
}

void F2() // st2
{
	//EnterCriticalSection(&cs); // st2 goes to wait
	MyCriticalSectionRAII raii2(cs);
	//cs.Lock();

	i++;
	printf("F2: %d  ", i); // 2
	Sleep(100);
	i++;
	printf("F2: %d  ", i); // 4
	
	//cs.Unlock();

	//LeaveCriticalSection(&cs);
}

void main() // called using main thread
{
	//InitializeCriticalSection(&cs); 

	thread t1(F1); // st 1
	thread t2(F2); // st 2
	_getch(); // main thread will wait
}