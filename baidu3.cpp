/*
���������ַ������жϵڶ����ַ����Ƿ�Ϊ��һ���ַ������Ӵ����ַ����п��ܰ�������
*/
#include "stdafx.h"
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

bool Find(const string& a, const string& b)
{
	if (strstr(a.c_str(), b.c_str()) == NULL)
		return 0;
	else
		return 1;
}

int main()
{
	string a, b;
	cin >> a >> b;
	int n = b.size();
	int flag = 1;
	for (int i = 0; i<n; ++i)
	{
		string tmp;
		tmp += b[i];
		if ((b[i] & 0x1000) == 0x1000)
		{
			++i;
			tmp += b[i];
		}
		if (Find(a, tmp) == 0)
		{
			flag = 0;
			break;
		}
	}
	cout << flag << endl;
	return 0;
}
