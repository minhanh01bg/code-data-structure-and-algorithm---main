#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define EL printf("\n")
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define X  first
#define Y  second
#define fillchar(a) memset(a, 0, sizeof(a))
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)
#define run() int t;cin>>t;while(t--)
#define endl "\n"
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//code by vu minh anh

int main(){
    fast()
    run(){
        string s;
        cin>>s;
        int n=s.size();
        ll dp[n+1];
        dp[0]=s[0]-'0';
        ll res=s[0]-'0';
        FOR(i,1,n-1){
            dp[i] =(i+1)*(s[i]-'0') + dp[i-1]*10;    
            // cout<<dp[i]<<" ";
            res+=dp[i];
        }
        cout<<res<<endl;
    }
}