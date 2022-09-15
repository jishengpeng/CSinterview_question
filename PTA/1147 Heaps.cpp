//判断是否是堆，并且对完全二叉树（数组形式的）进行后序遍历
//前半部分判断是否是堆小模拟即可,后面就理解了思想之后可以直接遍历
//还是要减少依赖他人解析的思想。一道题一眼做不出来老是想着看看别人的思路，会形成思维的惰性
//一定要争取自己先想一遍，在规定时间内敲一遍，其实题目很简单
#include <iostream>
#include <vector>

using namespace std;

vector<int> res;
int a[1010];
int m, n;
void postorder(int i) {
	if (i > n) {
		return;
	}
	postorder(i * 2);
	postorder(i * 2 + 1);
	res.push_back(a[i]);
	return ;
}

int main() {
	cin >> m >> n;
	//输入树的个数
	for (int i = 0; i < m; i++) {
		res.clear();
		int flag = 3;//用来判断是大根还是小根
		for (int j = 1; j <= n; j++) {
			cin >> a[j];
		}
		for (int j = 1; j <= n / 2; j++) {
			if (2 * j <= n) {
				//如果是小根向，却出现了大的
				if (flag == 1 && a[j] > a[2 * j]) {
					flag = 3;
					cout << "Not Heap"<<endl;
					break;
				}
				//如果是大根向，却出现了小的
				if (flag == 2 && a[j] < a[2 * j]) {
					flag = 3;
					cout << "Not Heap" << endl;
					break;
				}
				if (a[j] > a[2 * j]) {
					flag = 2;
				}
				if (a[j] < a[2 * j]) {
					flag = 1;
				}
			}
			if (2 * j+1 <= n) {
				//如果是小根向，却出现了大的
				if (flag == 1 && a[j] > a[2 * j+1]) {
					flag = 3;
					cout << "Not Heap" << endl;
					break;
				}
				//如果是大根向，却出现了小的
				if (flag == 2 && a[j] < a[2 * j+1]) {
					flag = 3;
					cout << "Not Heap" << endl;
					break;
				}
				if (a[j] > a[2 * j+1]) {
					flag = 2;
				}
				if (a[j] < a[2 * j+1]) {
					flag = 1;
				}
			}

		}
		if (flag == 1) {
			cout << "Min Heap" << endl;
		}
		if (flag == 2) {
			cout << "Max Heap" << endl;
		}
		//下面用来进行后根遍历
		postorder(1);
		for (int i = 0; i < res.size() - 1; i++) {
			cout << res[i] << " ";
		}
		cout << res[res.size() - 1] << endl;


	}
	return 0;
}