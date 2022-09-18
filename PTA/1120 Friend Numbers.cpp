//签到题
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int get(int n){
    int sum=0;
    while(n!=0){
        int tmp=n%10;
        sum+=tmp;
        n=n/10;
    }
    return sum;
}

int main(){
    int n;
    int a[40];
    int tmp;
    cin>>n;
    vector<int> res;
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++){
        cin>>tmp;
        a[get(tmp)]++;        
    }
    for(int i=0;i<40;i++){
        if(a[i]>0){
            res.push_back(i);
        }
    }
    cout<<res.size()<<endl;
    for(int i=0;i<res.size()-1;i++){
        cout<<res[i]<<" ";
    }
    cout<<res[res.size()-1];
    return 0;
}