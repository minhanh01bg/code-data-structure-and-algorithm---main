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
bool comp(int a,int b){
    return a>b;
}
void number(int n,int a[]){
    map<int,int>dem;
    FOR(i, 0, n)
        dem[a[i]]++;
    // FOR(i, 0, n)  
        // cout << dem[a[i]] << " ";    
    int d=INT_MIN;
    FOR(i,0,n){
        if(d<dem[a[i]]){
            d=dem[a[i]];
        }
    }
    FOR(i,0,n){
        if(dem[a[i]]!=d){
            int x=1;
            FOR(j,i+1,n){
                if(dem[a[j]]>dem[a[i]]){
                    cout<<a[j]<<" ";
                    x=0;
                    break;
                }
            }
            if(x==1) cout<<-1<<' ';
        }
        else cout<<-1<<" ";
    }
}
void maintest(){
    FAST
    BEGIN{
        int n;
        cin>>n;
        int a[n];
        FOR(i,0,n)
            cin >> a[i];
        number(n,a);   
        cout<<"\n";
    }
}
int main(){
    maintest();
    return EXIT_SUCCESS;
}