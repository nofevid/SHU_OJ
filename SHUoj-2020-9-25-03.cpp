/*
描述
给定一个由不同的小写字母组成的字符串，输出这个字符串的所有全排列。

我们假设对于小写字母有'a' < 'b' < ... < 'y' < 'z'，而且给定的字符串中的字母已经按照从小到大的顺序排列。

输入
输出只有一行，是一个由不同的小写字母组成的字符串，已知字符串的长度在1到6之间。

输出
输出这个字符串的所有排列方式，每行一个排列。要求字母序比较小的排列在前面。字母序如下定义： 已知S=s1s2...sk , T=t1t2...tk，则S<T 等价于，∃p(1≤p≤k)，使得 s1=t1,s2=t2,...,sp−1=tp−1,sp<tp成立。

样例输入1
abc
样例输出1
abc
acb
bac
bca
cab
cba
*/




#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int fun(int m, int n) {
	if (m == 0 || n == 1)
		return 1;
	if (m < n)
		return fun(m, m);
	else
		return fun(m, n - 1) + fun(m - n, n);
}

int main() {

	int num,i;

	int M[20];
	int N[20];

	cin >> num;

	for (i = 0; i < num; i++) {
		cin >> M[i] >> N[i];
	}

	for (i = 0; i < num; i++) {
		m = M[i];
		n = N[i];

		cout << fun(m, n);
	}

	return 0;
}
