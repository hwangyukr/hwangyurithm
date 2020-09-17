#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 100000;

struct P {
    int x;
    int y;
    int n;
};

struct cmp {
    bool operator() (const P &a, const P &b) {
        if (a.y < b.y) return true;
        else if (a.y > b.y) return false;
        if (a.x > b.x) return true;
        return false;
    }
};

struct TREE {
    P p;
    TREE* left;
    TREE* right;
};

void insert_tree(TREE* root, P node) {
    if (root->p.x > node.x) {
        if (root->left != nullptr) {
            insert_tree(root->left, node);
        }
        else {
            root->left = new TREE();
            root->left->p = node;
            root->left->left = nullptr;
            root->left->right = nullptr;
        }
    }
    if (root->p.x < node.x) {
        if (root->right != nullptr) {
            insert_tree(root->right, node);
        }
        else {
            root->right = new TREE();
            root->right->p = node;
            root->right->left = nullptr;
            root->right->right = nullptr;
        }
    }
}

void get_order(TREE* tree, bool isPre, vector<int> &dest) {
    if (isPre) {
        dest.push_back(tree->p.n);
    }
    
    if (tree->left != nullptr) {
        get_order(tree->left, isPre, dest);
    }
    if (tree->right != nullptr) {
        get_order(tree->right, isPre, dest);
    }

    if (!isPre) {
        dest.push_back(tree->p.n);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    priority_queue<P, vector<P>, cmp> pq;
    for (int i = 0; i < nodeinfo.size(); i++) {
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];
        int n = i + 1;
        pq.push({ x, y, n });
    }
    TREE* tree = new TREE();
    tree->p = pq.top();
    tree->left = nullptr;
    tree->right= nullptr;
    pq.pop();
    while (!pq.empty()) {
        P t = pq.top();
        insert_tree(tree, t);
        pq.pop();
    }
    vector<int> pre;
    vector<int> post;
    get_order(tree, 1, pre);
    get_order(tree, 0, post);

    answer = { pre, post };
    return answer;
}

int main() {
    vector<vector<int>> in1 = { {5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2} };
    vector<vector<int>> ans = solution(in1);
    return 0;
}

// {{5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2}};