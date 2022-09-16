//又是这种链的题目，模拟做一下，注意储存链的方式用map，其他就是根据题意去做即可
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Node {
	int value;
	string next;
};

int main() {
	vector<string> tmp1;
	vector<string> tmp2;
	vector<string> res;
	string str1, str2,str3,str4;
	map<string,Node> ans;
	int n,m;
	cin >> str1 >> str2 >> n;
	str3 = str1;
	str4 = str2;
	tmp1.push_back(str1);
	tmp2.push_back(str2);
	for (int i = 0; i < n; i++) {
		cin >> str1 >> m >> str2;
		Node node;
		node.value = m;
		node.next = str2;
		ans[str1] = node;
	}
	//分别放入两条链中
	while (str3 != "-1") {
		str1 = ans[str3].next;
		if (str1 != "-1") {
			tmp1.push_back(str1);
		}
		str3 = str1;
	}
	while (str4 != "-1") {
		str1 = ans[str4].next;
		if (str1 != "-1") {
			tmp2.push_back(str1);
		}
		str4 = str1;
	}
	////打印看一下
	//for (int i = 0; i < tmp1.size(); i++) {
	//	cout << tmp1[i] << " ";
	//}
	//cout << endl;
	//for (int i = 0; i < tmp2.size(); i++) {
	//	cout << tmp2[i] << " ";
	//}
	//tmp1中放短的那条队伍
	if (tmp1.size() > tmp2.size()) {
		res = tmp1;
		tmp1 = tmp2;
		tmp2 = res;
	}
	//进行合并
	res.clear();
	int len1 = tmp1.size();
	int len2 = tmp2.size();
	int k = 0;//计数用的
	int j = len1-1;//用来保存短的那条边
	for (int i = 0; i < len2; i++) {
		res.push_back(tmp2[i]);
		k++;
		if (k == 2) {
			if (j >=0 ) {
				res.push_back(tmp1[j]);
				j--;
				k = 0;
			}
		}
	}
	//进行最后的输出
	for (int i = 0; i < res.size()-1; i++) {
		cout << res[i] << " " << ans[res[i]].value << " "<<res[i + 1] << endl;
	}
	cout << res[res.size() - 1] << " " << ans[res[res.size() - 1]].value << " " << -1<<endl;


	return 0;
}