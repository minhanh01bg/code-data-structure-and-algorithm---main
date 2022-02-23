#include <bits/stdc++.h>
using namespace std;
vector<int> List[200005];
int n, dep[200005];
long long dp[200005], sub[200005];

void dfs(int x){
    dp[x] = dep[x];
	sub[x] = 1;
	for(auto &i : List[x]){
		dfs(i);
		dp[x] += dp[i];
		sub[x] += sub[i];
	}
}

main(){
	int i,x; cin>>n;
	for(i=2; i<=n; i++){
		int x;cin>>x;
		List[x].push_back(i);
		dep[i] = dep[x] + 1;
	}
	dfs(1);
	for(i=1; i<=n; i++)
		printf("%lld ", dp[i] - sub[i] * (dep[i] - 1));
}