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
int main(){
    fast()
    run(){
        int n,k;
        cin >> n >> k;
        int graph[n+1][n+1];
        int x, y;
        int ra[n+1],vao[n+1];
        memset(ra,0,sizeof(ra));
        memset(vao,0,sizeof(vao));
        FOR(i,1,k){
            cin >> x >> y;
            ra[x]++;
            vao[y]++;
        }
        bool check=false;
        FOR(i,1,n){
            if(ra[i]!=vao[i]){
                cout<<0<<endl;
                check=true;
                break;
            }
        }
        if(check) continue;
        cout<<1<<endl;
        
    }
    return EXIT_SUCCESS;
}