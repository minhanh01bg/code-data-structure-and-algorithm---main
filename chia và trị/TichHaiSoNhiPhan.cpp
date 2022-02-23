#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define X first
#define Y second
#define run() int t;cin>>t;while(t--)
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

ll chuyen(ll n,ll k){
    ll x=0,binary[1000];    
    while(n>0){
        binary[x]=n%k;
        n/=k;
        x++;
    }
    ll d=0;
    FORD(i,x-1,0) 
        d=d*10+binary[i];    
    return d;
}

ll tachso(string n,ll a[]){
    ll i=0;
    FORD(j,n.size()-1,0){
        a[i++]=(n[j]-'0');
    }
    return i;
}
ll ch(ll a[],ll n,ll k){
    ll s=0,x=0;
    FOR(i,0,n-1)
        s=s+a[i]*pow(k,i);
    
    return s;  
}
int main() {
    int t;
    cin>>t;
    while(t--){
        ll n;
        string A,B;
        cin >> A >> B;
        n=2;
        ll a[1000];
        ll b[1000];
        ll C=tachso(A,a);
        ll D=tachso(B,b);
        ll d=ch(a,C,n)*ch(b,D,n);
        cout<<d<<endl; 
    }
    return 0;
}