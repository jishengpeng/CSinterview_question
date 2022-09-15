//大模拟,仔细模拟即可
//用了很多变量，尽量写注释了，代码可读性不是很好哈
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


struct node {
	string str;
	int height;
}tmp[10010];

bool cmp(node a, node b) {
	if (a.height == b.height) {
		return a.str > b.str;
	}
	else {
		return a.height < b.height;
	}
}

int main() {
	string res[10100];//用来保存每一行的结果
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> tmp[i].str >> tmp[i].height;
	}
	sort(tmp, tmp + n, cmp);
	int m1 = n / k;//正常每行m1个
	int m2 = n - (k - 1) * m1;//第一行m2个
	int ji = m2; //用来维护m2状态的中间变量
	int m3 = 0;//控制加减
	//输出第一行
	int loc = m2 / 2 + 1;
	int len = n - 1;//总的a数组到了哪个位置了
	int biaozhi = 0;//表示每一行应该变化多少
	while (ji > 0) {
		if (m3 % 2 == 0) {
			loc = loc + biaozhi;
			res[loc] = tmp[len].str;
			m3++;
			biaozhi++;
			len--;
			ji--;
		}
		else {
			loc = loc - biaozhi;
			res[loc] = tmp[len].str;
			m3++;
			biaozhi++;
			len--;
			ji--;
		}
	}
	for (int i = 1; i < m2; i++) {
		cout << res[i] << " ";
	}
	cout << res[m2] << endl;
	//输出剩余行
	for (int i = 0; i < k - 1; i++) {
		loc = m1 / 2 + 1;
		ji = m1;
		m3 = 0;
		biaozhi = 0;
		while (ji > 0) {
			if (m3 % 2 == 0) {
				loc = loc + biaozhi;
				res[loc] = tmp[len].str;
				m3++;
				biaozhi++;
				len--;
				ji--;
			}
			else {
				loc = loc - biaozhi;
				res[loc] = tmp[len].str;
				m3++;
				biaozhi++;
				len--;
				ji--;
			}
		}
		for (int j = 1; j < m1; j++) {
			cout << res[j] << " ";
		}
		cout << res[m1] << endl;
	}



}