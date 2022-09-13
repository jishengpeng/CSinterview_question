//完全是一个DFS的问题，只不过需要进行两次剪枝，一次是每次遍历到什么值即可，另一次是当前值超过n时结束递归
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, k, p;

int cal(int i, int j) {
	int sum = 1;
	for (int w = 0; w < j; w++) {
		sum *= i;
	}
	return sum;
}


vector <int> res;
int res1 = 0;
vector <int> res2;

void dfs(int i, int tmp, int num) {
	if (tmp > n || i > k) {
		return;
	}
	if (i == k) {
		if (tmp == n) {
			int sum = 0;
			for (int j = 0; j < res.size(); j++) {
				sum += res[j];
			}
			if (sum > res1) {
				res1 = sum;
				res2 = res;
			}
		}
		return;
	}
	else {
		for (int j = num; j >= 1; j--) {
			res.push_back(j);
			dfs(i + 1, tmp + cal(j, p), j);
			res.pop_back();
		}
	}
	return;
}

int main() {
	cin >> n >> k >> p;
	dfs(0, 0, int(pow(n, 1.0 / p)) + 1);
	if (res2.size() == 0) {
		cout << "Impossible";
	}
	else {
		cout << n << " " << "=";
		for (int i = 0; i < res2.size() - 1; i++) {
			cout << " " << res2[i] << "^" << p << " " << "+";
		}
		cout << " " << res2[res2.size() - 1] << "^" << p;
	}

}