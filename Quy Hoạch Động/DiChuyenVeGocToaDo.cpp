#include<bits/stdc++.h>

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define REP(i, a, b) for(int i = (a); i <=(b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define REPD(i, a, b) for(int i = (a); i >=(b); i--)
#define TR(it, a) for(typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define BEGIN int t;cin>>t;while(t--)
#define reset(x) memset(x,0,sizeof((x)))
#define SZ(a) (int((a).size()))
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
#define LL long long
#define LD long double
#define II pair<int, int>
#define X first
#define Y second
#define VI vector<int>
const int N = 100005;
using namespace std;
/*--------------------------------------------*/
int main(){
    FAST
    BEGIN{
        int n,m;
        cin>>n>>m;
        LL dp[n+1][m+1];
        REP(i,0,n){
            REP(j,0,m){
                if(i==0||j==0){
                    dp[i][j]=1;
                }
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        cout<<dp[n][m]<<endl;
    }
    return 0;
}