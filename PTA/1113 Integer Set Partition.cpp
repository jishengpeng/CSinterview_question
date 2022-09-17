//签到题
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[100010];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    if(n%2==0){
        cout<<0<<" ";
        int sum1=0;
        int sum2=0;
        for(int i=0;i<n/2;i++){
            sum1+=a[i];
        }
        for(int i=n/2;i<n;i++){
            sum2+=a[i];
        }
        cout<<abs(sum1-sum2)<<endl;       
    }
    else{
        cout<<1<<" ";
        int sum1=0;
        int sum2=0;
        for(int i=0;i<n/2;i++){
            sum1+=a[i];
        }
        for(int i=n/2;i<n;i++){
            sum2+=a[i];
        }
        cout<<abs(sum1-sum2)<<endl; 
        
    }
    
    return 0;
}