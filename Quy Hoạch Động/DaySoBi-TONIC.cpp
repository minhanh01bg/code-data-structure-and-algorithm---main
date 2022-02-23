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
        int n;
        cin>>n;
        int a[n];
        FOR(i,0,n-1)
            cin>>a[i];
        int list[n];
        FOR(i,0,n-1) 
            list[i]=a[i];
        FOR(i,1,n-1)
            FOR(j,0,i)
                if(a[i] > a[j]&&list[i] < list[j]+a[i])
                    list[i]=list[j]+a[i];
        int d[n];
        FOR(i,0,n-1) d[i]=a[i];
        FORD(i,n-2,0)
            FORD(j,n-1,i+1)
                if(a[i] > a[j] && d[i] < d[j]+a[i])
                    d[i]=d[j]+a[i];
        int Max=0;
        FOR(i,0,n-1){
            Max=max(Max,list[i]+d[i]-a[i]);
        }
        cout<<Max<<endl;
    }
}