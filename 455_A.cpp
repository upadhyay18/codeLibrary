// ques link: https://codeforces.com/problemset/problem/455/A 
// similar to house robber problem 

#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int size=1e5+1;
    vector<long long>arr(size,0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        arr[a]++;
    }
    for(long long i=2;i<=size;i++){
        if(arr[i]>0){
            arr[i]=max(arr[i-1],i*arr[i]+arr[i-2]);
        }
        else{
            arr[i]=arr[i-1];
        }
    }
    cout<<arr[size]<<endl;
    return 0;
}