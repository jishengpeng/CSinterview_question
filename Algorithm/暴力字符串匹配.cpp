#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

//写一个暴力算法的字符串匹配

int main() {
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	int len1 = str1.length();
	int len2 = str2.length();
	//判断主串的位置和字串的位置
	int i = 0, j = 0, k=0;//和一般的暴力不同，我这里引入了三个指针
	while (i <= len1 - len2) {
		if (j == len2) {
			cout << "能够找到";
			return 0;
		}
		else {
			if (str1[k] == str2[j]) {
				k++;
				j++;
			}
			else {
				j = 0;
				i = i + 1;
				k = i;
			}
		}
	}
	cout << "不能找到";

}
