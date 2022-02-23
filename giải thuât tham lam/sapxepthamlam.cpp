#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define EL printf("\n")
#define OK printf("OK")
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define X  first
#define Y  second
#define fillchar(a,x) memset(a, x, sizeof(a))
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)
const int p = 1e9;
#define run() int t;cin>>t;while(t--)
#define fast(); ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
int main(){
    fast();
    run(){
        int n;
        cin>>n;
        int a[n],b[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
            b[i]=a[i];
        }
        sort(b,b+n);
        int x=0;
        for(int i=0;i<n;i++){
            if(b[i]!=a[i] && a[i]!=b[n-1-i]){
                x=1;
                break;
            }
        }
        if(x==0) cout<<"Yes";
        else cout<<"No";
        cout<<endl;
    }
}