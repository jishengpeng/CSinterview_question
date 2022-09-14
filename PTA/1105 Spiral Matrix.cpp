//暴力找n和m
//数组排序
//小模拟排数，开一个方向数组和isvisit即可
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <cmath>
using namespace std;

int b[10100][110];//用来存储最终的结果
int isvisit[10100][110];//用来表示是否访问过

bool cmp(int a, int b) {
	return a > b;
}

//得到方向数组
int c[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

int main() {
	int n;
	int a[10100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, cmp);
	//关键是找到行m1和列n1
	int m1=1, n1=1;
	int tmp = sqrt(n);
	int sum = INT_MAX;
	for (int i = 1; i <= tmp; i++) {
		for (int j = i; j <= n; j++) {
			if (i * j == n) {
				if (j - i < sum) {
					sum = j - i;
					m1 = j;
					n1 = i;
				}
			}
		}
	}
	//进行转化
	//cout << m1 << " " << n1 << endl;
	int w1 = 0, w2 = 0,fang=0;
	memset(isvisit, 0, sizeof(isvisit));
	for (int k = 0; k < n; k++) {
		b[w1][w2] = a[k];
		isvisit[w1][w2] = 1;
		//来判断下一个位置
		int w3 = w1 + c[fang][0];
		int w4 = w2 + c[fang][1];
		if (w3 >= 0 && w3 < m1 && w4 >= 0 && w4 < n1 && isvisit[w3][w4] == 0) {
			w1 = w3;
			w2 = w4;
		}
		else {
			fang = (fang + 1) % 4;
			w1 = w1 + c[fang][0];
			w2 = w2 + c[fang][1];
		}
	}

	//进行输出到最终结果
	for (int i = 0; i < m1; i++) {
		for (int j = 0; j < n1-1; j++) {
			cout << b[i][j] << " ";
		}
		cout << b[i][n1 - 1] << endl;
	}

	return 0;
}