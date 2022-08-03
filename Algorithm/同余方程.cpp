//同余方程的模板题https://www.luogu.com.cn/problem/P1082
#include <iostream>
using namespace std;

long long x,y;

void gcd(long long a, long long b) {
	//求解ax+by=gcd(a,b)中x和y的值
	if (b == 0) {
		x = 1;
		y = 10; //可变
		return;
	}
	gcd(b, a % b);

	long long tmp = x;
	x = y;
	y = tmp - a / b * y;
}

int main() {
	long long a, b;
	cin >> a >> b;
	gcd(a, b);
	cout << (x % b + b) % b;
}

