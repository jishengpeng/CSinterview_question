//签到题
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n;
    int a[100010];
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = n; i >= 1; i--) {
        if (a[i] > i) {
            cout << i;
            return 0;
        }
    }
    cout << 0 << endl;

    return 0;
}