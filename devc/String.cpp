#include<string.h>
#include<iostream>
#include<Windows.h>
using namespace std;
class String
{
	char *str1;
public:
	String()
	{
	}
	String (const char *s)
	{
		str1 = new char[strlen(s) + 1];
		strcpy(str1, s);
	}
	String(const String &y)
	{
		str1 = new char[strlen(y.str1) + 1];
		strcpy(str1, y.str1);
	}
	~String()
	{
		delete []str1;
		str1=NULL;
	}
	String& operator = (const String &y)
	{
		if(strcmp(str1,y.str1)==0)
		return *this;
		delete[]str1;
		str1 = new char[strlen(y.str1) + 1];
		strcpy(str1, y.str1);
		return *this;
	}
	
	String operator +(String &y)
	{
		String temp;
		temp.str1 = new char[strlen(str1) + strlen(y.str1) + 1];
		strcat(temp.str1,str1);
		strcat(temp.str1, y.str1);
		return temp;
	}
	friend ostream& operator<<(ostream &out,const String &y);
	friend istream& operator>>(istream &in,const String &y);
	char operator[](size_t i)
	{
		return str1[i];
	}
};
ostream& operator<<(ostream &out,const String &y)
	{
		out<<y.str1;
		return out;
	}
istream& operator>>(istream &in,const String& y)
{
	
	in>>y.str1;
	return in;
}

int main()
{
	String st1("world");
	String st2("hello");
	String st3;
	st3=st2+st1;
	//cin>>st1;
	
	cout<<st3<<endl;
	cout<<st2[2]<<endl;
	cout << st1 << endl;
	cout << st2 << endl;
	//return 0;
	system("pause");
}
