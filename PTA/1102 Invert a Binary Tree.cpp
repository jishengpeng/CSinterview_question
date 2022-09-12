//建树，层次遍历，中序遍历，反转树
//熟悉一下这种简短的建树方式，反转也很方便
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct node {
	char left;
	char right;;
};

vector<int> res;
vector<int> res2;
node a[12];

void inorder(char i) {
	if (i == '-') {
		return;
	}
	inorder(a[int(i - '0')].left);
	res.push_back(int(i - '0'));
	inorder(a[int(i-'0')].right);
}

void levelorder(char i) {
	queue<int> tmp;
	tmp.push(int(i - '0'));
	while (!tmp.empty()) {
		int tmptmp = tmp.front();
		res2.push_back(tmptmp);
		tmp.pop();
		if (a[tmptmp].left != '-') {
			tmp.push(a[tmptmp].left - '0');
		}
		if (a[tmptmp].right != '-') {
			tmp.push(a[tmptmp].right - '0');
		}
	}
}


int main() {
	int n;
	cin >> n;
	int b[12];//用来找根节点
	char root;
	memset(b, 0, sizeof(b));
	for (int i = 0; i < n; i++) {
		cin >> a[i].right;
		getchar();
		cin >> a[i].left;
		getchar();
		if (a[i].left != '-') {
			b[a[i].left - '0'] = 1;
		}
		if (a[i].right != '-') {
			b[a[i].right - '0'] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		if (b[i] == 0) {
			root = char(i + '0');
			break;
		}
	}
	inorder(root);
	levelorder(root);
	//层次
	for (int i = 0; i < res2.size()-1; i++) {
		cout << res2[i] << " ";
	}
	cout << res2[res2.size() - 1]<<endl;
	//中根
	for (int i = 0; i < res.size() - 1; i++) {
		cout << res[i] << " ";
	}
	cout << res[res.size() - 1];
	


	return 0;
}