#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define ll long long

struct node
{
	long long data;
	node *left, *right;
	node(long long x)
	{
		this->data = x;
		this->left = this->right = NULL;
	}
};

void themnode(node *t, int pa, int chi, int c)
{
	if (t->data == pa)
	{
		if (c == 'L')
			t->left = new node(chi);
		else
			t->right = new node(chi);
	}
	else
	{
		if (t->left)
			themnode(t->left, pa, chi, c);
		if (t->right)
			themnode(t->right, pa, chi, c);
	}
}

long long maxPathSumUtil(node *root, long long &res)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return root->data;

	long long sumLeft = maxPathSumUtil(root->left, res);
	long long sumRight = maxPathSumUtil(root->right, res);

	if (root->left != NULL && root->right != NULL)
	{
		res = max(res, sumLeft + sumRight + root->data);
		return max(sumLeft, sumRight) + root->data;
	}
	return (((root->left != NULL) ? sumLeft : sumRight) + root->data);
}

long long find(node *root)
{
	long long res = -221120010407;
	long long temp = maxPathSumUtil(root, res);
	if (res == -221120010407)
		return temp;
	return res;
}

int main()
{
	int test;
	cin >> test;
	while (test--)
	{
		int n;
		cin >> n;
		int pa, chi;
		char c;
		cin >> pa >> chi >> c;
		node *t = new node(pa);
		if (c == 'L')
		{
			t->left = new node(chi);
		}
		else
		{
			t->right = new node(chi);
		}
		for (int i = 2; i <= n; i++)
		{
			cin >> pa >> chi >> c;
			themnode(t, pa, chi, c);
		}
		cout << find(t);
		cout << endl;
	}
	return 0;
}