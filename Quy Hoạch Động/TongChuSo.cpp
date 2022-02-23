#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define BEGIN() int t;cin>>t;while(t--)
#define FAST() ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long 
#define endl "\n"
//mikey
int dp[901][8101];
int table(int a, int b){ 
    if (a > b || a < 0 || b < 0 || a > 900 || b > 8100)
        return -1;
    if (a == 0 && b == 0)
        return 0;
    if (dp[a][b] != -1)
        return dp[a][b];
    int ans = 101; 
    for (int i = 9; i >= 1; i--) {
        int k = table(a - i, b - (i * i)); 
        if (k != -1)
            ans = min(ans, k + 1);
    }
    return dp[a][b] = ans;
}

void res(int a,int b){
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0; 
    int k = table(a,b); 
    if (k == -1 || k > 100)
        cout << "-1";
    else {
        while (a > 0 && b > 0) {
            FOR(i,1,9) {
                if (a >= i && b >= i * i && 
                    1 + dp[a - i][b - i * i] == dp[a][b]) {
                    cout << i;
                    a -= i;
                    b -= i * i;
                    break;
                }
            }
        }
    }
}
int main(){
	FAST()
    BEGIN(){
        int a,b;
		cin>>a>>b;
		res(a,b);
		cout<<endl;
	}
	return 0;
}