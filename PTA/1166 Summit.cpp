//用邻接矩阵来保存图，进行大模拟
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m,tmp3;
	cin >> n >> m;
	vector<int> res; //存每次查询的数目
	vector<int> ans;
	int isvisit[210];//判断是否是当前查询的内容；
	int tmp1,tmp2;
	int a[210][210];
	memset(a, 0, sizeof(a));
	memset(isvisit, 0, sizeof(isvisit));
	//初始化
	for (int i = 0; i < 210; i++) {
		a[i][i] = 1;
	}
	//用邻接矩阵来存储
	for (int i = 0; i < m; i++) {
		cin >> tmp1 >> tmp2;
		a[tmp1][tmp2] = 1;
		a[tmp2][tmp1] = 1;
		a[tmp1][205]++;//这个是我记录当前节点的边的数目的
		a[tmp2][205]++;
		//初始化
		if (isvisit[tmp1] == 0) {
			ans.push_back(tmp1);
			isvisit[tmp1] = 1;
		}
		if (isvisit[tmp2] == 0) {
			ans.push_back(tmp2);
			isvisit[tmp2] = 1;
		}
		
	}
	//排序
	sort(ans.begin(), ans.end());

	cin >> tmp3;
	for (int i = 1; i <= tmp3; i++) {
		res.clear();
		memset(isvisit, 0, sizeof(isvisit));
		cin >> tmp1;
		for (int j = 0; j < tmp1; j++) {
			cin >> tmp2;
			isvisit[tmp2] = 1;
			res.push_back(tmp2);
		}
		int flag = 0;
		//来进行判断，首先判断是否需要帮助
		for (int j = 0; j < tmp1; j++) {
			for (int k = 0; k < tmp1; k++) {
				if (a[res[j]][res[k]] == 0) {
					flag = 1;
					cout << "Area " << i << " needs help." << endl;
					break;
				}
			}
			if (flag == 1) {
				break;
			}
		}
		if (flag == 1) {
			continue;
		}
		//来进行判断是否有新的没有加入
		for (int j = 0; j < ans.size(); j++) {
			if (isvisit[ans[j]] == 0) {
				int flag1 = 0;
				for (int k = 0; k < tmp1; k++) {
					if (a[ans[j]][res[k]] == 0) {
						flag1 = 1;
						break;
					}
				}
				if (flag1 == 0) {
					//说明是找到了
					cout << "Area " << i << " may invite more people, such as " << ans[j] << "."<<endl;
					flag = 1;
					break;
				}

			}
		}
		if (flag == 0) {
			cout << "Area "<<i<<" is OK." << endl;
		}


	}

	return 0;
}