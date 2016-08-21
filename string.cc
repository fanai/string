#include<string.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;

class String
{
public:
	String();//无参构造函数
	String(const char * pstr);//普通构造函数
	String(const String & rhs);//拷贝构造函数
	~String();//析构函数
	void display();

	String & operator=(const String & rhs);
	String & operator=(const char * pstr);

	String & operator+=(const char *);
	String & operator+=(const String &);

	char & operator[](std::size_t index);
	const char & operator[](std::size_t index) const;

	std::size_t size() const;
	const char* c_str() const;

	friend bool operator==(const String &, const String &);
	friend bool operator!=(const String &, const String &);

	friend bool operator<(const String &,const String &);
	friend bool operator>(const String &,const String &);
	friend bool operator<=(const String &,const String &);
	friend bool operator>=(const String &,const String &);

	friend std::ostream & operator<<(std::ostream & os, const String & rhs);
	friend std::istream & operator>>(std::istream & is, String & rhs);
private:
	char * _pstr;
};

String::String()
{
	cout << "String()" << endl;
	_pstr = new char[1];
	bzero(_pstr, 1);
}

String::String(const char * pstr)
{
	cout << "String(const char *)" << endl;
	_pstr = new char[strlen(pstr) + 1];
	strcpy(_pstr, pstr);
}

String::String(const String & rhs)
{
	cout << "String(const String &)" << endl;
	_pstr = new char[strlen(rhs._pstr) + 1];
	strcpy(_pstr, rhs._pstr);
}

String & String::operator=(const String & rhs)
{
	if(this == &rhs)
	  return *this;
	else
	{
		cout << "String & operator=(const String &)" << endl;
		delete [] _pstr;
		_pstr = new char[strlen(rhs._pstr) + 1];
		strcpy(_pstr, rhs._pstr);
		return *this;
	}
}

String::~String()
{
	cout << "~String()" << endl;
	delete [] _pstr;
}

void String::display()
{
	cout << _pstr << endl;
}

String & String::operator=(const char * pstr)
{
	cout << "String & operator(const char *)" << endl;
	delete [] _pstr;
	_pstr = new char[strlen(pstr) + 1];
	strcpy(_pstr, pstr);
	return *this;
}

String & String::operator+=(const char * cstr)
{
	cout << "string & operator+=(const char *)" << endl;
	char * pstr = new char[strlen(cstr) + strlen(_pstr) + 1];
	bzero(pstr, sizeof(pstr));
	strcpy(pstr, _pstr);
	strcat(pstr, cstr);
	delete [] _pstr;
	_pstr = pstr;
	return * this;
}

String & String::operator+=(const String & rhs)
{
	cout << "String & operator+=(const String &)" << endl;
	operator+=(rhs._pstr);
	return * this;
}

char & String::operator[](std::size_t index)
{
	cout << "char & operator[](size_t)" << endl;
	return _pstr[index];
}

const char & String::operator[](std::size_t index) const 
{
	cout << "const char & oprrator[](size_t)" << endl;
	return _pstr[index];
}

std::size_t String::size() const
{
	return strlen(_pstr);
}

const char* String::c_str() const
{
	return _pstr;
}

bool operator==(const String & rhs1, const String & rhs2)
{
	cout << "bool operator==(const String &, const String &)" << endl;
	if(strcmp(rhs1._pstr, rhs2._pstr) == 0)
	  return true;
	else
	  return false;
}

bool operator!=(const String & rhs1, const String & rhs2)
{
	cout << "bool operator!=(const String &, const String &)" << endl;
	return !operator==(rhs1, rhs2);
}

bool operator<(const String & rhs1, const String & rhs2)
{
	cout << "bool operator<(const String &, const String &)" << endl;
	if(strcmp(rhs1._pstr, rhs2._pstr) < 0)
	  return true;
	else
	  return false;
}

bool operator>(const String & rhs1, const String & rhs2)
{
	cout << "bool operator>(const String &, const String &)" << endl;
	if(strcmp(rhs1._pstr, rhs2._pstr) > 0)
	  return true;
	else
	  return false;
}

bool operator<=(const String & rhs1, const String & rhs2)
{
	cout << "bool operator<=(const String &, const String &)" << endl;
	if(strcmp(rhs1._pstr, rhs2._pstr) <= 0)
	  return true;
	else
	  return false;
}

bool operator>=(const String & rhs1, const String & rhs2)
{
	cout << "bool operator>=(const String &, const String &)" << endl;
	if(strcmp(rhs1._pstr, rhs2._pstr) >= 0)
	  return true;
	else
	  return false;
}

std::ostream & operator<<(std::ostream & os, const String & rhs)
{
	os << rhs._pstr;
	return os;
}

std::istream & operator>>(std::istream & is, String & rhs)
{
//	string tmp(rhs.c_str());
	is >> rhs._pstr;
	return is;
}
int main(void)
{
	String str1;
	str1.display();
	String str2 = "hello, world";
	str2.display();
	String str3 = str2;
	str3.display();
	String str4 = "fanai";
	str4.display();
	str4 = str3;
	str4.display();
	str4 = "hello, fanai";
	str4.display();
	str2 += str4;
	str2.display();
	str2 += " haha";
	str2.display();
	cout << str2[1] << endl;
	cout << (str2 != str3) << endl;
	cout << (str2 >= str3) << endl;
	cin >> str1;
	cout << str1 << endl;
	return 0;
}
