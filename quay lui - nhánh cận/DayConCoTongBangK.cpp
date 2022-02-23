#include<bits/stdc++.h>
using namespace std;
int b[100],a[100],n,m=0,k;
void res(){

    int sum=0;
    for(int i=0;i<n;i++){
        if(b[i]==0) sum+=a[i]; 
    }
    if(sum == k) {
        int c[100],x=0;
        cout<<"[";
        for(int i=0;i < n;i++){
            if(b[i]==0) {
                c[x++]=a[i];
            }
        }
        for(int i=0;i<x;i++){
            if(i!=x-1) cout<<c[i]<<" ";
            else cout<<c[i];
        }
        cout<<"]"<<" ";
    }
    else m++;
}
void Try(int i){
    for(int j=0;j<2;j++){
        b[i]=j;
        if(i==n-1) res();
        else Try(i+1);
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        m=0;
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        Try(0);
        if(m==pow(2,n)) cout<<-1;
        cout<<endl;
    }
}