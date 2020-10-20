描述
给出两幅相同大小的黑白图像（用0-1矩阵）表示，求它们的相似度。

说明：若两幅图像在相同位置上的像素点颜色相同，则称它们在该位置具有相同的像素点。两幅图像的相似度定义为相同像素点数占总像素点数的百分比。

输入
第一行包含两个整数m和n，表示图像的行数和列数，中间用单个空格隔开。1 <= m <= 100, 1 <= n <= 100。 之后m行，每行n个整数0或1，表示第一幅黑白图像上各像素点的颜色。相邻两个数之间用单个空格隔开。 之后m行，每行n个整数0或1，表示第二幅黑白图像上各像素点的颜色。相邻两个数之间用单个空格隔开。

输出
一个实数，表示相似度（以百分比的形式给出），精确到小数点后两位。

样例输入1
3 3
1 0 1
0 0 1
1 1 0
1 1 0
0 0 1
0 0 1
样例输出1
44.44




//二维数组sb
#include <iostream>
#include <iomanip>

using namespace std;

double cal(double a, double b) {
	int img1[100][100], img2[100][100];
	double res, sum = 0;

	for (int i = 0; i < b; i++) {
		for (int j = 0; j < a; j++) {
			cin >> img1[i][j];
		}
	}

	for (int i = 0; i < b; i++) {
		for (int j = 0; j < a; j++) {
			cin >> img2[i][j];
		}
	}

	for (int i = 0; i < b; i++) {
		for (int j = 0; j < a; j++) {
			if (img1[i][j] == img2[i][j]) {
				sum++;
			}
		}
	}

	res = 100 * (sum / (a * b));

	return res;
}

int main() {
	double len, wid, res;

	cin >> wid >> len;

	res = cal(len, wid);

	cout << setiosflags(ios::fixed) << setprecision(2) << res << endl;
}




//一维数组nb
#include <iostream>
#include <iomanip>

using namespace std;

double cal(double a, double b) {
	int img1[10000], img2[10000];
	double res, sum = 0, num;

	num = a * b;

	for (int i = 0; i < num; i++) {
		cin >> img1[i];
	}

	for (int i = 0; i < num; i++) {
		cin >> img2[i][j];
	}

	for (int i = 0; i < num; i++) {
		if (img1[i] == img2[i]) {
			sum++;
		}
	}

	res = 100 * (sum / num);

	return res;
}

int main() {
	double len, wid, res;

	cin >> wid >> len;

	res = cal(len, wid);

	cout << setiosflags(ios::fixed) << setprecision(2) << res << endl;
}




描述
输入一个整数矩阵，计算位于矩阵边缘的元素之和。所谓矩阵边缘的元素，就是第一行和最后一行的元素以及第一列和最后一列的元素。

输入
第一行分别为矩阵的行数m和列数n（m < 100，n < 100），两者之间以一个空格分开。 接下来输入的m行数据中，每行包含n个整数，整数之间以一个空格分开。

输出
输出对应矩阵的边缘元素和

样例输入1
3 3
3 4 1
3 7 1
2 0 1
样例输出1
15




#include <iostream>
#include <iomanip>

using namespace std;

long int cal(int a, int b) {
	int ori[100][100];
	long int res = 0, sum = 0;

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cin >> ori[i][j];
		}
	}

	if (a == 1 && b == 1) {
		sum = ori[0][0];
	}
	else if (a == 1 && b != 1) {
		for (int i = 0; i < b; i++) {
			sum += ori[0][i];
		}
	}
	else if (b == 1 && a != 1) {
		for (int i = 0; i < a; i++) {
			sum += ori[i][0];
		}
	}
	else if (a != 1 && b != 1) {
		for (int i = 0; i < a; i++) {
			res += ori[i][0];
		}
		for (int i = 0; i < a; i++) {
			res += ori[i][b-1];
		}
		for (int j = 0; j < b; j++) {
			res += ori[0][j];
		}
		for (int j = 0; j < b; j++) {
			res += ori[a-1][j];
		}
		sum = res - ori[0][0] - ori[0][b-1] - ori[a-1][0] - ori[a-1][b-1];
	}

	return sum;
}

int main() {
	int len, wid;
	long int res;

	cin >> wid >> len;

	res = cal(wid, len);

	cout << res << endl;
}




描述
给定n*n由0和1组成的矩阵，如果矩阵的每一行和每一列的1的数量都是偶数，则认为符合条件。

你的任务就是检测矩阵是否符合条件，或者在仅改变一个矩阵元素的情况下能否符合条件。

"改变矩阵元素"的操作定义为0变成1或者1变成0。

输入
输入n + 1行，第1行为矩阵的大小n(0 < n < 100)，以下n行为矩阵的每一行的元素，元素之间以一个空格分开。

输出
如果矩阵符合条件，则输出OK； 如果矩阵仅改变一个矩阵元素就能符合条件，则输出需要改变的元素所在的行号和列号，以一个空格分开。 如果不符合以上两条，输出Corrupt。

样例输入1
4
1 0 1 0
0 0 0 0
1 1 1 1
0 1 0 1
样例输出1
OK
样例输入2
4
1 0 1 0
0 0 1 0
1 1 1 1
0 1 0 1
样例输出2
2 3
样例输入3
4
1 0 1 0
0 1 1 0
1 1 1 1
0 1 0 1
样例输出3
Corrupt





#include <iostream>
#include <iomanip>

using namespace std;

void cal(int a) {
	int ori[100][100], sign_1 = 0, sign_2 = 0, sum_1 = 0, sum_2 = 0, x, y;
	long int res = 0;

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			cin >> ori[i][j];
		}
	}

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			if (ori[i][j] == 1) {
				sum_1++;
			}
		}
		if (sum_1 % 2 != 0) {
			sign_1++;
			x = i;
		}
		sum_1 = 0;
	}

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			if (ori[j][i] == 1) {
				sum_2++;
			}
		}
		if (sum_2 % 2 != 0) {
			sign_2++;
			y = i;
		}
		sum_2 = 0;
	}

	if (sign_1 == 0 && sign_2 == 0) {
		cout << "OK" << endl;
	}
	else if (sign_1 == sign_2 && sign_1 == 1) {
		cout << x+1 << " " << y+1 << endl;
	}
	else {
		cout << "Corrupt" << endl;
	}
}

int main() {
	int n;
	long int res;

	cin >> n;

	cal(n);

}








描述
扫雷游戏是一款十分经典的单机小游戏。它的精髓在于，通过已翻开格子所提示的周围格地雷数，来判断未翻开格子里是否是地雷。

现在给出n行m列的雷区中的地雷分布，要求计算出每个非地雷格的周围格地雷数。

注：每个格子周围格有八个：上、下、左、右、左上、右上、左下、右下。

输入
第一行包含两个整数n和m，分别表示雷区的行数和列数。1 <= n <= 100, 1 <= m <= 100。 接下来n行，每行m个字符，‘*’表示相应格子中是地雷，‘？’表示相应格子中无地雷。字符之间无任何分隔符

输出
n行，每行m个字符，描述整个雷区。若相应格中是地雷，则用‘*’表示，否则用相应的周围格地雷数表示。字符之间无任何分隔符。

样例输入1
3 3
*??
???
?*?
样例输出1
*10
221
1*1




#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

char map[102][102] = { {"?"},{"?"} }, out_map[100][100];

void mine(int x, int y) {
	int sum = 0;

	if (map[x + 1][y + 1] == '*')
		sum++;
	if (map[x + 1][y] == '*')
		sum++;
	if (map[x + 1][y - 1] == '*')
		sum++;
	if (map[x][y + 1] == '*')
		sum++;
	if (map[x][y - 1] == '*')
		sum++;
	if (map[x - 1][y + 1] == '*')
		sum++;
	if (map[x - 1][y] == '*')
		sum++;
	if (map[x - 1][y - 1] == '*')
		sum++;

	cout << sum;
}

void cal(int a, int b) {
	int sign_1 = 0, sign_2 = 0, sum_1 = 0, sum_2 = 0, x, y;
	long int res = 0;

	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			cin >> map[i][j];
		}
	}


	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			if (map[i][j] == '*') {
				cout << "*";
			}
			else {
				mine(i, j);
			}
		}
		cout << endl;
	}
}

int main() {
	int len, wid;
	long int res;

	cin >> wid >> len;

	cal(wid, len);

}






描述
CSL喜欢爬楼梯，他可以每次走1级或者2级，输入楼梯的级数，求不同的走法数。

例如：楼梯一共有3级，他可以每次都走1级，或者第一次走1级，第二次走2级。也可以第一次走2级，第二次走1级，一共3种方法。

输入
输入包含若干行，每行包含一个正整数N，代表楼梯级数，
1<=N<=30
输出
不同的走法数，每一行输入对应一行输出

样例输入1
5
8
10
样例输出1
8
34
89
