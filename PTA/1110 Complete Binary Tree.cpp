//建树和判断是否是完全二叉树，还需要层次遍历完全二叉树（队列）
//判断完全二叉树我写的比较麻烦
//首先存在只有右儿子无左儿子的节点不是完全二叉树
//只有左儿子无右儿子的节点个数大于一的不是完全二叉树
//层次遍历下一旦当前节点无儿子入队列，此队列中剩余的所有节点都不能有儿子
//一直卡几个点不过是由于没注意到输入可以是两位数，应该输入字符串而不是字符的...
#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
using namespace std;

struct node {
	string a, b;
}res[30];

int main() {
	int n;
	cin >> n;
	int flag = 0;
	int visit[30];
	int root = 1;
	int flag1 = 0;
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < n; i++) {
		cin >> res[i].a >> res[i].b;
		//判断是否只有一个
		if ((res[i].a == "-" && res[i].b != "-")) {
			flag = 1;

		}
		//判断有右子树无左子树的节点只能有一个
		if ((res[i].a != "-" && res[i].b == "-")) {
			flag1++;

		}
		//找根
		if (res[i].a !="-") {
			visit[stoi(res[i].a)] = 1;
		}
		if (res[i].b != "-") {
			visit[stoi(res[i].b)] = 1;
		}

	}
	//找根
	for (int i = 0; i < n; i++) {
		if (visit[i] == 0) {
			root = i;
		}
	}
	//非完全
	if (flag == 1 || flag1 > 1) {
		cout << "NO" << " " << root;
		return 0;
	}
	//进行层次遍历，顺便判断是否是完全
	queue<int> que;
	vector<int> vec;
	que.push(root);
	int kk = 1;//判断是否完全用的
	while (!que.empty()) {
		int tmp = que.front();
		que.pop();
		vec.push_back(tmp);
		if (res[tmp].a == "-" && res[tmp].b == "-") {
			kk = 0;
			continue;
		}
		else {
			if (kk == 0) {
				flag = 1;
			}
			if (res[tmp].a != "-") {
				que.push(stoi(res[tmp].a));
			}
			if (res[tmp].b != "-") {
				que.push(stoi(res[tmp].b));
			}
		}

	}
	if (flag == 1) {
		cout << "NO" << " " << root;
	}
	else {
		cout << "YES" << " " << vec[vec.size() - 1];
	}

	return 0;
}