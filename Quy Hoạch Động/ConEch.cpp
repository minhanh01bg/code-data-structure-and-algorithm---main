#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define run() int t;cin>>t;while(t--)
#define endl "\n"
/**/
/*xem phim*/
ll dp[105];
void mi(){
    dp[1]=1,dp[2]=2,dp[3]=4;
    for(int i=4;i<=104;i++)
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];    
}
int main(){
    mi();
    run(){
        int n;
        cin >> n;
        cout<<dp[n]<<endl;   
    }
}