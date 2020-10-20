描述
给定3个线段的长度，若它们能构成一个三角形，则计算其周长和面积。要求编写一个函数实现“根据3边求三角形的面积及周长”（该函数中不允许进行I/O操作），仅被主函数调用。

输入
输入数据有若干行，每行上有3个双精度浮点型数据。

输出
对于每一种情形，先输出“Case #:”（#为序号，从1起），若能构成三角形则输出三角形的周长，逗号，面积；否则输出“不能构成三角形”，换行。

样例输入1
3 4 5
3 4 8
样例输出1
Case 1: 12, 6
Case 2: 不能构成三角形





#include <iostream>
#include <cmath>

using namespace std;

void cal(double a, double b, double c) {
	double S, C, H;

	H = (a + b + c) / 2;

	C = a + b + c;
	S = sqrt(H * (H - a) * (H - b) * (H - c));

	cout << C << ", " << S << endl;

}

int main() {
	int exnum;
	double a[100], b[100], c[100];

	for (exnum = 1; exnum <= 100; exnum++) {
		cin >> a[exnum - 1] >> b[exnum - 1] >> c[exnum - 1];

		cout << "Case " << exnum << ": ";

		if (a[exnum - 1] + b[exnum - 1] > c[exnum - 1] && a[exnum - 1] + c[exnum - 1] > b[exnum - 1] && b[exnum - 1] + c[exnum - 1] > a[exnum - 1])
			cal(a[exnum - 1], b[exnum - 1], c[exnum - 1]);
		else
			cout << "不能构成三角形" << endl;
	}
	return 0;
}





描述
给定一元二次方程的3个系数，计算其根。要求编写一个函数实现“根据3个系数求其可能的两个实根”（该函数中不允许进行I/O操作），仅被主函数调用。

输入
输入数据有若干行，每行上有3个双精度浮点型数据分别是二次项系数(不为0)、一次项系数和常数项。

输出
对于每一种情形，先输出“Case #:”（#为序号，从1起），若该方程有实数根则按根从小到大输出x1，逗号，x2；否则输出“无实数根”，换行。

样例输入1
1 2 -3
1 2 3
样例输出1
Case 1: -3, 1
Case 2: 无实数根





#include <iostream>
#include <cmath>

using namespace std;

void cal(double a, double b, double c) {
	double delta, x1, x2;

	delta = b * b - 4 * a * c;

	if (delta < 0) {
		cout << "无实数根" << endl;
	}

	if (delta > 0) {
		x1 = (-b - pow(delta, 0.5)) / (2 * a);
		x2 = (-b + pow(delta, 0.5)) / (2 * a);
		if (x1 < x2)
			cout << x1 << ", " << x2 << endl;
		else
			cout << x2 << ", " << x1 << endl;
	}

	if (delta == 0) {
		x1 = -b / (2 * a);
		cout << x1 << endl;
	}
}


int main() {
	int exnum;
	double a[100], b[100], c[100];

	for (exnum = 1; exnum <= 100; exnum++) {
		cin >> a[exnum - 1] >> b[exnum - 1] >> c[exnum - 1];

		cout << "Case " << exnum << ": ";

		cal(a[exnum - 1], b[exnum - 1], c[exnum - 1]);
	}
	return 0;
}





描述
给定多项式p(x)=a_n x^n + a_{n-1} x ^ {n-1} + \ldots + a_1 x + a_0 的各系数，且满足p(0)p(1)<0，根据连续函数的性质可知方程p(x)=0在区间[0,1] 之间至少有一个根。用二分法求该方程在区间[0,1]之间的一个根，要求误差不超过\epsilon < 10 ^{-8}。

输入
输入数据有若干行，每行上有若干（个数不超过20）个双精度浮点型数据，它们分别是a_n,a_{n-1},\cdot,a_1,a_0
输出
对于每一种情形，先输出“Case #:”（#为序号，从1起），结果，换行。

样例输入1
-1 2.5 -1
1 2 3 0 -5
样例输出1
Case 1: 0.5
Case 2: 0.933458




描述
给定一个布雷矩阵：矩阵的元素为0（表示此处无地雷）与1（表示此处有地雷）。根据布雷矩阵计算各个位置周围（一般为九宫格）所布雷的数量。要求①编写一个函数计算各位置周围地雷的数目；②编写一个函数输出计算结果；③编写主函数调用上述两个函数。

输入
输入数据有若干种情形，每一种情形对应一个矩阵（有若干行及若干列，行数及列数均不超过100），两个矩阵之间有一空行。

输出
对于每一种情形，先输出“Case #:”（#为序号，从1起），换行，输出结果矩阵（数据之间空1格，行尾无空格），换行。

样例输入1
0 1 1 1
1 0 1 0
0 1 0 0

1 0 0 1
0 1 0 0
0 0 1 1
1 1 0 0
样例输出1
Case 1:
2 4 4 3
3 5 5 3
2 3 2 1
Case 2:
2 2 2 1
2 3 4 3
3 4 4 2
2 3 3 2





#include<iostream>
#include<vector>
using namespace std;

int situation[103][103];
int lines = 1, column, cnt;
int matrixcolumn;
bool flag = false;

void printsituation() {
    cout << "Case " << ++cnt << ":" << endl;
    for (int i = 1; i <= lines - 1; i++) {
        for (int j = 1; j < matrixcolumn; j++) {
            cout << situation[i][j] << " ";
        }
        cout << situation[i][matrixcolumn] << endl;
    }
}

void endinputline() {
    flag = true;
    matrixcolumn = column;
    column = 0;
    lines++;

}

void endsituation() {
    flag = false;

    printsituation();
    for (int i = 0; i <= 102; i++) {
        for (int j = 0; j <= 102; j++) {
            situation[i][j] = 0;
        }
    }
    lines = 1;
    column = 0;
    matrixcolumn = 0;
}

void inputmine(int inputm) {
    flag = false;
    ++column;
    if (inputm == 0)return;
    situation[lines][column]++;
    situation[lines - 1][column]++;
    situation[lines + 1][column]++;
    situation[lines][column - 1]++;
    situation[lines][column + 1]++;
    situation[lines - 1][column - 1]++;
    situation[lines + 1][column - 1]++;
    situation[lines - 1][column + 1]++;
    situation[lines + 1][column + 1]++;
}

int main() {
    char inputc;
    while (1) {
        inputc = getchar();
        if (inputc == ' ')continue;
        switch (inputc) {
        case '\n':
            if (!flag)endinputline();
            else endsituation();
            break;
        case EOF:
            printsituation();
            return 0;
            break;
        case '0':
            inputmine(0);
            break;
        case '1':
            inputmine(1);
            break;
        }
    }
}





描述
给定两个已经按照从小到大排序的数组，将它们归并成从小到大排序的一个数组。要求编写一个函数完成归并操作。

输入
输入数据有若干种情形，每一种情形对应两行分别表示已经排序的两个整型数组。每行的数据个数不超过100，字符总数不超过1000。

输出
对于每一种情形，先输出“Case #:”（#为序号，从1起），输出结果，换行。

样例输入1
1 2 5 8 9 10 12 21 31
1 3 4 6 7 12
0 1 10 50
5 25 50
样例输出1
Case 1: 1 1 2 3 4 5 6 7 8 9 10 12 12 21 31
Case 2: 0 1 5 10 25 50 50





#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int sum = 0; int n; int num[1000000];
	int t = 0;
	while (cin >> n) {
		num[t] = n; t += 1;
		if (cin.get() == '\n')
			break;
	}
	sort(num, num + t);
	cout << "Case " << ++sum << ":";
	for (int i = 0; i <= t - 1; i++)
		cout << " " << num[i];
	cout << endl;
	return 0;
}





描述
给定一系列整数，用快速排序法将它们按照从小到大排序。可以使用标准函数qsort()。

输入
输入数据有若干行，每一行有若干个整数对应一种情形。每种情形的数据个数不超过65536，每行总字符数不超过1048576。

输出
对于每一种情形，先输出“Case #:”（#为序号，从1起），输出排序结果，换行。

样例输入1
5 3 4 8 9 1 2 10 12 21 31 1 6 7 12
0 1 10 50 5 25 50
样例输出1
Case 1: 1 1 2 3 4 5 6 7 8 9 10 12 12 21 31
Case 2: 0 1 5 10 25 50 50





#include <iostream>
using namespace std;
int merge(int arr_1[], int len_1, int arr_2[], int len_2, int arr_3[])
{
	int i = 0, j = 0, k = 0, min, len_3 = len_1 + len_2;
	while (k < len_3) {
		if ((arr_1[i] <= arr_2[j] && i < len_1) || j >= len_2) {
			min = arr_1[i];
			i++;
		}
		else if ((arr_2[j] < arr_1[i] && j < len_2) || i >= len_1) {
			min = arr_2[j];
			j++;
		}
		arr_3[k] = min;
		k++;
	}
	return 0;
}
int main()
{
	int arr_a[100], arr_b[100], arr_c[200];
	int i = 0, j = 0, k = 0, a = 0, c = 1, num = 0;
	while (cin >> num)
	{
		arr_a[i] = num;
		i++;
		while (cin.get() != '\n')
		{
			cin >> arr_a[i];
			i++;
		}
		cin >> arr_b[j];
		j++;
		while (cin.get() != '\n')
		{
			cin >> arr_b[j];
			j++;
		}
		merge(arr_a, i, arr_b, j, arr_c);
		k = i + j;
		cout << "Case" << " " << c << ":";
		while (a < k)
		{
			cout << " " << arr_c[a];
			a++;
		}
		cout << endl;
		i = 0;
		j = 0;
		a = 0;
		c++;
	}
	return 0;
}





描述
给定一个十进制正整数，将其转换成指定的进制形式。

输入
输入数据有若干行，每一行有两个正整数n,m（其中m≤36）对应一种情形。

输出
对于每一种情形，先输出“Case #:”（#为序号，从1起），输出正整数n的m进制表示形式。36进制的基数依次为0,1,…,9,A,B,…,Z（大写）。

样例输入1
100 2
100 20
101 36
样例输出1
Case 1: 1100100
Case 2: 50
Case 3: 2T




#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main()
{
	int num, sys, remind, i = 0, j = 0, k = 0, exnum = 1;
	while (cin >> num >> sys)
	{
		string num_1, num_2;
		while (num / sys >= 1)
		{
			remind = num % sys;
			num = num / sys;
			if (remind >= 10)
			{
				num_2 = 65 + remind - 10;
				num_1 += num_2;
			}
			else
			{
				num_2 = 48 + remind;
				num_1 += num_2;
			}
		}
		if (num >= 10)
		{
			num_2 = 65 + num - 10;
			num_1 += num_2;
		}
		else
		{
			num_2 = 48 + num;
			num_1 += num_2;
		}
		while (j < 50)
		{
			if (num_1[j] == '\0')
			{
				k = j - 1;
				break;
			}
			j++;
		}
		cout << "Case " << exnum << ": ";
		for (; k >= 0; k--)
		{
			cout << num_1[k];
		}
		cout << endl;
		j = 0; k = 0; exnum++;
	}
	return 0;
}





描述
给定任意两个高精度正整数a及b，计算a与b的乘积。

输入
输入数据有若干行，每行上有两个用字符串表示的正整数。字符串的长度及运算结果均不超过65536字符。

输出
对于每一种情形，先输出“Case #:”（#为序号，从1起），然后输出a*b=及结果，换行。

样例输入1
12345 6788466
345 66
样例输出1
Case 1: 12345*6788466=83803612770
Case 2: 345*66=22770





