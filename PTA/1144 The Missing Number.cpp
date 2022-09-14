//签到题
#include <iostream>
#include <cstring>
using namespace std;

int a[100100];

int main(){
    int n,k;
    cin>>n;
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++){
        cin>>k;
        if(k>0&&k<100100){
            a[k]=1;
        }
    }
    for(int i=1;i<100100;i++){
        if(a[i]==0){
            cout<<i;
            break;
        }
    }
    return 0;
}