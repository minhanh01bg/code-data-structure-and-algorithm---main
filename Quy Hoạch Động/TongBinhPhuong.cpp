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
int dp[10001];
void dinamic(){
    dp[0]=0;
    FOR(i,1,10001) dp[i]=i;
    FOR(i,3,10000){
        FOR(j,1,sqrt(i)){
            dp[i] = min(dp[i],dp[i-j*j]+1);
        }
    }
}
int main(){
    fast()
    dinamic();
    run(){
        int n;
        cin>>n;
        cout<<dp[n]<<endl;
    }
    return EXIT_SUCCESS;
}