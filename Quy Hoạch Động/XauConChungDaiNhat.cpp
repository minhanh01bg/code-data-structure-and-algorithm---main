#include <bits/stdc++.h>

 
#define FOR(i,a,b) for (int i=a; i<=b; i++)

#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define	run() int N; cin>>N; cin.ignore(); while(N--)

using namespace std;
/*--------------------------------------------------------------------------------*/
main() {
	faster()
	run() {
		string a;
		string b;
		cin>>a>>b;
		int dp[a.size()+1][b.size()+1];
		FOR(i,0,a.size()) {
			FOR(j,0,b.size()) {
				if(i==0 || j==0){
					dp[i][j]=0;
				}
				else if(a[i-1]==b[j-1]){
					dp[i][j]=dp[i-1][j-1]+1;
				}
				else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
		cout<<dp[a.size()][b.size()]<<endl;
	}
}