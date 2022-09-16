//签到题，注意性感素数是小于或者大于都可以。
#include <iostream>
#include <climits>
using namespace std;

bool prime(int i){
    if(i<=1) return false;
    for(int j=2;j*j<=i;j++){
        if(i%j==0){
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin>>n;
    if((prime(n)&&prime(n+6))||(prime(n)&&prime(n-6))){
        cout<<"Yes"<<endl;
        if(prime(n-6)){
            cout<<n-6;
        }
        else{
            cout<<n+6;
        }
    }
    else{
        cout<<"No"<<endl;
        for(int j=n+1;j<=INT_MAX;j++){
            if((prime(j)&&prime(j+6))||(prime(j)&&prime(j-6))){
                cout<<j;
                break;
            }
        }
    }
    
    return 0;

}