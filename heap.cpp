// heap.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
/*
*	Ĭ����less<int>() ���ѣ�greter<int>()��С��
*	greter<int>()������ #include <functional>
*	make_heap�Ȱ����� #include <algorithm>
*/
int _tmain(int argc, _TCHAR* argv[])
{
	int a[9]={5,99,2,3,4,8,9,3,5};
	vector<int> v(a,a+9);
	cout<<v.front()<<endl;

	make_heap(v.begin(),v.end(),greater<int>());
	cout<<v.front()<<endl;

	pop_heap(v.begin(),v.end(),greater<int>());
	v.pop_back();
	cout<<v.front()<<endl;
	
	v.push_back(100);
	push_heap(v.begin(),v.end(),greater<int>());
	cout<<v.front()<<endl;

	return 0;
}

