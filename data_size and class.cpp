// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class A
{
public:
	~A(){cout<<"A";}
};
class B
{
public:
	~B(){cout<<"B";}
};
class C:public A
{
public:
	~C(){cout<<"C";}
private:
	B b;
};

int _tmain(int argc, _TCHAR* argv[])
{
	//������������λ��
	/*
	cout<<"char:\t"<<sizeof(char)<<endl;
	cout<<"int:\t"<<sizeof(int)<<endl;
	cout<<"float:\t"<<sizeof(float)<<endl;
	cout<<"double:\t"<<sizeof(double)<<endl;
	cout<<"short:\t"<<sizeof(short)<<endl;
	cout<<"long:\t"<<sizeof(long)<<endl;
	cout<<"u int:\t"<<sizeof(unsigned int)<<endl;
	cout<<"long double:\t"<<sizeof(long double)<<endl;
	cout<<"bool:\t"<<sizeof(bool)<<endl;
	cout<<"wchar_t:\t"<<sizeof(wchar_t)<<endl;
	
	*/
	C c;
	return 0;
}

