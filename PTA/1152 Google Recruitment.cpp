//签到题
#include <iostream>
#include <cmath>
using namespace std;

string str;

int get(int i, int n) {
	int sum = 0;
	//找到第一个非零的；
	while (str[i] == '0') {
		i++;
		n--;
		if (n == 0) {
			break;
		}
	}
	if (n == 0) {
		return 0;
	}
	else {
		while (n != 0) {
			sum += (str[i] - '0') * pow(10, n-1);
			i++;
			n--;  
		}
		return sum;
	}

}

bool prime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}



int main() {
	int len, n;
	cin >> len >> n;
	cin >> str;
	int flag = 0;
	for (int i = 0; i <= len - n; i++) {
		if (prime(get(i, n))) {
			flag = 1;
			cout << str.substr(i, n);
			break;
		}
	}
	if (flag == 0) {
		cout << "404";
	}

	return 0;

}