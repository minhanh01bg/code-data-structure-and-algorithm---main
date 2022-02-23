#include<bits/stdc++.h>
using namespace std;
int Count(int x,int b[],int m,int k[]){
    if(x==0) return 0;
    if(x==1) return k[0];
    int *p=upper_bound(b,b+m,x);
    int ans=(b+m)-p;
    ans+=(k[0]+k[1]);
    if(x==2) ans-=(k[3]+k[4]);
    if(x==3) ans+=k[2];
    return ans;
}
int mi(int a[],int b[],int n,int m){
    int k[5]={0};
    for(int i=0;i<m;i++){
        if(b[i]<5) k[b[i]]++;
    }
    sort(b,b+m);
    int total=0;
    for(int i=0;i<n;i++){
        total+=Count(a[i],b,m,k);
    }
    return total;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int a[n],b[m];
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<m;i++) cin>>b[i];
        cout<<mi(a,b,n,m)<<endl;
    }
}