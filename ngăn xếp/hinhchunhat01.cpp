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
#include <bits/stdc++.h>
using namespace std;
 
// Rows and columns in input matrix
#define R 500
#define C 500
 
int A[R][C];
int n,m;
int maxHist(int row[]) {
    stack<int> result;
    int top_val; 
    int max_area = 0;
    int area = 0;
    int i = 0;
    while (i < m) {
        if (result.empty() || row[result.top()] <= row[i])
            result.push(i++);
 
        else {
            top_val = row[result.top()];
            result.pop();
            area = top_val * i;
 
            if (!result.empty())
                area = top_val * (i - result.top() - 1);
            max_area = max(area, max_area);
        }
    }
    while (!result.empty()) {
        top_val = row[result.top()];
        result.pop();
        area = top_val * i;
        if (!result.empty())
            area = top_val * (i - result.top() - 1);
        max_area = max(area, max_area);
    }
    return max_area;
}

int maxRectangle(int A[500][500]) {
    int result = maxHist(A[0]);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (A[i][j])
                A[i][j] += A[i - 1][j];
        result = max(result, maxHist(A[i]));
    }
    return result;
}


void printMaxSubSquare(int M[500][500]) {
    int i,j;
    int S[n][m];
    int max_of_s, max_i, max_j;
    
    for(i = 0; i < n; i++)
        S[i][0] = M[i][0];
     
    for(j = 0; j < m; j++)
        S[0][j] = M[0][j];
         
    for(i = 1; i < n; i++) {
        for(j = 1; j < m; j++) {
            if(M[i][j] == 1)
                S[i][j] = min(S[i][j-1],min( S[i-1][j], S[i-1][j-1])) + 1;
            else
                S[i][j] = 0;
        }
    }
    max_of_s = S[0][0]; max_i = 0; max_j = 0;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(max_of_s < S[i][j]) {
                max_of_s = S[i][j];
            }
        }            
    }
    cout<<max_of_s<<endl;
}
 
int main()
{
    faster();
    run(){
        cin>>n>>m;
        FOR(i,0,n-1)
            FOR(j,0,m-1) cin>>A[i][j];
        printMaxSubSquare(A);
    }
    return 0;
}
/*
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef unsigned long long ull;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define EL printf("\n")
#define sz(A) (int) A.size()
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
#define fillchar(a,x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 100005;
int n, m, a[N], h[N], L[N], R[N], ans;
stack<int> st;

int main() {
    int t; cin>>t;
    while(t--){
    	scanf("%d%d", &n,&m);
    	FOR(i,1,n) {
    		FOR(j,1,m) scanf("%d", &a[j]);
    		FOR(j,1,m)
    		h[j] = a[j] == 1 ? h[j] + 1 : 0;
    
    		st = stack<int> {};
    		FOR(j,1,m) {
    			while (! st.empty() && h[j] <= h[st.top()]) st.pop();
    			L[j] = st.empty() ? 1 : st.top() + 1;
    			st.push(j);
    		}
    
    		st = stack<int> {};
    		FOD(j,m,1) {
    			while (! st.empty() && h[j] <= h[st.top()]) st.pop();
    			R[j] = st.empty() ? m : st.top() - 1;
    			st.push(j);
    		}
    
    		FOR(j,1,m)
    		ans = max(ans, h[j] * (R[j] - L[j] + 1));
    	}
    
    	printf("%d\n", ans);
    	FOR(i,1,25000) {
    	    h[i]=0;
    	    R[i]=0;
    	    L[i]=0;
    	}    
    	ans=0;
    }   

	return 0;
}*/