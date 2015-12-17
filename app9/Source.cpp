#include <string>
#include <iostream>
#include <functional>
#include <vector>
#include <mutex>
#include <algorithm>
#include <thread>
using namespace std;

#include <Windows.h>

//string s; // ascii
//wstring s; // unicode

template<typename T>
class Event : public vector < function<T> >
{
	mutex m;
public:
	void Register(function<T> func)
	{
		lock_guard<mutex> lg(m);
		push_back(func);
	}
};

class Search // subject
{
public:
	Event<void(wstring)> FileFound;
	Event<void(wstring, wstring)> Exception;

	void SearchFile(const wchar_t *filename)
	{
		WIN32_FIND_DATA fd;
		HANDLE file = ::FindFirstFile(L"c:\\lg\\*.*", &fd);
		do
		{
			if (wcscmp(fd.cFileName, filename) == 0)
			{
				wstring str;
				str.append(L"c:\\lg\\");
				str.append(fd.cFileName);
				for (auto& func : FileFound)
					func(str);
			}
			else
			{
				for (auto& func : Exception)
					func(fd.cFileName, L" x ");
			}
		} while (::FindNextFile(file, &fd));
	}

	void Start(const wchar_t *filename) // MT
	{
		thread st ( [filename,this]() { this->SearchFile(filename);  });
	}

	void Stop()
	{
	}
};

class Window // observer
{
	Search s;
public:
	Window()
	{
		s.FileFound.Register(bind(&Window::Receive1, this, placeholders::_1));
		s.FileFound.Register(bind(&Window::Receive2, this, placeholders::_1));

		s.Exception.Register(bind(&Window::Exception1, this, placeholders::_1, placeholders::_2));
		s.Exception.Register(bind(&Window::Exception2, this, placeholders::_1, placeholders::_2));
	}

	void Receive1(wstring folder)
	{
		wcout << "Receive1: " << folder << endl;
	}
	void Receive2(wstring folder)
	{
		wcout << "Receive2: " << folder << endl;
	}


	void Exception1(wstring folder, wstring reason)
	{
		wcout << "Exception1: " << folder << " " << reason << endl;
	}
	void Exception2(wstring folder, wstring reason)
	{
		wcout << "Exception2: " << folder << " " << reason << endl;
	}


	void StartButtonClick()
	{
		s.Start(L"data.txt"); // MT
	}

	void StopButtonClick()
	{
		s.Stop();
	}
};

void main() // MT
{
	Window g;
	g.StartButtonClick(); // mT
}