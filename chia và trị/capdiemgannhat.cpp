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
#define spr(A) ((A)*(A))
struct PoLL { 
    LL x, y; 
}; 
#define db long double
int compareX(const void* a, const void* b) { 
    PoLL *p1 = (PoLL *)a, *p2 = (PoLL *)b; 
    return (p1->x - p2->x); 
} 
  
int compareY(const void* a, const void* b) { 
    PoLL *p1 = (PoLL *)a, *p2 = (PoLL *)b; 
    return (p1->y - p2->y); 
} 

db dist(PoLL p1, PoLL p2) { 
    return sqrt( spr(p1.x - p2.x) +  spr(p1.y - p2.y)); 
} 
  
db bruteForce(PoLL P[], int n) { 
    db min = FLT_MAX; 
    for (int i = 0; i < n; ++i) 
        for (int j = i+1; j < n; ++j) 
            if (dist(P[i], P[j]) < min) 
                min = dist(P[i], P[j]); 
    return min; 
} 
  
db min(db x, db y) { 
    return (x < y)? x : y; 
} 

db stripClosest(PoLL strip[], LL size, db d) 
{ 
    db min = d;
  
    qsort(strip, size, sizeof(PoLL), compareY); 
    for (LL i = 0; i < size; ++i) 
        for (LL j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j) 
            if (dist(strip[i],strip[j]) < min) 
                min = dist(strip[i], strip[j]); 
  
    return min; 
} 
  
db closestUtil(PoLL P[], LL n) { 
    if (n <= 3) 
        return bruteForce(P, n); 
    LL mid = n/2; 
    PoLL midPoLL = P[mid]; 
    db dl = closestUtil(P, mid); 
    db dr = closestUtil(P + mid, n - mid); 
  
    db d = min(dl, dr); 
  
    PoLL strip[n]; 
    int j = 0; 
    for (int i = 0; i < n; i++) 
        if (abs(P[i].x - midPoLL.x) < d) 
            strip[j] = P[i], j++; 
    return min(d, stripClosest(strip, j, d) ); 
} 
  
db closest(PoLL P[], int n)  { 
    qsort(P, n, sizeof(PoLL), compareX); 
    return closestUtil(P, n); 
} 
  
main() {
    FAST
    BEGIN{
        LL n;
        cin >> n;
        PoLL P[n]; 
        FOR(i,0 ,n) 
            cin>>P[i].x>>P[i].y;
        cout << setprecision(6) << fixed << closest(P, n) << endl; 
    }
    return 0; 
}