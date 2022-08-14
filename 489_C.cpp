// Ques Link: https://codeforces.com/problemset/problem/489/C

#include<bits/stdc++.h>
using namespace std;
string minV(int m,int s){
    string ans="";
    if(s==0)
        return (m==1)?"0":"-1";
    if(m*9 <s) return "-1";
    s--;
    for(int i=1;i<m;i++){
        int val=(s<9)?s:9;
        s-=val;
        ans+=('0'+val);
    }
    ans+='0'+1+((s<8)?s:8);
    if(ans=="")return "-1";
    reverse(ans.begin(),ans.end());
    return ans;
}
string maxV(int m,int s){
    if(s==0)
        return (m==1)?"0":"-1";
    if(m*9 <s) return "-1";
    string ans="";
    ans+='0'+((s<9)?s:9);
    s-=((s<9)?s:9);

    for(int i=1;i<m;i++){
        int val=(s<9)?s:9;
        s-=val;
        ans+=('0'+val);
    }
    if(ans=="")return "-1";
    return ans;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int m,s;
    cin>>m>>s;
    cout<<minV(m,s)<<" "<<maxV(m,s)<<endl;
    return 0;
}