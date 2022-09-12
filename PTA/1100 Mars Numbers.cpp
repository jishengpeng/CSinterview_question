//小模拟，注意格式问题和边缘样例（12前面是没有空格的），注意整数和字符串的转化。to_string()和stoi()很好用。
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string a[13] = { "tret","jan","feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string b[13] = { " ","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
int main() {
	int n;
	cin >> n;
	string str,str1;
	for (int i = 0; i < n; i++) {
		cin >> str;
		//cout << str << endl;
		//说明是数字
		if (str[0] <= '9' && str[0] >= '0') {
			if (str.size() == 1) {
				cout << a[str[0] - '0'] << endl;
			}
			if (str.size() == 2) {
				int sum = (str[0] - '0') * 10 + (str[1] - '0');
				int tmp1 = sum % 13;
				int tmp2 = sum / 13;
				if (tmp1 != 0) {
					cout << b[tmp2] << " " << a[tmp1] << endl;
				}
				else {
					cout << b[tmp2] <<endl;
				}

			}
			if (str.size() == 3) {
				int sum = (str[0] - '0') * 100 + (str[1] - '0')*10+(str[2]-'0');
				int tmp1 = sum % 13;
				int tmp2 = sum / 13;
				if (tmp1 != 0) {
					cout << b[tmp2] << " " << a[tmp1] << endl;
				}
				else {
					cout << b[tmp2]<< endl;
				}
			}

		}
		//说明是字母
		else {
			int flag = 0;
			for (int j = 0; j < 13; j++) {
				if (a[j] == str) {
					cout << j << endl;
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				int sum = 0;
				for (int j = 0; j < 13; j++) {
					if (b[j] == str) {
						sum += j * 13;
					}
				}
				char ji = getchar();
				if (ji == ' ') {
					cin >> str1;
					for (int j = 0; j < 13; j++) {
						if (a[j] == str1) {
							sum += j;
						}
					}
				}
				cout << sum << endl;

			}

		}
	}

	return 0;
}