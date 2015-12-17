#include <iostream>
#include <memory>
#include <string>
using namespace std;

#include "..\CommonLibrary\CommonLibrary.h"
#pragma comment ( lib, "..\\CommonLibrary\\Debug\\CommonLibrary.lib")

// name of the DLL is written to EXE

#include <Windows.h>
#include <conio.h>
// Application that wants to draw shapes

void LoadDLLs()
{
	WIN32_FIND_DATA fd;
	HANDLE file = ::FindFirstFile(L"*.dll", &fd);
	do
	{
		LoadLibrary(fd.cFileName);
	} while (::FindNextFile(file, &fd));
}

void main()
{ 
	LoadDLLs();

	auto& factories = ShapeFactory::GetFactories();
	for (auto factory : factories)
		cout << factory->GetName() << endl ;

	_getch();
}
// -------------------------------------------------------------------------




