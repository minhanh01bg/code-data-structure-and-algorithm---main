#include<bits/stdc++.h>
#define reset(x) memset(x,0,sizeof((x)))
#define VI vector<char>
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define TR(it, a) for(typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define run() int t;cin>>t;while(t--)
using namespace std;
map<string, int>start, endd;
string test="1238004765";
string str="";
string left(string str){
	char x = str[0];
	str[0] = str[3];
	str[3] = str[7];
	str[7] = str[8];
	str[8] = str[5];
	str[5] = str[1];
	str[1] = x;
	return str;
}

string left_ng(string str){
	char x = str[0];
	str[0] = str[1];
	str[1] = str[5];
	str[5] = str[8];
	str[8] = str[7];
	str[7] = str[3];
	str[3] = x;
	return str;
}

string right(string str){
	char x = str[1];
	str[1] = str[4];
	str[4] = str[8];
	str[8] = str[9];
	str[9] = str[6];
	str[6] = str[2];
	str[2] = x;
	return str;
}

string right_ng(string str) {
	char x = str[1];
	str[1] = str[2];
	str[2] = str[6];
	str[6] = str[9];
	str[9] = str[8];
	str[8] = str[4];
	str[4] = x;
	return str;
}

void check(string str){
	if(str==test) return;
	queue<string>F;
	F.push(str);
	while(!F.empty()){
		string k = F.front();F.pop();
		int i = start[k];
		if(!start[left(k)]){
			start[left(k)]=i+1;
			F.push(left(k));
		}
		if(!start[right(k)]){
			start[right(k)]=i+1;
			F.push(right(k));
		}
		if(start[F.back()]>=14) return;
	}
}

int check2(string str){
	if(str==test) return 0;
	queue<string>F;
	F.push(test);
	while(!F.empty()){
		string k=F.front();F.pop();
		int i = endd[k];
		if(start[k]) return start[k]+endd[k];
		if(!endd[left_ng(k)]){
			endd[left_ng(k)]=i+1;
			F.push(left_ng(k));
		}
		if(!endd[right_ng(k)]){
			endd[right_ng(k)]=i+1;
			F.push(right_ng(k));
		}
		if(endd[F.back()] >= 14) return -1;
	}
	return -1;
}
main(){
	fast()
	run(){
		char x;
		str="";
		FOR(i,0,10){
			cin>>x;
			str+=x;
		}
		start.clear();
		endd.clear();
		check(str);
		cout<<check2(str)<<endl;
	}
	return EXIT_SUCCESS;
}
