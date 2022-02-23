#include<bits/stdc++.h>

using namespace std;
// code by vu minh anh
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,l,r) for (int i=l;i>=r;i--)
#define BEGIN() int t;cin>>t;while(t--)
#define FAST() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long 
#define endl "\n"
#define RESET(C) memset(C,0,sizeof(C))
const ll mod=1e9+7;
int n,k;
int a[100];
bool ktr(){
    int d=0,dp[n+1]={0};
    FOR(i, 1, n){
        if(a[i]==0){
            dp[i]=dp[i-1]+1;
            dp[i-1]=0;
        }
        else dp[i]=0;
    }
    FOR(i,1,n){
        if(dp[i]==k) return true;
    }
    return false;
}
void res(){
    FOR(i,1,n){
        if(a[i]) cout<<"B";
        else cout<<"A";
    }
    cout<<endl;
}
int x=0;
void Try(int i){
    FOR(j,0,1){
        a[i]=j;
        if(i==n) {
            if(ktr()) {
                // res();
                x++;       
            }
        }
        else Try(i+1);
    }
}
void Trry(int i){
    FOR(j,0,1){
        a[i]=j;
        if(i==n) {
            if(ktr()) {
                res();
                // x++;       
            }
        }
        else Trry(i+1);
    }
}
int main(){
    FAST()
    // BEGIN(){
        cin >> n >> k;
        if(k==0) {
            FOR(i,1,n) cout<<"B";
        }
        else{
            Try(1);
            cout<<x<<endl;
            Trry(1);
        }
    // }
}