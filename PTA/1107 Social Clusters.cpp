//并查集加改版
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int isvisit[1010];

int father[1010];

int isvisit2[1010];

int res[1010],res1=0;

int find(int i) {
	if (father[i] == i) {
		return father[i];
	}
	else {
		father[i] = find(father[i]);
		return father[i];
	}
}

bool cmp(int a, int b) {
	return a > b;
}


int main() {
	int n,k,k1;
	cin >> n;
	//初始化
	memset(isvisit, 0, sizeof(isvisit));
	memset(isvisit2, 0, sizeof(isvisit2));
	for (int i = 0; i < 1010; i++) {
		father[i] = i;
	}

	vector<int> tmp;
	for (int i = 0; i < n; i++) {
		tmp.clear();
		cin >> k;
		char c = getchar();
		for (int j = 0; j < k; j++) {
			cin >> k1;
			tmp.push_back(k1);
			isvisit[k1] = 1;
			if (j == 0) {
				res[res1++] = k1;
			}
		}
		for (int j = 0; j < tmp.size() - 1; j++) {
			father[find(tmp[j])] = find(tmp[j + 1]);
		}
	}
	//得到总个数
	int sum = 0;
	for (int i = 1; i < 1010; i++) {
		if (isvisit[i] == 1) {
			//cout << i << " " << father[i] << endl;
			if (father[i] == i) {
				sum++;
			}
		}
	}
	cout << sum << endl;;
	//再将其路径压缩一下
	for (int i = 0; i < 1010; i++) {
		if (isvisit[i] == 1) {
			find(i);
			//cout << i << " " << father[i] << endl;
		}
	}
	//得到总个数
	for (int i = 0; i < n; i++) {
		isvisit2[father[res[i]]]++;
	}
	sort(isvisit2, isvisit2 + 1010, cmp);
	for (int i = 0; i < sum - 1; i++) {
		cout << isvisit2[i] << " ";
	}
	cout << isvisit2[sum - 1];
	


	return 0;
}