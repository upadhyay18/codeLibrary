// ques link: https://codeforces.com/problemset/problem/1714/G
#include<bits/stdc++.h>
using namespace std;
vector<vector<vector<int>>>adj;
vector<long long>ans,sum;
void findSum(int src,long long tot){
    sum[src]=tot;
    for(auto x:adj[src]){
        if(x[0]==src)continue;
        findSum(x[0],tot+x[1]);
    }
}
void length(int src,long long tot, vector<long long>&temp){
    ans[src]=upper_bound(temp.begin(),temp.end(),sum[src])-temp.begin();
    for(auto x:adj[src]){
        if(x[0]==src)continue;
        tot+=x[2];
        temp.push_back(tot);
        length(x[0],tot,temp);
        tot-=x[2];
        temp.pop_back();
    }
}
int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T;cin>>T;
    for(int t=1;t<=T;t++){
        adj.clear();ans.clear();
        int N;cin>>N;
        adj.resize(N+1);
        sum.resize(N+1);
        ans.resize(N+1,0);
        for(int i=2;i<=N;i++){
            int x,a,b;cin>>x>>a>>b;
            adj[x].push_back({i,a,b});
            //adj[i].push_back({x,a,b});
        }
        findSum(1,0);
        vector<long long>temp;
        length(1,0,temp);
        for(int i=2;i<=N;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}