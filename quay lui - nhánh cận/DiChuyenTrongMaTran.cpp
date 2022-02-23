#include<bits/stdc++.h>
using namespace std;
int N,M;
int max(int n,int m){
    if(n==N-1||m==M-1){
        return 1;       
    }
    return max(n,m+1) + max(n+1,m);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>N>>M;
        int a[N][M];
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>a[i][j];
            }
        }
        cout<<max(0,0)<<endl;
    }
}