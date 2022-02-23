#include <bits/stdc++.h>

#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define X first
#define Y second
#define run() int t;cin>>t;while(t--)
#define fast(); ios_base::sync_with_stdio(0); cin.tie(0);
const ll p=1e9+7;
using namespace std;
/*--------------------------------------------------------------------------------*/
int main(){
    // fast();
    // run(){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int lis[1001]={1};
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++)
                if(a[j] < a[i] && lis[i]<lis[j]+1){
                    lis[i]=lis[j]+1;
                }
        }
        cout<<*max_element(lis,lis+n)<<endl;
    // }
}