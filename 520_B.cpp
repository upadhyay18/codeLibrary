//ques link: https://codeforces.com/problemset/problem/520/B

/* 
    Brute Force: BFS se sare value genrate karke
    Optimaize Solution: 
        like we approach this question in opposite manner-
            $ we will convert Y into X
            $ so multiply will convert into divide
            $ and subtract will convert into addtion
            $ now if X==Y means we have reached to our solution
            $ and if X become greater then Y then we can convert Y to X only by adding 1 into Y
            $ if now Y is Odd then we have to make Y even by adding one
            $ and if it is even we just have  to divide the number
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    long x,y;cin>>x>>y;
    long ans=0;
    while(x!=y){
        if(x<0 && y<0){
            ans=-1;break;
        }
        if(x>y){
            ans+=x-y;break;
        }
        ans++;
        if(y&1)
            ++y;
        else
            y/=2;
    }
    cout<<ans<<endl;
    return 0;
}