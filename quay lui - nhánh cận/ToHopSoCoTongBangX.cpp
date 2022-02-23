#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define pb push_back
#define eb emplace_back
#define cl(C) C.clear()
#define f first
#define s second
#define cint cpp_int
#define all(C) C.begin(), C.end()
#define run() int test; cin>>test; cin.ignore(); while(test--)

#define FOR(i,a,b)                    	for (int i=a; i<=b; i++)
#define FOR2(i,a,b)                   	for (ll i=a; i<=b; ++i)
#define FORD(i,a,b) 					for (int i=a; i>=b; i--)
#define FORA(x,C) 						for (auto x:C)

#define reset(C) 						memset(C,0,sizeof(C))
#define clearQueue(C, x) 				C = queue<x> ()
#define Fill(C,a) 						fill(C.begin(), C.end(), a)


#define SORTC(C,check) 					sort(C.begin(), C.end(), check)

#define um(x,y) 				unordered_map<x,y> 
#define m(x,y) 					map<x,y> 
#define p(x,y) 					pair<x,y> 
#define us(x) 					unordered_set<x> 
#define vec(x) 					vector<x> 
#define vec2(C,x,y,token) 		vector<vector<token> > C(x, vector<token> (y, 0))
#define pq(x) 					priority_queue<x>
#define reverse_pq(x) 			priority_queue<x, vector<x>, greater<x> >

	// System

#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pause() system("pause");
using namespace std;
vector<vector<int>>sesons;
int n,k;
int a[100],d=0;
void Try(int i, int sum, vector<int>save){
    if(sum>k)   return;
    if(sum==k) {d++;sesons.push_back(save);return;}
    else {
        FOR(j,i,n-1){
            if(sum+a[i]<=k){
                save.push_back(a[j]);
                Try(j,sum+a[j],save);
                save.pop_back();
            }
        }
    }
}
main(){
    faster();
    run(){
        cin >> n >> k;
        FOR(i,0,n-1){
            cin>>a[i];
        }
        sort(a,a+n);
        vector<int> save;
        save.clear();
        sesons.clear();
        Try(0,0,save);
        if(sesons.empty()) {
            cout<<-1<<endl;
            continue;
        }
        // cout<<d<<" ";d=0;
        FOR(i,0,sesons.size()-1){
            cout<<"[";
            FOR(j,0,sesons[i].size()-1){
                if(j!=sesons[i].size()-1)
                cout<<sesons[i][j]<<" ";
                else cout<<sesons[i][j];
            }
            cout<<"]";
        }
        cout<<endl;
    }
    return EXIT_SUCCESS;
}