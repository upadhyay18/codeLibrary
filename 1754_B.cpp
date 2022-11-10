#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n/2;i++)
            cout<<(i+n/2)<<" "<<i<<" ";
        if(n&1)cout<<n;
        cout<<endl;
    }
    return 0;
}