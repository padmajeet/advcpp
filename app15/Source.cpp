#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Reader // Component
{
public:
	virtual string Read() = 0;
};

class ReaderDecorator : public Reader // Decorator is a Component
{
protected:
	Reader *r_; // Decorate has component
protected:
	ReaderDecorator(Reader *r) : r_(r)
	{
	}
};

class File : public Reader
{
	string filename_;
public:
	File(const string &filename) : filename_(filename)
	{
	}

	string Read() override
	{
		ifstream ifs(filename_);

		string line;
		ifs >> line;

		ifs.close();

		return line;
	}
};

class Compress : public ReaderDecorator
{
public:
	Compress(Reader *r) : ReaderDecorator(r) {  }
	string Read()
	{
		string str = "Compressed " + r_->Read();
		return str;
	}
};

class Logger : public ReaderDecorator
{
public:
	Logger(Reader *r) : ReaderDecorator(r) {  }
	string Read()
	{
		string str = "Logger " + r_->Read();
		return str;
	}
};

class Encrypt : public ReaderDecorator
{
public:
	Encrypt(Reader *r) : ReaderDecorator(r) {  }
	string Read()
	{
		string str = "Encrypted " + r_->Read();
		return str;
	}
};
// Compress as an algorithm
//
//class CompressedFile : public File
//{
//public:
//	CompressedFile(const string& filename) : File(filename){} 
//	string Read()
//	{
//		return "Compressed " + File::Read();
//	}
//};
//
//
//class EncryptedFile : public File
//{
//public:
//	EncryptedFile(const string& filename) : File(filename){}
//	string Read()
//	{
//		return "EncryptedFile " + File::Read();
//	}
//};
//
//class EncryptCompress : public  CompressedFile, public EncryptedFile
//{
//	string Read()
//	{
//		return CompressedFile::Read() + " " + EncryptedFile::Read();
//	}
//};
//
//class EncryptedFile : public File
//{
//public:
//	EncryptedFile(const string& filename) : File(filename){}
//	string Read()
//	{
//		return "EncryptedFile " + File::Read();
//	}
//};

//void F1()
//{
//	File f("c:\\lg\\data1.txt");
//	cout << f.Read() << endl  ;
//}
//
//void F2()
//{
//	CompressedFile f("c:\\lg\\data1.txt");
//	cout << f.Read() << endl;
//
//
//
//}
//
//void F3()
//{
//	EncryptedFile f("c:\\lg\\data1.txt");
//	cout << f.Read() << endl;
//}
//
//void F4()
//{
//	EncryptedFile f("c:\\lg\\data1.txt");
//	cout << f.Read() << endl;
//}

void main()
{
	File f1("c:\\lg\\data1.txt");

	File f2("c:\\lg\\data2.txt");

	Compress c1(&f2);
	cout << c1.Read() << endl;

	//Compress c2(&f2);
	//cout << c2.Read() << endl;

	Encrypt e1(&c1);
	cout << e1.Read() << endl;

	Encrypt e2(&f2);
	cout << e2.Read() << endl;

	Compress c3(&e2);
	cout << c3.Read() << endl;
}