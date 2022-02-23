#include<bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define REP(i, a, b) for(int i = (a); i <=(b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define REPD(i, a, b) for(int i = (a); i >=(b); i--)
#define TR(it, a) for(typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define BEGIN int t;cin>>t;while(t--)
#define reset(x) memset(x,0,sizeof((x)))
#define SZ(a) (int((a).size()))
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
#define LL long long
#define LD long double
#define II pair<int, int>
#define X first
#define Y second
#define VI vector<int>
const int N = 100005;
using namespace std;


#define ROW 500
#define COL 500
 
int n,m;
int isSafe(int M[][COL], int row, int col,bool visited[][COL]){
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (M[row][col] && !visited[row][col]);
}

void DFS(int M[][COL], int row, int col, bool visited[][COL]){
    static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    visited[row][col] = true;
    for (int k = 0; k < 8; ++k)
        if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited))
            DFS(M, row + rowNbr[k], col + colNbr[k], visited);
}

int countIslands(int M[][COL]) {
    bool visited[ROW][COL];
    memset(visited, 0, sizeof(visited));
 
    int count = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (M[i][j] && !visited[i][j]) {
                DFS(M, i, j, visited);
                ++count;
            }
 
    return count;
}
int main() {
    FAST
    BEGIN {
        cin>>n>>m;
        int M[ROW][COL];
        char x;
        FOR(i,0,n)
            FOR(j,0,m){
                cin>>x;
                if(x=='.')
                    M[i][j]=0;
                else M[i][j]=1;
            }
        cout << countIslands(M) << "\n";
    }
    return 0;
}