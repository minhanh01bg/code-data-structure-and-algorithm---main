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

int k,m,n;
string s[101],str;
char a[5][5];
bool xet[5][5]={{false}};
vector<string> res;

void init(){
	cin>>k>>n>>m;
	for(int i=1;i<=k;i++) cin>>s[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) cin>>a[i][j];
	res.clear();
	str="";
}

void Try(int i, int j){
	xet[i][j]=true;
	str=str+a[i][j];
	
	for(int l=1;l<=k;l++)
		if(s[l]==str){
			res.push_back(str);
			break;
		}
		
	for(int row=i-1; row<=i+1 && row<=n; row++){ 
		for(int col=j-1; col<=j+1 && col<=m ; col++){
		    if(row>=1 && col>=1 && xet[row][col]==false)
		    	Try(row,col);
    	}
    }
    str.erase(str.length()-1);
    xet[i][j]=false;
}

main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
    	init();
    	for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				Try(i,j);
    	if(res.size()==0) cout<<-1;
    	else{
    		for(int i=0;i<res.size();i++){
    			cout<<res[i]<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}