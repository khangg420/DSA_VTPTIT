#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int num) {
        value = num;
        left = right = NULL;
    }
};

map<int, Node*> nodeMap;

Node* buildTree(int n) {
    nodeMap.clear();
    Node* root = NULL;
    
    for (int i = 0; i < n; ++i) {
        int u, v;
        char dir;
        cin >> u >> v >> dir;

        if (!nodeMap[u]) nodeMap[u] = new Node(u);
        if (!nodeMap[v]) nodeMap[v] = new Node(v);

        if (dir == 'L') {
            nodeMap[u]->left = nodeMap[v];
        } 
		else {
            nodeMap[u]->right = nodeMap[v];
        }

        if (!root) root = nodeMap[u]; // ch?n node d?u tiên làm root
    }

    return root;
}

// Ki?m tra các node lá có cùng level không
bool checkLeafLevel(Node* root) {
    if (!root) return true;

    queue<pair<Node*, int>> q;
    q.push({root, 0});
    int leafLevel = -1;

    while (!q.empty()) {
    	Node* node = q.front().first;
    	int level = q.front().second;
        q.pop();

        // N?u là node lá
        if (!node->left && !node->right) {
            if (leafLevel == -1) leafLevel = level;
            else if (level != leafLevel) return false;
        }

        if (node->left) q.push({node->left, level + 1});
        if (node->right) q.push({node->right, level + 1});
    }

    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        Node* root = buildTree(N);
        cout << (checkLeafLevel(root) ? 1 : 0) << endl;
    }
    return 0;
}
