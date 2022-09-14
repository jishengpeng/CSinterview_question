//读懂题意，是用平方探测法来进行哈希的冲突避免
//注意平方探测法，是从刚开始的位置来依次寻找不冲突,依次加上0*0,1*1,2*2，
//一直到加到mise*mise(至于为什么到mise，就直接记吧)
//小模拟
#include <iostream>
#include <cstring>
using namespace std;
bool isprime(int w) {
    if (w == 1) return false;
    for (int i = 2; i * i <= w; i++) {
        if (w % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int mise, n, m, tmp1, tmp2;
    cin >> mise >> n >> m;
    while (!isprime(mise)) {
        mise++;
    }
    int res[10010];
    memset(res, 0, sizeof(res));
    for (int i = 0; i < n; i++) {
        cin >> tmp1;
        int flag = 0;
        for (int j = 0; j <= mise; j++) {
            int pos = (tmp1 + j * j) % mise;
            if (res[pos] == 0) {
                res[pos] = tmp1;
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            cout << tmp1 << " cannot be inserted."<<endl;
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        cin >> tmp2;
        for (int j = 0; j <= mise; j++) {
            ans++;
            int pos = (tmp2 + j * j) % mise;
            if (res[pos] == 0 || res[pos] == tmp2) {
                break;
            }
        }
    }
    printf("%.1f",ans*1.0/m);

    return 0;
}