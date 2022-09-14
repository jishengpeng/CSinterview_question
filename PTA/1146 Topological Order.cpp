//典型的拓扑排序的问题，不一样的是判断是否是拓扑序列
//关键点一是要会建图,vector<int> graph[INT_MAX];这个是正宗的邻接表存储的方式，有时会用struct
//注意用入度数组来保存每个点的入度，这个是拓扑排序的核心思想
//接下来思想就很简单了，出一个点所有以他为起点的终点的入度减一
//正常拓扑排序是开队列维护的
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


vector<int> graph[1010]; //建图用的，仔细想想这种建图，要是要存边的权值，就vector中放结构体
int indegree[1010];//用来记录每个点的入度的
int indegree1[1010];//用来保证每次判断一个序列的中间结果
vector<int> res;//用来存放最终结果
int a[1010];//用来保存题目中输入的序列
int n, m, k, tmp1, tmp2;

bool istuo() {
	for (int i = 0; i < n; i++) {
		if (indegree1[a[i]] != 0) {
			return false;
		}
		else {
			for (int j = 0; j < graph[a[i]].size(); j++) {
				indegree1[graph[a[i]][j]]--;
			}
		}
	}
	return true;
}

int main() {
	memset(indegree, 0, sizeof(indegree));
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> tmp1 >> tmp2;
		graph[tmp1].push_back(tmp2);
		indegree[tmp2]++;
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		//重新初始化一下
		for (int j = 0; j < 1010; j++) {
			indegree1[j] = indegree[j];
		}
		for (int j = 0; j < n; j++) {
			cin >> a[j];
		}
		if (!istuo()) {
			res.push_back(i);
		}
	}
	for (int i = 0; i < res.size() - 1; i++) {
		cout << res[i] << " ";
	}
	cout << res[res.size() - 1];

	return 0;

}