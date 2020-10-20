描述
给定两个正整数m, n(m>n)，输出m除以n的带余除法的算式。m=q*n+r（其中0<=r<n，r为0时只输出m=q*n）。

输入
输入数据仅有一行，该行有两个正整数。

输出
依次输出被除数，空格，等号，空格，商，星号，除数；若余数不为0，则继续输出空格，加号，空格，余数。最后输出换行。

样例输入1
7 2
样例输出1
7 = 3*2 + 1




#include<iostream>

using namespace std;

int main() {
    int a, b, shang, yushu;

    cin >> a >> b;

    yushu = a % b;
    shang = (a - yushu) / b;

    if (yushu == 0)
        cout << a << " = " << shang << "*" << b << endl;
    else 
        cout << a << " = " << shang << "*" << b << " + "<< yushu << endl;


    return 0;

}





描述
给定3个实数a, b, c作为3条线段的长度，判断由它们是否能构成一个三角形。

输入
输入数据仅有一行，该行有3个双精度浮点型数据。

输出
若能构成一个三角形则输出Yes，否则输出No；换行。

样例输入1
3 4 5
样例输出1
Yes




#include<iostream>

using namespace std;

int main() {
    double a, b, c;

    cin >> a >> b >> c;

    if (a + b > c && a + c > b && b + c > a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
 
    return 0;

}




描述
给定一个百分制的分数（整数），输出其对应的五级分制分数。对应关系如下：

A级：90~100，B级：80~89，C级：70~79，D级：60~69，E级：0~59。


输入
输入数据仅有一行，该行有一个百分制分数n（0≤n≤100，n为整数）。

输出
输出该百分制分数对应的五级分制分数，换行。

样例输入1
85
样例输出1
B




#include<iostream>

using namespace std;

int main() {
    int score;

    cin >> score;

    if (score <= 100 && score >= 90)
        cout << "A" << endl;
    else if (score <= 89 && score >= 80)
        cout << "B" << endl;
    else if (score <= 79 && score >= 70)
        cout << "C" << endl;
    else if (score <= 69 && score >= 60)
        cout << "D" << endl;
    else if (score <= 59 && score >= 0)
        cout << "E" << endl;

    return 0;

}





描述
给定3个浮点型数据a、b、c（a<>0)，求一元二次方程ax^2+bx+c的根。

输入
输入数据仅有一行，该行有3个双精度浮点型数据a、b、c（a<>0)。

输出
若有实根，则按根的值从小到大（即 ）输出；否则输出“无实数根”（不要输出双引号），换行。

样例输入1
1 2 -3
样例输出1
-3, 1




#include<iostream>
#include<cmath>

using namespace std;

int main() {
    double a, b, c, delta, x1, x2;

    cin >> a >> b >> c;

    delta = b * b - 4 * a * c;

    if (delta < 0) {
        cout << "无实数根" << endl;
    }

    if (delta > 0) {
        x1 = (-b - pow(delta, 0.5)) / (2 * a);
        x2 = (-b + pow(delta, 0.5)) / (2 * a);
        cout << x1 << ", " << x2 << endl;
    }

    if (delta == 0) {
        x1 = -b / (2 * a);
        cout << x1 << endl;
    }

    return 0;

}





描述
给定3个整数a、b、c，要求将它们按从小到大排序。

输入
输入数据仅有一行，该行有3个整数 。

输出
输出递增排序结果，换行。

样例输入1
6 -3 1
样例输出1
-3 1 6




#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int a, b, c;

    cin >> a >> b >> c;

    if (a <= b && b <= c && a <= c) {
        cout << a << " " << b << " " << c << endl;
    }
    else if (a <= b && a <= c && b >= c) {
        cout << a << " " << c << " " << b << endl;
    }
    else if (a <= b && a >= c && b >= c) {
        cout << c << " " << a << " " << b << endl;
    }
    else if (a >= b && b <= c && a <= c) {
        cout << b << " " << a << " " << c << endl;
    }
    else if (a >= b && a >= c && b <= c) {
        cout << b << " " << c << " " << a << endl;
    }
    else if (c <= b && b <= a && c <= a) {
        cout << c << " " << b << " " << a << endl;
    }

    return 0;

}




描述
给定一系列整数，计算其总和。

输入
输入数据有2行，第一行有一个正整数n；第二行有n个整数。

输出
输出n，及计算结果，换行。

样例输入1
5
1 2 3 4 5
样例输出1
5, 15






#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int n, i, sum;
    int num[100];

    sum = 0;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> num[i];
    }

    for (i = 0; i < n; i++) {
        sum = sum + num[i];
    }

    cout << n << ", " << sum << endl;

    return 0;
}




描述
给定一系列数据，去掉其中一个最大值、一个最小值后求平均值。

输入
输入数据仅有一行，其中有若干（大于2）个双精度浮点型数据。

输出
输出数据项数，最小值，最大值，计算结果，换行。

样例输入1
6 8 9 7 1 10 2 3 5 5
样例输出1
10, 1, 10, 5.625




#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main() {
    int sum;
    double Sum, maxnum, minnum, ave;

    double num[100];

    sum = 0;
    Sum = 0;

    while (1 ==1){
        cin >> num[sum];
        sum++;
        if (cin.get() == '\n')
            break;
    }

    for (int i = 0; i < sum; i++) {
        Sum += num[i];
    }

    minnum = *min_element(num, num+(sum));
    maxnum = *max_element(num, num+(sum));
    ave = (Sum - minnum - maxnum)/((long double)sum-2);

    cout << sum << ", " << minnum << ", " << maxnum << ", " << ave << endl;

    return 0;
}



描述
给定两个正整数a(0<a<10)和n，计算[a]+[aa]+…+[a…a]的值。例如：a为2，n为5时，则计算2＋22＋222＋2222＋22222。

输入
输入数据有若干行。每行有两个整数，分别是a（0

输出
对于每一种情形，先输出“Case #: ”（#为序号，从1起），然后输出算式及结果（结果值小于2^31,格式参见输出样例），换行。

样例输入1
2 5
3 6
1 4
样例输出1
Case 1: 2 + 22 + 222 + 2222 + 22222 = 24690
Case 2: 3 + 33 + 333 + 3333 + 33333 + 333333 = 370368
Case 3: 1 + 11 + 111 + 1111 = 1234




#include <iostream>
#include <cmath>

using namespace std;

void cal(int a, int n) {
	double res, an;

	res = 0;

	cout << a;

	for (int i = 1; i < n; i++) {
		an = 0;
		for (int l = 0; l <= i; l++) {
			an += a * pow(10, l);
		}
		cout << " + " << an;
		res += an;
	}

	res += a;
	cout << " = " << res << endl;

}

int main() {
	int exnum;
	int a[50], n[50];

	for (exnum = 1; exnum <= 50; exnum++) {
		cin >> a[exnum - 1] >> n[exnum - 1];

		cout << "Case " << exnum << ": ";
		cal(a[exnum - 1], n[exnum - 1]);
	}

	return 0;
}





描述
给定一个正整数n，计算n!的尾部0的个数。

输入
输入数据有若干行。每行上有一个正整数n，对应一种情形。

输出
对于每一种情形，先输出“Case #: ”（#为序号，从1起），然后输出n的值，逗号，结果，换行。

样例输入1
8
16
30
样例输出1
Case 1: 8, 1
Case 2: 16, 3
Case 3: 30, 7 




#include <iostream>
#include <cmath>
using namespace std;

long long cal(int a) {
	long long res, an;
	res = 0;
	for (long long i = 1; i <= a; i++) {
		an = i % 5;
		long long l = i;
		while (an == 0) {
			res++;
			l = l / 5;
			an = l % 5;
		}
	}
	//cout << res << endl;
	return res;
}

int main() {

	for (int exnum = 1; exnum <= 100; exnum++) {
		long long n, res;

		cin >> n;

		res = cal(n);

		cout << "Case " << exnum << ": " << n << ", " << res << endl;
	}

	return 0;
}




描述
对于给定的一个正整数，若该数为偶数则将其除以2，若为奇数则将其乘3再加1。反复进行上述过程，直到结果为1时停止。这就是著名的“3n+1”问题。要求对于给定的整数，求按3n+1规则变换到1所需要的数字变换次数。

输入
输入一行，有多个数据。

输出
对于每一个整数，要求先输出“Case #: ”（#为序号），然后输出读入的整数、逗号、空格、计算结果。若输入的数据为非正整数，结果为-1。

样例输入1
1024 1023 0 100 66
样例输出1
Case 1: 1024, 10
Case 2: 1023, 62
Case 3: 0, -1
Case 4: 100, 25
Case 5: 66, 27




#include <iostream>
#include <cmath>
using namespace std;

long long cal(int a) {
	long long res;
	res = 0;

    if (a == 0) {
        return -1;
    }
    else
        while (a != 1) {
            if (a % 2 == 0) {
                a = a / 2;
                res++;
            }
            else {
                a = 3 * a + 1;
                res++;
            }
        }

	return res;
}

int main() {
    long long num[100], sum, ans;

    sum = 0;

    while (1 == 1) {
        cin >> num[sum];
        sum++;
        if (cin.get() == '\n')
            break;
    }

    for (int i = 0; i < sum; i++) {
        ans = cal(num[i]);

        cout << "Case " << i+1 << ": " << num[i] << ", " << ans << endl;
    }

	return 0;
}




描述
给定一个正整数，判断其是否为素数。

输入
输入数据有若干行。每行上有一个正整数对应一种情形。

输出
对于每一种情形，先输出“Case #:”（#为序号，从1起），然后输出n，逗号，结果（参见输出样例），换行。

样例输入1
31
2
27
样例输出1
Case 1: Number 31 is prime.
Case 2: Number 2 is prime.
Case 3: Number 27 is not prime.




//time limit exceeded

#include <iostream>
#include <cmath>
using namespace std;

long long cal(int a) {
	long long res;

    res = 0;

    for (int i = 3; i < a/2; i++) {
        if (a % i == 0) {
            res++;
        }
    }

    if (res == 0 || a == 2) {
        return 0;
    }
    else if (res != 0) {
        return 1;
    }
}

int main() {

    for (int exnum = 1; exnum <= 100; exnum++) {
        long long n, res;

        cin >> n;

        res = cal(n);

        if (res == 0) {
            cout << "Case " << exnum << ": Number " << n << " is prime." << endl;
        }
        else if (res == 1) {
            cout << "Case " << exnum << ": Number " << n << " is not prime." << endl;
        }
        
    }

    return 0;
}




#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int n, exnum = 0;

    while (cin >> n) {
        int res;

        int i = 2;
        res = 0;
        exnum++;

        if (n == 1) {
            cout << "Case " << exnum << ": Number " << n << " is not prime." << endl;
            continue;
        }

        while (i <= sqrt(n)) {
            if (n % i == 0) {
                cout << "Case " << exnum << ": Number " << n << " is not prime." << endl;
                res = 1;
                break;
            }
            i++;
        }

        if (res == 0)
            cout << "Case " << exnum << ": Number " << n << " is prime." << endl;
        
    }

    return 0;
}





描述
给定一个十进制正整数，判断其是否为同构数。所谓同构数是这样的一些数，它出现在其平方数的右边，例如5是5^2=25右边的数，25是25^2=625右边的数，所以5和25都是同构数。

输入
输入数据有若干行。每行上有一个正整数，对应一种情形。

输出
对于每一种情形，先输出“Case #:”（#为序号，从1起），然后输出n，逗号，结果（Yes或No），换行。

样例输入1
5
15
25
样例输出1
Case 1: 5, Yes
Case 2: 15, No
Case 3: 25, Yes




#include <iostream>
#include <cmath>
using namespace std;

int cal(int a) {
    int res, ten, i, mid_res;
    res = 0;
    i = 1;

    for (int i = 1; i != 0; i++) {
        ten = pow(10, i);
        if (ten >= a)
            break;
    }

    //cout << ten << endl;

    mid_res = int(pow(a, 2) - a) % ten;

    if (mid_res == 0) {
        return 0;
    }
    else if (mid_res != 0) {
        return 1;
    }
}

int main() {

    int n, exnum = 0;

    while (cin >> n) {
        int res;

        res = cal(n);
        exnum++;
        //cal(n);

        if (res == 0) {
            cout << "Case " << exnum << ": " << n << ", Yes" << endl;
        }
        else if (res == 1) {
            cout << "Case " << exnum << ": " << n << ", No" << endl;
        }
    }
    return 0;
}





描述
给定两个十进制正整数，判断它们是否为亲密数对。对于两正整数a，b，若a的所有包含1但不包含自身的因子的和等于b，并且b的所有包含1但不包含自身的因子的和等于a，则称a，b为一对亲密数。例如，a=6，b=6是一亲密数对。

输入
输入数据有若干行。每行上有两个正整数，对应一种情形。

输出
对于每一种情形，先输出“Case #:”（#为序号，从1起），然后输出a，b及结果（参见输出样例），换行。

样例输入1
4 6
220 284
1210 1184
样例输出1
Case 1: 4, 6, No
Case 2: 220, 284, Yes
Case 3: 1210, 1184, Yes




#include <iostream>
#include <cmath>
#include <numeric>
using namespace std;

int cal(long a, long b) {
    int res = 0, num[2] = {0, 0}, sum_a = 0, sum_b = 0;
    long de_a[100], de_b[100];

    for (int k = 1; k < a; k++)
    {
        if (a % k == 0)
        {
            de_a[num[0]] = k;
            num[0]++;
        }
    }

    for (int k = 1; k < b; k++)
    {
        if (b % k == 0)
        {
            de_b[num[1]] = k;
            num[1]++;
        }
    }

    for (int i = 0; i < num[0]; i++) {
        sum_a += de_a[i];
        //cout << de_a[i] << " ";
    }

    //cout << endl;

    for (int i = 0; i < num[1]; i++) {
        sum_b += de_b[i];
        //cout << de_b[i] << " ";
    }

    //cout << endl;

    if (sum_a == b && sum_b == a) {
        return 1;
    }
    else {
        return 0;
    }

}

int main() {

    long a, b, exnum = 0;

    while (cin >> a >> b) {
        int res;

        res = cal(a, b);
        exnum++;
        //cal(n);

        if (res == 1) {
            cout << "Case " << exnum << ": " << a << ", " << b << ", Yes" << endl;
        }
        else if (res == 0) {
            cout << "Case " << exnum << ": " << a << ", " << b << ", No" << endl;
        }
    }
    return 0;
}




描述
对于给定的人民币金额n（分），问有多少种方案将其兑换成1分、2分、5分。

输入
输入数据有若干行。每行上有一个正整数表示以分为单位的人民币金额n，对应一种情形。

输出
对于每一种情形，先输出“Case #:”（#为序号，从1起），然后输出n，逗号，结果，换行。

样例输入1
10
100
150
样例输出1
Case 1: 10, 10
Case 2: 100, 541
Case 3: 150, 1186




#include <iostream>

using namespace std;

int cal(long a) {
    int res = 0, an = 0;
    
    for (int i = 0; i <= a / 5; i++)
    {
        an = (a - i * 5) / 2;
        res += an + 1;
    }

    return res;

}

int main() {

    long a, exnum = 0;

    while (cin >> a) {
        int res;

        res = cal(a);
        exnum++;
        //cal(n);

        cout << "Case " << exnum << ": " << a << ", " << res << endl;
    }
    return 0;
}






描述
给定两个有效正整数year及month，打印该月的日历。

输入
输入数据有若干行。每行上有两个正整数year及month对应一种情形。

输出
对于每一种情形，先输出“Case #:”（#为序号，从1起），然后输出“year年month月”，换行，“Sun Mon Tue Wed Thu Fri Sat”，换行，日历内容，换行。

样例输入1
2008 2
2009 2
2010 2
样例输出1
Case 1: 2008年2月
Sun Mon Tue Wed Thu Fri Sat
                      1   2
  3   4   5   6   7   8   9
 10  11  12  13  14  15  16
 17  18  19  20  21  22  23
 24  25  26  27  28  29 
Case 2: 2009年2月
Sun Mon Tue Wed Thu Fri Sat
  1   2   3   4   5   6   7
  8   9  10  11  12  13  14
 15  16  17  18  19  20  21
 22  23  24  25  26  27  28

Case 3: 2010年2月
Sun Mon Tue Wed Thu Fri Sat
      1   2   3   4   5   6
  7   8   9  10  11  12  13
 14  15  16  17  18  19  20
 21  22  23  24  25  26  27
 28




//wrong answer （输出问题）
#include <iostream>

using namespace std;

int len(int a, int b) {
    int i = 0;

    while (a > 0) {
        if (a % 400 == 0) {
            i = 1;
            break;
        }
        if (a % 100 == 0) {
            i = 0;
            break;
        }
        if (a % 4 == 0) {
            i = 1;
            break;
        }
        break;
    }

    if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12)
        return 31;
    else if (b == 2 && i == 1)
        return 29;
    else if (b == 2 && i == 0)
        return 28;
    else if (b == 4 || b == 6 || b == 9 || b == 11)
        return 30;

}

void cal(int y, int m) {
    int res = 0, an = 0, days = 0, leep_year = 0, first_day = 0, week_day = 0;

    cout << "Sun Mon Tue Wed Thu Fri Sat" << endl;

    while (y > 0) {
        if (y % 400 == 0) {
            leep_year = 1;
            break;
        }
        if (y % 100 == 0) {
            leep_year = 0;
            break;
        }
        if (y % 4 == 0) {
            leep_year = 1;
            break;
        }
        break;
    }

    for (int i = 1900; i < y; i++) {
        if (i % 400 == 0) {
            days += 366;
            continue;
        }
        if (i % 100 == 0) {
            days += 365;
            continue;
        }
        if (i % 4 == 0) {
            days += 366;
            continue;
        }
        days += 365;
    }

    if (leep_year == 1) { //该年为闰年
        if (m >= 2) {
            days += 31;
        }
        if (m >= 3) {
            days += 29;
        }
        if (m >= 4) {
            days += 31;
        }
        if (m >= 5) {
            days += 30;
        }
        if (m >= 6) {
            days += 31;
        }
        if (m >= 7) {
            days += 30;
        }
        if (m >= 8) {
            days += 31;
        }
        if (m >= 9) {
            days += 31;
        }
        if (m >= 10) {
            days += 30;
        }
        if (m >= 11) {
            days += 31;
        }
        if (m >= 12) {
            days += 30;
        }
    }
    else if (leep_year == 0) { //该年不是闰年
        if (m >= 2) {
            days += 31;
        }
        if (m >= 3) {
            days += 28;
        }
        if (m >= 4) {
            days += 31;
        }
        if (m >= 5) {
            days += 30;
        }
        if (m >= 6) {
            days += 31;
        }
        if (m >= 7) {
            days += 30;
        }
        if (m >= 8) {
            days += 31;
        }
        if (m >= 9) {
            days += 31;
        }
        if (m >= 10) {
            days += 30;
        }
        if (m >= 11) {
            days += 31;
        }
        if (m >= 12) {
            days += 30;
        }
    }

    first_day = 1 + days % 7;

    for (int i = 1; i <= first_day; i++) {
        if (first_day == 7)
            break;
        cout << " " << "  " << " ";
        week_day++;
    }

    int day = len(y, m);

    for (int i = 1; i <= day; i++) {
        if (week_day == 7) {
            cout << endl;
            week_day = 0;
        }

        if (i <= 9) {
            cout << "  " << i << " ";
        }
        else {
            cout << " " << i << " ";
        }
        week_day++;
    }

    cout << endl;

}

int main() {

    int a, b, exnum = 0;

    while (cin >> a >> b) {
        int res;

        exnum++;

        cout << "Case " << exnum << ": " << a << "年" << b << "月" << endl;

        cal(a, b);
    }
    return 0;
}




#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int nyear(int y)
{
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        return 366;
    else
        return 365;
}

int nmonth(int y, int m)
{
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        return 31;
    else if (nyear(y) == 366 && m == 2)
        return 29;
    else if (nyear(y) == 365 && m == 2)
        return 28;
    else
        return 30;
}
int Days(int y, int m)
{
    int i = 0;
    int sum = 0;
    if (y >= 1990)
    {
        for (i = 1990; i < y; i++)
            sum += nyear(i);

        if (m > 1)
            for (i = 1; i < m; i++)
            {
                sum += nmonth(y, i);
            }
    }
    else
    {
        for (i = 1989; i > y; i--)
            sum += nyear(i);

        for (i = 12; i >= m; i--)
        {
            sum += nmonth(y, i);
        }


    }
    return sum;
}
int main()
{
    int   year, month, i, j, k = 0, sum = 0, blank;

    while (cin >> year >> month)
    {
        cout << "Case " << ++k << ": ";
        sum = Days(year, month);
        if (year >= 1990) {
            blank = (sum + 1) % 7;
        }
        else
        {
            blank = (8 - sum % 7) % 7;
        }

        cout << year << "年" << month << "月" << endl;
        cout << "Sun Mon Tue Wed Thu Fri Sat" << endl;
        for (i = 0; i < blank; i++)
        {
            cout << setw(4) << " ";
        }
        for (i = 1, j = blank + i; i <= nmonth(year, month); i++, j++)
        {

            if (j % 7 != 0 && i != nmonth(year, month))
                cout << setw(3) << i << " ";
            else
                cout << setw(3) << i << endl;
        }

        if ((j - 1) % 7 == 0 && i == nmonth(year, month) + 1)
            cout << endl;

    }
    return 0;
}
