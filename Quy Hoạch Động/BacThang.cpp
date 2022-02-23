#include <bits/stdc++.h>

#define ll long long

#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define	run() int N; cin>>N; cin.ignore(); while(N--)
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 

#define reset(C) memset(C,0,sizeof(C))

// Namespaces
 /*--------------------------------------------------------------------------------*/
using namespace std;
int mod = 1e9+7;
main() {
	faster()
	run() {
		int n,k;
		cin>>n>>k;
		ll dp[n+1];
		reset(dp);
		dp[1] = 1;
		dp[0] = 1;
		FOR(i,2,n){
			FOR(j,1,min(i,k)){
				dp[i]+=(dp[i-j]%mod);
				dp[i] %=mod;
			}
		}
		cout<<dp[n]<<endl;
	}
	return EXIT_SUCCESS;
}