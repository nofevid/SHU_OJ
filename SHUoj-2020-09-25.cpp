#include <iostream>
#include <iomanip>
#include <math.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;




/*
描述
形如a3=b3+c3+d3的等式被称为完美立方等式。例如123=63+83+103 。编写一个程序，对任给的正整数N(N≤100)，寻找所有的四元组(a,b,c,d)，使得a3=b3+c3+d3，其中a,b,c,d 大于 1, 小于等于N，且b≤c≤d。

输入
一个正整数N(N≤100)
输出
每行输出一个完美立方。输出格式为： Cube = a, Triple = (b,c,d) 其中a,b,c,d所在位置分别用实际求出四元组值代入。 请按照a的值，从小到大依次输出。当两个完美立方等式中a的值相同，则b值小的优先输出、仍相同则c值小的优先输出、再相同则d值小的先输出。

样例输入1
24
样例输出1
Cube = 6, Triple = (3,4,5)
Cube = 12, Triple = (6,8,10)
Cube = 18, Triple = (2,12,16)
Cube = 18, Triple = (9,12,15)
Cube = 19, Triple = (3,10,18)
Cube = 20, Triple = (7,14,17)
Cube = 24, Triple = (12,16,20)
*/




int A() {
	int a, b, c, d, N;

	cin >> N;

	if (N <= 100) {
		for (a = 6; a <= N; a++) {
			for (b = 2; b <= a; b++) {
				for (c = b; c <= a; c++) {
					for (d = c; d <= a; d++) {
						if (a*a*a == b*b*b + c*c*c + d*d*d) {
							cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")" << endl;
						}
					}
				}
			}
		}
	}

	return 0;
}



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






int B() {
	int n, i, a, b, m;

	int num[50];
	int NUM[50];

	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> num[i];
	}

	for (i = 0; i < n; i++) {
		b = num[i];
		m = 0;
			for (a = 2; a < b; a++) {
				while (b != i)
				    if (b % a == 0) {
					     m = m + 1;
					     b = b / a;
				    }
				    else break;
		    }

		m = pow(2, m);
		NUM[i] = m;
	}
	
	for (i = 0; i < n; i++) {
		cout << NUM[i] << endl;
	}

	return 0;
}





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
int C()
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






int fun(int m, int n) {
	if (m == 0 || n == 1)
		return 1;
	if (m < n)
		return fun(m, m);
	else
		return fun(m, n - 1) + fun(m - n, n);
}

int D() {

	int num,i;

	int M[20], m;
	int N[20], n;

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




/*
描述
把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？（用K表示）5，1，1和1，5，1 是同一种分法。

输入
第一行是测试数据的数目t（0≤t≤20）。以下每行均包含二个整数M和N，以空格分开。1≤M，N≤10。

输出
对输入的每组数据M和N，用一行输出相应的K。

样例输入1
1
7 3
样例输出1
8
*/






int fun_2(int m,int n){
	if(m==0||n==1)
		return 1;
	if(m <n)
		return fun(m,m);
	else
		return fun(m,n-1)+fun(m-n,n);	
}
 
int E(){
	int m,n;//m个苹果 n个盘子 
	scanf("%d%d",&n,&m);
	printf("%d",fun(m,n));
	return 0;
}





/*
描述
火车从始发站（称为第1站）开出，在始发站上车的人数为a，然后到达第2站，在第2站有人上、下车，但上、下车的人数相同，因此在第2站开出时（即在到达第3站之前）车上的人数保持为a人。从第3站起（包括第3站）上、下车的人数有一定规律：上车的人数都是上两站上车人数之和，而下车人数等于上一站上车人数，一直到终点站的前一站（第n-1站），都满足此规律。现给出的条件是：共有n个车站，始发站上车的人数为a，最后一站下车的人数是m（全部下车）。试问x站开出时车上的人数是多少？

输入
一行，包含四个整数a，n，m和x，相邻两个整数之间用单个空格隔开。0≤a≤10, 3≤x<n≤15, 0≤m≤10000。 题目保证数据有唯一解。允许有人在同一站上下车。

输出
一个整数，为从x站开出时车上的人数。

样例输入1
5 7 32 4
样例输出1
13
*/





/*
描述
农夫约翰在去年赚了一大笔钱！他想要把这些钱用于投资，并对自己能得到多少收益感到好奇。已知投资的复合年利率为R（0到20之间的整数）。约翰现有总值为M的钱（100到1,000,000之间的整数）。他清楚地知道自己要投资Y年（范围0到400）。请帮助他计算最终他会有多少钱，并输出它的整数部分。数据保证输出结果在32位有符号整数范围内。

输入
一行包含三个整数R，M，Y，相邻两个整数之间用单个空格隔开。

输出
一个整数，即约翰最终拥有多少钱（整数部分）。

样例输入1
5 5000 4
样例输出1
6077
提示
在样例中：第1年后：1.05*5000=5250，第2年后：1.05*5250=5512.5，第3年后：1.05*5512.5=5788.125；

第4年后：1.05*5788.125=6077.53125         6077.53125的整数部分为：6077
*/






int F() {
	float R, Y;
	long double M;

	cin >> R >> M >> Y;

	if (R > 0 && R < 20 && Y>0 && Y < 400 && M>100 && M < 1000000) {
		M = M * pow((R / 100 + 1), Y);
	}

	cout << floor(M);

	return 0;
}





int G()
{
int n,m,a,b,c,s2,s3,i;double s1;
cin>>a>>m>>n;
s1=m;
for(i=1;i<=n;i=i+1)
{
s1=s1*(1+a*1.0/100);
}
s2=floor(s1);
cout<<s2;
}


int main(){
	A();
	B();
	C();
	D();
	E();
	F();
	G();

	return 0;
}