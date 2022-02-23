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
#define init(n) int n;cin>>n;
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int A[100], c[100], a[100];
int n,B;
bool res(){
    int sum=0;
    FOR(i,0,n-1)
        if(A[i]==1) sum+=a[i];
    if(sum>B) return false;
    return true;
}
int Max=INT_MIN,b[100];
void Try(int i){
    FOR(j,0,1){
        A[i]=j;
        if(i==n-1) {
            if(res()){
                int x=0;
                FOR(i,0,n-1)
                    x+=(A[i]*c[i]);
                
                if(Max<x){
                    Max=x;
                    FOR(i,0,n-1){
                        b[i]=A[i];
                    }
                }
            }
        }
        else Try(i+1); 
    }
}
int main(){
    fast()
    // run(){
        cin>>n>>B;
        FOR(i, 0, n-1)
            cin >> c[i];
        FOR(i, 0, n-1)
            cin >> a[i];
        Try(0);
        cout << Max << endl;
        FOR(i, 0, n-1) cout << b[i] << " ";
    // }
}