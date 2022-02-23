#include<bits/stdc++.h>
#define run() int t;cin>>t;while(t--)
#define ll long long
#define endl "\n"
#define FOR(i,l,r) for(int i=l;i<=r;i++)
using namespace std;

map<ll,bool>d;
int u[10];
ll res;
vector<int>a;
//sinh nhi phan 
void Try(int i,int n){
    for(int j=0;j<=1;j++){
        u[i]=j;
        if(i==n-1){
            // tim ket qua
            ll ans=0;
            for(int l=0;l<n;l++){
                if(u[l]==1) ans=10*ans+a[l];
            }
            if(d[ans] == true && ans!=0 && res < ans) 
                res=ans;
        }
        else Try(i+1,n);
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    for(ll i=1;i<=500000;i++){
        d[i*i*i]=true;
    }

    run(){  
        ll n;
        cin >> n;
        a.clear();
        while(n){
            a.push_back(n%10);
            n/=10;
        }
        reverse(a.begin(),a.end());
        res=-1;
        Try(0,a.size());
        cout<<res;
        cout<<endl;
    }
}