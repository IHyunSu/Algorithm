#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

#define MAX 999
typedef vector<vector<int> > matrix_t;
int cnt = 1, N;

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} *node_ptr;

node_ptr create_node(int key) {
    node_ptr node = new struct node;
    node->data = key;
    node->left = node->right = nullptr;
    return node;
}

void optsearchtree(int n, vector<int>& p, matrix_t& A, matrix_t& R) {
    for (int i = 1; i <= n; i++) {
        A[i][i] = p[i];
        A[i][i - 1] = 0;
        R[i][i] = i;
        R[i][i - 1] = 0;
    }
    A[n + 1][n] = R[n + 1][n] = 0;

    for (int diagonal = 1; diagonal <= n - 1; diagonal++) {
        for (int i = 1; i <= n - diagonal; i++) {
            int j = i + diagonal;
            A[i][j] = INT_MAX;
            int psum = 0;
            for (int m = i; m <= j; m++) psum += p[m];
            for (int k = i; k <= j; k++) {
                int cost = A[i][k - 1] + A[k + 1][j] + psum;
                if (cost < A[i][j]) {
                    A[i][j] = cost;
                    R[i][j] = k;
                }
            }
        }
    }
}

node_ptr tree(int i, int j, vector<int>& keys, matrix_t& R) {
    int k = R[i][j];
    if (k == 0) return nullptr;

    node_ptr node = create_node(keys[k]);
    node->left = tree(i, k - 1, keys, R);
    node->right = tree(k + 1, j, keys, R);
    return node;
}

void preorder(node_ptr root) {
    if (root == nullptr) return;
    cout << root->data;
    if (cnt != N) {
        cout << " ";
        cnt++;
    }
    preorder(root->left);
    preorder(root->right);
}

void inorder(node_ptr root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data;
    if (cnt != N) {
        cout << " ";
        cnt++;
    }
    inorder(root->right);
}

int main() {
    int n;
    cin >> n;
    N = n;

    vector<int> keys(n + 1);  // 1-based indexing
    vector<int> p(n + 1);     // weights or frequencies

    for (int i = 1; i <= n; i++)
        cin >> keys[i];
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    matrix_t A(n + 2, vector<int>(n + 1, 0));
    matrix_t R(n + 2, vector<int>(n + 1, 0));

    optsearchtree(n, p, A, R);
    node_ptr root = tree(1, n, keys, R);

    for (int i = 1; i <= n+1; i++) {
        for (int j = i-1; j <= n; j++) {
            cout << A[i][j];
            if (j != n) cout << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= n+1; i++) {
        for (int j = i-1; j <= n; j++) {
            cout << R[i][j];
            if (j != n) cout << " ";
        }
        cout << endl;
    }
    cout << A[1][n] << endl;
    preorder(root);
    cout << endl;
    cnt = 1;
    inorder(root);
    cout << endl;

    return 0;
}
