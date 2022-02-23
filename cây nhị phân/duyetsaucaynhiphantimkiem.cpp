/*
2

11

40  28  45 38  33  15  25  20  23  35  30

10

1  2  3  4  5  6  7  8  9  10
*/
#include <bits/stdc++.h>
using namespace std;
#define Nothing "mikey"
#define run() \
    int t;    \
    cin >> t; \
    while (t--)
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FORD(i, l, r) for (int i = l; i >= r; i--)
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl "\n"
#define ll long long

int MOD = 1e9 + 7;

struct node
{
    int data;
    node *left;
    node *right;
};

node *createNode(int data);
node *sortALV(int arr[], int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    node *root = createNode(arr[mid]);
    root->left = sortALV(arr, start, mid - 1);
    root->right = sortALV(arr, mid + 1, end);
    return root;
}

void printPostorder(node *Node);

int main()
{
    faster()
        run()
    {
        int n;
        cin >> n;
        int arr[n];
        FOR(i, 0, n - 1)
            cin >> arr[i];
        sort(arr, arr + n);
        node *root = sortALV(arr, 0, n - 1);
        printPostorder(root);
        cout << "\n";
    }
    return EXIT_SUCCESS;
}

node *createNode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return Node;
}

void printPostorder(node *Node)
{
    if (Node == NULL)
        return;
    printPostorder(Node->left);
    printPostorder(Node->right);
    cout << Node->data << " ";
}
