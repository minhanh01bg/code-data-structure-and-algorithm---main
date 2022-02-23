#include<bits/stdc++.h>
using namespace std;
#define run() int t;cin>>t;while(t--)
int b[100];int n, k;int a[100];
void sinh(){
    int i=k-1;
    while(i>=0&& b[i] == n-k+i+1) i--;
    if(i>=0){
        b[i]++;
        for(int j=i+1;j<k;j++)
            b[j]=b[i]-i+j;
    }
    else return;
}
void out(){
    int x=0;
    int c[n+1];
    for(int i=1;i<=n;i++) c[i]=0;
    for(int i=0;i<k;i++) 
        c[b[i]]++;
    for(int i=0;i<k;i++){
        if(c[a[i]]==0) x++;
    }
    if(x==0) cout<<k;
    else cout<<x;
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    run() {
        
        cin >> n >> k;
        
        for(int i=0;i<k;i++) {
            cin>>a[i];
            b[i]=a[i];
        }
        sinh();
        out();
    }
    return 0;
}