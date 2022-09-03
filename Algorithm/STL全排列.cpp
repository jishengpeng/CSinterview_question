//牛客题目地址：http://t.cn/Ai0K0hXZ

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


bool cmp(char a, char b) {
    return a < b;
}

int main() {
    char a[10];
    scanf("%s", a);
    sort(a, a + strlen(a), cmp);
    do {
        for (int i = 0; i < strlen(a); i++) {
            cout << a[i];
        }
        cout << endl;
    } while (next_permutation(a, a + strlen(a)));
    return 0;
}
