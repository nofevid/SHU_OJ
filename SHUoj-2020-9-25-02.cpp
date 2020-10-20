/*
描述
给出一个正整数a，要求分解成若干个正整数的乘积，即a=a1∗a2∗a3∗...∗an，并且1<a1≤a2≤a3≤...≤an，问这样的分解的种数有多少。注意到a=a也是一种分解

输入
第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个正整数a (1<a<32768)
输出
n行，每行输出对应一个输入。输出应是一个正整数，指明满足要求的分解的种数

样例输入1
2
2
20
样例输出1
1
4
*/




#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int sum;

void count(int a, int b)
{
	for (int i = a; i < b; i++)
	{
		if (b % i == 0 && i <= b / i)
		{
			sum++;
			count(i, b / i);//递归计算
		}
		if (i > b / i) break;
	}
}
int main()
{
	int n;
	int a;

	cin >> n;
	while (n)
	{
		sum = 1;
		cin >> a;
		count(2, a);
		cout << sum << endl;
		n--;
	}
	return 0;
}
