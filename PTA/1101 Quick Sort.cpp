//这道题首先要是正确的话，位置一定在排序的位置。并且左边的一定都得比他小，
//维护一个当前最大值就行
//注意0的格式输出，很烦
//这道题用素数筛选法的思想，可以过90%的用例，暴力可以过70%

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int a[100010],b[100010];
    vector <int> res;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a,a+n);
    int sum=0;
    int max=0;
    for(int i=0;i<n;i++){
        if(a[i]==b[i]&&b[i]>max){
            sum++;
            res.push_back(b[i]);
        }
        if(b[i]>max){
            max=b[i];
        }
    }
    if(sum==0){
        cout<<0<<"\n"<<"\n";
        return 0;
    }
    cout<<sum<<endl;
    for(int i=0;i<sum-1;i++){
        cout<<res[i]<<" ";
    }
    cout<<res[sum-1];   
    return 0;
}