#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        long long x=a[0],y=0;
        long long s_new=0;
        for(int i=1;i<n;i++){
            s_new=(x>y) ? x:y;
            x=y+a[i];
            y=s_new;
        }
        s_new=(x>y) ? x:y;
        cout<<s_new<<endl;
    }
}