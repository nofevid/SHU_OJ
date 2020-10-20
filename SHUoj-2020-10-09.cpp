描述
1742年6月7日哥德巴赫写信给当时的大数学家欧拉，正式提出了以下的猜想：任何一个大于9的奇数都可以表示成3个质数之和。质数是指除了1和本身之外没有其他约数的数，如2和11都是质数，而6不是质数，因为6除了约数1和6之外还有约数2和3。需要特别说明的是1不是质数。

这就是哥德巴赫猜想。欧拉在回信中说，他相信这个猜想是正确的，但他不能证明。

从此，这道数学难题引起了几乎所有数学家的注意。哥德巴赫猜想由此成为数学皇冠上一颗可望不可及的“明珠”。

现在请你编一个程序验证哥德巴赫猜想。

先给出一个奇数n，要求输出3个质数，这3个质数之和等于输入的奇数。

输入
仅有一行，包含一个正奇数n，其中 9 < n < 20000。

输出
仅有一行，输出3个质数，这3个质数之和等于输入的奇数。相邻两个质数之间用一个空格隔开，最后一个质数后面没有空格。如果表示方法不唯一，请输出第一个质数最小的方案，如果第一个质数最小的方案不唯一，请输出第一个质数最小的同时，第二个质数最小的方案。

样例输入1
2009
样例输出1
3 3 2003





#include <iostream>
using namespace std;

inline int prime(int n)
{
    int i;
    for (i = 2; i < n; i++)
    {
        if (n % i == 0)break;
    }
    if (i == n) return true;
    else return false;
}

int main()
{
    int n, num1, num2, num3;
    cin >> n;
    for (num1 = 2; num1 < n; num1++)
    {
        if (prime(num1) == true)
            for (num2 = 2; num2 < n; num2++)
            {
                if (prime(num2) == true)
                    num3 = n - num2 - num1;
                if (prime(num3) == true)
                {
                    cout << num1 << " " << num2 << " " << num3 << endl;
                    return 0;
                }
            }
    }
}




描述
因为 151 既是一个质数又是一个回文数（从左到右和从右到左是看一样的），所以 151 是回文质数。

写一个程序来找出范围 [a,b]（5≤a<b≤100,000,000）间的所有回文质数。

输入
两个整数 a 和 b。

输出
输出一个回文质数的列表，一行一个。

样例输入1
5 500
样例输出1
5
7
11
101
131
151
181
191
313
353
373
383




//time limit exceeded
#include <iostream>
#include <math.h>
using namespace std;

void cal(int a, int b) {
	int num = a, prime = 1;

	while (num >= a && num <= b) {
		int weishu = 0;

		for (int i = 2; i <= sqrt(num); i++) {
			if (num % i == 0) {
				prime = 0;
				break;
			}
		}

		if (prime == 0) {
			prime = 1;
			num++;
			continue;
		}
		else if (prime == 1) {
			int i = num;
			while (i > 0) {
				i /= 10;
				weishu++;
			}

			//cout << weishu << endl;

			i = num;

			int newnum = 0;
			if (i == 5 || i == 7) {
				cout << num << endl;
			}
			else {
				while (i > 0) {
					newnum = 10 * newnum + i % 10;
					i /= 10;
				}

				if (num == newnum) {
					cout << num << endl;
				}
			}
		}
		num++;
	}
}

int main() {
	int a, b;

	while (cin >> a >> b) {
		if (a >= 5 && b < 100000000 && a < b) {
			cal(a, b);
		}
		else
			continue;
	}
}





//pass
#include <iostream>

using namespace std;

bool prime(int n)
{
	bool x; int i;
	for (i = 3; i * i <= n; i = i + 2)
		if (n % i == 0)
			return false;
	return true;
}

int main()
{
	int a, b, num; bool res;
	cin >> a >> b;
	if (a % 2 == 0) {
		for (num = a + 1; num <= b; num = num + 2)
		{
			if (num >= 5 && num < 1000 || num>10000 && num < 100000 || num>1000000 && num < 10000000) {

				int i, newnum = 0;
				i = num;
				while (i != 0) {
					newnum = newnum * 10 + i % 10;
					i = i / 10;
				}
				if (newnum == num)
				{

					res = prime(num);
					if (res == true)
						cout << num << endl;
				}
			}
		}
	}
	else {
		for (num = a; num <= b; num = num + 2)
		{
			if (num >= 5 && num < 1000 || num>10000 && num < 100000 || num>1000000 && num < 10000000) {

				int i, newnum = 0;
				i = num;
				while (i != 0) {
					newnum = newnum * 10 + i % 10;
					i = i / 10;
				}
				if (newnum == num)
				{
					res = prime(num);
					if (res == true)
						cout << num << endl;
				}

			}
		}
	}
}





描述
我们要求找出具有下列性质数的个数（包含输入的正整数）:

先输入一个正整数 n（n≤1000），然后对此正整数按照如下方法进行处理：

不作任何处理；
在它的左边加上一个正整数，但该正整数不能超过原数的一半；
加上数后，继续按此规则进行处理，直到不能再加正整数为止。
输入
一个正整数 n（n≤1000）。

输出
一个整数，表示具有该性质数的个数。

样例输入1
6
样例输出1
6





描述
已知 n 个整数 x1，x2，…，xn​，以及1个整数k（k len）。从n个整数中任选k个整数相加，可分别得到一系列的和。例如当 n=4，k=3，4个整数分别为 3，7，12，19 时，可得全部的组合与它们的和为：

3+7+12=22
3+7+19=29
7+12+19=38
3+12+19=34
现在，要求你计算出和为素数共有多少种。

例如上例，只有一种的和为素数：3+7+19=29。

输入
n k（1≤n≤20,0≤k≤n） x1 x2 ... xn（1≤xi≤5000000）

输出
一个整数（满足条件的种数）。

样例输入1
4 3
3 7 12 19
样例输出1
1





描述
 “叮铃铃铃”，随着高考最后一科结考铃声的敲响，三年青春时光顿时凝固于此刻。毕业的欣喜怎敌那离别的不舍，憧憬着未来仍毋忘逝去的歌。1000多个日夜的欢笑和泪水，全凝聚在毕业晚会上，相信，这一定是一生最难忘的时刻！

为了把毕业晚会办得更好，老师想要挑出默契程度最大的k个人参与毕业晚会彩排。可是如何挑呢？老师列出全班同学的号数1，2，……，n，并且相信k个人的默契程度便是他们的最大公约数（这不是迷信哦~）。这可难为了他，请你帮帮忙吧！

PS：一个数的最大公约数即本身。

输入
两个空格分开的正整数 n 和 k。（1≤k≤n≤1,000,000,000）

输出
一个整数，为最大的默契值。

样例输入1
4 2
样例输出1
2





#include <iostream>

using namespace std;

int main() {
	int n, k, res;

	cin >> n >> k;
	res = n / k;
	cout << res;

}
