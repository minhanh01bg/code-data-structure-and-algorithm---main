#include<bits/stdc++.h>
using namespace std;
#define Nothing					"mikey"
#define run() int t;cin>>t;while(t--)
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define reset(a,b) memset(a,b,sizeof(a))
#define ll long long
int d=INT_MAX;
int f[100001];
int Try(int n){
	if(n==1) return 0;
	if(f[n]!=-1) return f[n];
	int res=Try(n-1);
	if(n%2==0) res=min(res,Try(n/2));
	if(n%3==0) res=min(res,Try(n/3));
	f[n] = 1+res;
	return f[n];
}
main(){
    faster();
    run(){
        int n;
        cin>>n;
        reset(f,-1);
        d=INT_MAX;
        cout<<Try(n);
        cout<<endl;
    }
}