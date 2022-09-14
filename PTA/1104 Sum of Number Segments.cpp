//直接三层大循环复杂度会超，所以需要找找规律
//注意特例数据点，long double,输出要Lf
//优化了一下dp数组，数组变成变量了
#include <iostream>

using namespace std;

int main() {
	long double res[100100];
	long double dp;
	int n;
	long double sum = 0.0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> res[i];
	}
	dp = res[1];
	sum = dp;
	for (int i = 2; i <= n; i++) {
		dp = dp + i * res[i];
		sum += dp;
	}

	printf("%.2Lf", sum);

	return 0;
}