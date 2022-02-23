#include<bits/stdc++.h>
using namespace std;

#define NMAX 10000
#define MMAX 10000
 
int main(){
    int t;
    cin>>t;
    while(t--){
        
        int x[MMAX], y[MMAX], Head[NMAX+2], Adj[MMAX+1];
        int n, m, u, v;
        cin >> n >> m;
        
        for (int i=0; i<=n+1; i++)
            Head[i]=0;
        
        for (int i=1; i<=m; i++) {
            cin >> x[i] >> y[i];
            Head[x[i]]++;
        }
        
        for (int i=2; i<=n+1; i++)
            Head[i]=Head[i-1]+Head[i];
        
        for (int i=1; i<=m; i++) { 
            Adj[Head[x[i]]]=y[i];
            Head[x[i]]--;
        }
        int z[10000],k=0;
        for(int i=1;i<=n;i++){
            cout<<i<<": ";
            k=0;
            for(int j=Head[i]+1;j<=Head[i+1];j++){
               z[k]=Adj[j];
               k++; 
                
            }
            sort(z,z+k);
            for(int v=0;v<k;v++) cout<<z[v]<<" ";
            cout<<endl;
        }
    }
    
}