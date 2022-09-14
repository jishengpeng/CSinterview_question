//这是一道建多叉树的题
//关键问题是求书的最低深度，以及最低深度有多少个
//刚开始看错问题了，其实第二个输出是让求最低深度的个数
//典型的深度优先遍历的问题，应该没啥问题
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct node {
	vector<int> tmp;
	//int istree = 0;//判断是否是根节点
}res[100010];

int resheight = INT_MAX;
int sum = 0;

void dfs(int i, int height) {
	//cout <<"当前到了"<<i<<" "<<height<<" "<<res[i].tmp.size() << endl;
	if (res[i].tmp.size() == 0) {
		if (height < resheight) {
			resheight = height;
		}
		return;
	}
	for (int j = 0; j < res[i].tmp.size(); j++) {
		height++;
		dfs(res[i].tmp[j], height);
		height--;
	}

}

void calnum(int i, int height) {
	//cout <<"当前到了"<<i<<" "<<height<<" "<<res[i].tmp.size() << endl;
	if (res[i].tmp.size() == 0) {
		//cout << "***" << height << endl;
		if (height == resheight) {
			sum++;
		}
		return;
	}
	//cout << "&&&" << endl;
	for (int j = 0; j < res[i].tmp.size(); j++) {
		height++;
		calnum(res[i].tmp[j], height);
		height--;
	}

}






int main() {
	int n;
	double p, r;
	cin >> n >> p >> r;
	int k, k1;
	for (int i = 0; i < n; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> k1;
			res[i].tmp.push_back(k1);
		}
	}

	////打印看一下
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < res[i].tmp.size(); j++) {
	//		cout << res[i].tmp[j] << " ";
	//	}
	//	cout << i << endl;
	//}

	//求最低高度
	dfs(0, 0);
	for (int i = 0; i < resheight; i++) {
		p = p + p * r / 100.0;
	}
	printf("%.4f", p);
	//计算一下最低深度的叶子节点有几个
	calnum(0, 0);
	cout << " " << sum;
	return 0;
}
