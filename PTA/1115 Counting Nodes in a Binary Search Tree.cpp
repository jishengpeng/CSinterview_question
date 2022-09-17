//考察了二叉排序树/二叉搜索树的建树过程，建树需要传入俩个值，一个是根节点，一个是当前的值，然后递归建树
//然后就是比较常见的遍历求深度和找当前层的节点个数了，dfs即可
#include <iostream>

using namespace std;

int height=0;
int sum1 = 0;//记录倒数第二层
int sum2 = 0;//记录倒数第一层



struct Node {
	int value;
	Node* left;
	Node* right;
	Node(int i) :value(i), left(NULL), right(NULL) {};
};

void dfs(Node* root,int h) {
	if (root == NULL) {
		if (h > height) {
			height = h;
		}
		return;
	}
	h++;
	dfs(root->left, h);
	dfs(root->right, h);
	h--;
}

void get(Node* root, int h) {
	//cout << "***" << h << endl;
	if (root == NULL) {
		return;
	}
	if (h == height - 1) {
		sum2++;
	}
	if (h == height - 2) {
		sum1++;
	}
	h++;
	get(root->left, h);
	get(root->right, h);
	h--;
}



Node* build(int i,Node* root) {
	if (root == NULL) {
		root = new Node(i);
		return root;
	}
	if (i <= root->value) {
		root->left = build(i, root->left);
	}
	else {
		root->right = build(i, root->right);
	}
	return root;

}

int main() {
	int n;
	cin >> n;
	int tmp;
	//建树
	Node* root=NULL;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		root = build(tmp,root);
	}
	dfs(root, 0);
	//cout << height << endl;
	get(root, 0);
	cout << sum2 << " + " << sum1 << " = " << sum1 + sum2; 


	return 0;
}