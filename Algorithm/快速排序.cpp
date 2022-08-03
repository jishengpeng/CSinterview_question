//快速排序的模板题https://www.luogu.com.cn/problem/P1177
#include <iostream>
using namespace std;

int a[100100];

void kuaipai(int low,int heigh) {
    if (low >= heigh) return;
    int low1 = low;
    int heigh1 = heigh;
    int tmp = a[low];
    while (low < heigh) {
        while (low < heigh && a[heigh] >= tmp) heigh--;
        a[low] = a[heigh];
        while (low < heigh && a[low] <= tmp) low++;
        a[heigh] = a[low];
    }
    a[low] = tmp;
    kuaipai(low1, low - 1);
    kuaipai(low + 1, heigh1);

}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    kuaipai(0,n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }  
}