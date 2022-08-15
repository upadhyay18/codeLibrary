// ques link:https://codeforces.com/problemset/problem/580/C
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<int>cats;
int dfs(int src,int cnt,int & m){
    //cout<<src<<" "<<cnt<<endl;
    if(cnt<0){
        return 0;
    }
    if(adj[src].size()==1 && cats[adj[src][0]]==2)return 1;
    int ans=0;
    cats[src]=2;
    for(auto x:adj[src]){
        if(cats[x]==2)continue;
        int temp=(cats[x])?cnt-1:m;
        ans+=dfs(x,temp,m);
    }
    return ans;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    cats.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>cats[i];
    }
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int cnt=(cats[1])?m-1:m;
    cout<<dfs(1,cnt,m)<<endl;
    return 0;
}