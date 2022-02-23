// #include <bits/stdc++.h>

// #define ll long long
// #define ull unsigned long long
// #define pb push_back
// #define eb emplace_back
// #define cl(C) C.clear()
// #define f first
// #define s second
// #define cint cpp_int
// #define all(C) C.begin(), C.end()
// #define run() int test; cin>>test; cin.ignore(); while(test--)

// #define FOR(i,a,b)                    	for (int i=a; i<=b; i++)
// #define FOR2(i,a,b)                   	for (ll i=a; i<=b; ++i)
// #define FORD(i,a,b) 					for (int i=a; i>=b; i--)
// #define FORA(x,C) 						for (auto x:C)

// #define reset(C) 						memset(C,0,sizeof(C))
// #define clearQueue(C, x) 				C = queue<x> ()
// #define Fill(C,a) 						fill(C.begin(), C.end(), a)


// #define SORTC(C,check) 					sort(C.begin(), C.end(), check)

// #define um(x,y) 				unordered_map<x,y> 
// #define m(x,y) 					map<x,y> 
// #define p(x,y) 					pair<x,y> 
// #define us(x) 					unordered_set<x> 
// #define vec(x) 					vector<x> 
// #define vec2(C,x,y,token) 		vector<vector<token> > C(x, vector<token> (y, 0))
// #define pq(x) 					priority_queue<x>
// #define reverse_pq(x) 			priority_queue<x, vector<x>, greater<x> >

// 	// System

// #define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
// #define pause() system("pause");
// using namespace std;

// main() {
//     faster();
//     string str;
//     getline(cin,str);
//     stack<string>st;
//     string d="";
//     FOR(i, 0, str.size()-1) {
//         if(st.empty()&&(str[i]=='<'||str[i]=='>'||str[i]=='-')) continue;
//         if(str[i]=='<' && !st.empty()){
//             d = st.top()+d;
//             st.pop();
//         }
//         else if(str[i]=='>' && !st.empty() && d!=""){
//             string sx(1,d[0]);
//             d.erase(0,1);
//             st.push(sx);
//         }
//         else if(str[i]=='-'&& !st.empty()){
//             string sx=st.top();
//             st.pop();
//             sx.erase(sx.size()-1,sx.size());
//             st.push(sx);
//         }
//         else if(str[i]!='<'&&str[i]!='>'&&str[i]!='-'){
//             string sx="";
//             sx+=str[i];
//             st.push(sx);
//         }
//     }
//     if(d!=""&&str[str.size()-1]!='<'&&str[str.size()-1]!='>'&&str[str.size()-1]!='-')
//         st.push(d);
//     stack<string>st1;
//     while(!st.empty()) {
//         st1.push(st.top());
//         st.pop();
//     }
//     while(!st1.empty()){
//         cout<<st1.top();
//         st1.pop();
//     }
//     return EXIT_SUCCESS;
// }
/*
#include <iostream>
using namespace std;

const int MAX_N = 1000001;
char input[MAX_N], output[MAX_N];

// Node 
struct Node {
	char data;
	Node *next;
	Node *prev;
};

Node* initNode(char data = '\0') {
	Node* node = new Node;
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

// List
struct List {
	Node* root;
	Node* current;
};

List* initList() {
	List* list = new List;
	list->root = initNode();
	list->current = list->root;
	return list;
}

void deleteList(List *list) {
	Node *root = list->root;

	while(root->next != NULL) {
		Node* tmp = root->next;
		root->next = root->next->next;
		delete tmp;
	}

	delete root;
	delete list;
}

void moveLeft(List *list) {
	Node *p = list->current->prev;
	if (p) list->current = p; 
}

void moveRight(List *list) {
	Node *p = list->current->next;
	if (p) list->current = p; 
}

void backspace(List *list) {
	if (list->current->prev) {
		Node *curr = list->current;
		Node *prev = curr->prev;
		Node *next = curr->next;

		if (prev) prev->next = next;
		if (next) next->prev = prev;

		list->current = prev;
		delete curr;
	}
}

void addItem(List *list, char data) {
	Node* node = initNode(data);
	Node* next = list->current->next;
	list->current->next = node;
	node->prev = list->current;
	node->next = next;
	if (next) next->prev = node;
	list->current = node;
}

void build(List *list, char *output) {
	Node *p = list->root;
	int index = 0;

	while(p->next != NULL) {
		output[index] = p->next->data;
		p = p->next;
		index++;
	}

	output[index] = '\0';
}

void getPassword(List *list, char* output, char* input) {
	int index = 0;
	char current = '\0';

	while(true) {
		current = input[index];
		if (current == '\0') break;

		if (current == '<') {
			moveLeft(list);
		} else if (current == '>') {
			moveRight(list);
		} else if (current == '-') {
			backspace(list);
		} else {
			addItem(list, current);
		}

		index++;
	}

	build(list, output);
}

int main() {
	ios::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);

	// int T;
	// cin >> T;

	// for(int tc = 0; tc < T; tc++) {
		List *list = initList();
		cin >> input;
		getPassword(list, output, input);
		cout << output << endl;
		deleteList(list);
	}

	return 0;
}*/
/*
#include <iostream>
using namespace std;

const int MAX_N = 1000001;
char input[MAX_N], output[MAX_N];

// Stack
struct Stack {
	char* data;
	int length;
};

Stack* initStack(int maxLength) {
	Stack* st = new Stack;
	st->data = new char[maxLength];
	st->length = 0;
	st->data[st->length] = '\0';
	return st;
}

void destroyStack(Stack *st) {
	delete[] st->data;
	delete st;
}

int getLength(Stack *st) {
	return st->length;
}

bool isEmpty(Stack *st) {
	return st->length == 0;
}

bool isFull(Stack *st) {
	return st->length == MAX_N;
}

void push(Stack *st, char data) {
	if (!isFull(st) && data != '\0') {
		st->data[st->length] = data;
		st->length++;
		st->data[st->length] = '\0';
	}
}

char pop(Stack *st) {
	if (!isEmpty(st)) {
		char data = st->data[st->length - 1];
		st->length--;
		st->data[st->length] = '\0';
		return data;
	}

	return '\0';
}
// End of Stack

int getLength(char *input) {
  int index = 0;
	while(input[index] != '\0') index++;
	return index;
}

void concat(char *output, char *input1, char *input2) {
	int index1 = 0;
	while(input1[index1] != '\0') {
		output[index1++] = input1[index1]; 
	}

	int index2 = getLength(input2) - 1;
	int cnt = 0;
	while(index2 >= 0) {
		output[index1 + cnt++] = input2[index2--]; 
	}

	output[index1 + cnt] = '\0';
}

void getPassword(char *output, char* input) {
	Stack* stMain = initStack(MAX_N);
	Stack* stBuffer = initStack(MAX_N);

	int index = 0;
	char current = '\0';

	while(true) {
		current = input[index];
		if (current == '\0') break;
    
		if (current == '<') {
			push(stBuffer, pop(stMain));
		} else if (current == '>') {
			push(stMain, pop(stBuffer));
		} else if (current == '-') {
			pop(stMain);
		} else {
			push(stMain, current);
		}

		index++;
	}

	concat(output, stMain->data, stBuffer->data);
	destroyStack(stMain);
	destroyStack(stBuffer);
}

int main() {
	ios::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);

	// int T;
	// cin >> T;

	// for(int tc = 0; tc < T; tc++) {
		cin >> input;
		getPassword(output, input);
		cout << output << endl;
	}

	return 0;
}
*/