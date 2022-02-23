#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define ll long long

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

node *taonode(int x)
{
	node *t = new node;
	t->data = x;
	t->left = NULL;
	t->right = NULL;
	return t;
}

node *themnode(node *root, int x, queue<node *> &q)
{
	node *p = taonode(x);
	if (root == NULL)
		root = p;
	else if (q.front()->left == NULL)
		q.front()->left = p;
	else
	{
		q.front()->right = p;
		q.pop();
	}
	q.push(p);
	return root;
}

void in(node *t)
{
	if (t)
	{
		in(t->left);
		in(t->right);
		cout << t->data << " ";
	}
}
int main()
{
	int test;
	cin >> test;
	while (test--)
	{
		int n;
		cin >> n;
		int a, b;
		node *t = NULL;
		queue<node *> q;
		for (int i = 1; i <= n; i++)
			cin >> a;
		for (int i = 1; i <= n; i++)
		{
			cin >> b;
			t = themnode(t, b, q);
		}
		in(t);
		cout << endl;
	}
	return 0;
}