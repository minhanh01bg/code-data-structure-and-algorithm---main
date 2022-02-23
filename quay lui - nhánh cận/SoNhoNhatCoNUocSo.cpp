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
int prime[]={2,3,5,7,11,13,17,19,23,29};
int n;
ll res;
void Try(int i,ll ans,ll Uoc){
    if(Uoc>n) return;
    if(Uoc==n) res=min(res,ans);
    for(int j=1;;j++){
        if(ans>res) break;
        ans*=prime[i];
        Try(i+1,ans,Uoc*(j+1));
    }
}
int main(){
    fast()
    run(){
        cin>>n;
        res=1e18;
        Try(0,1,1);
        cout<<res<<endl;
    }
    return EXIT_SUCCESS;
}