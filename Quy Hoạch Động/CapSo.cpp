#include <bits/stdc++.h>

#define ll        long long
#define pii       pair<int, int>
#define MIN       INT_MIN
#define MAX       LLONG_MAX

#define res(x)          resize(x)
#define sz()            size()
#define er              erase
#define pb              push_back
#define eleV            vector <ele>
#define all(vec)        vec.begin(), vec.end()
#define rs(A,x)         memset(A, x, sizeof(A))
#define Unique(C)       C.erase(unique(C.begin(), C.end()), C.end())
#define pq(x)           priority_queue<x>
#define neg_pq(x)       priority_queue<x, vector<x>, greater<x>>
#define vec2(C,x,y,tp)  vector<vector<tp> > C(x, vector<tp> (y, 0))

#define FOR(i, m, n)    for(int i = m; i < n; ++i)
#define FORx(i,m,n,x)   for(int i = m; i < n; i += x)
#define FORD(i, m, n)   for(int i = m; i >= n; --i)
#define get(C,a)        FOR(i, 0, a) cin >> C[i]
#define print(C,a)      FOR(i, 0, a) cout << C[i]
#define faster()        cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
#define run()           int t; cin >> t; while (t--)

using namespace std; 
/*--------------------------------------------*/

bool cmp(pair<int,int>a,pair<int,int>b){
    return a.first<b.first;
}
int main(){
    faster()
    run(){
        int n;
        cin>>n;
        int x[n],y[n];
        pair<int, int> a[n];
        for(int i=0;i<n;i++){
            cin>>a[i].first>>a[i].second;
        }
        sort(a,a+n,cmp);
        int lis[n];
        for(int i=0;i<n;i++) 
            lis[i]=1;
        int Max = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(a[i].second<a[j].first && lis[j]<lis[i]+1){
                    lis[j]=lis[i]+1;
                    Max = max(lis[j], Max);
                }    
            }
        }
        cout<<Max<<endl;
    }
}