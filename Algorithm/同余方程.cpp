//ͬ�෽�̵�ģ����https://www.luogu.com.cn/problem/P1082
#include <iostream>
using namespace std;

long long x,y;

void gcd(long long a, long long b) {
	//���ax+by=gcd(a,b)��x��y��ֵ
	if (b == 0) {
		x = 1;
		y = 10; //�ɱ�
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

