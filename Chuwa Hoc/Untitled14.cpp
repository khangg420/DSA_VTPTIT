#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
	int value;
	TreeNode* left;
	TreeNode* right;
	
	TreeNode(int num) {
		value = num;
		left = NULL;
		right = NULL;
	}
};

TreeNode* TaoCayNP(vector<int> tree) {
	TreeNode* root = new TreeNode(tree[0]);
	
	queue<TreeNode*> q;
	q.push(root);
	
	int i = 1;
	while(i < tree.size() and !q.empty()) {
		TreeNode* tmp = q.front();
		q.pop();
		
		if(i < tree.size() and tree[i] != -1) {
			tmp->left = new TreeNode(tree[i]);
			q.push(tmp->left);
		}
		i++;
		
		if(i < tree.size() and tree[i] != -1) {
			tmp->right = new TreeNode(tree[i]);
			q.push(tmp->right);
		}
		i++;
	}
	return root;
}

vector<int> dfs;
void DFS(TreeNode* node) {
	if(node == NULL) {
		return;
	}
	dfs.push_back(node->value);
	
	if(node->left == NULL and node->right == NULL) {
		for(int i = 0; i < dfs.size(); i++) {
			cout << dfs[i];
			if(i != dfs.size() - 1) 
				cout << "->";
		}
		cout << endl;
	}
	
	DFS(node->left);
	DFS(node->right);
	
	dfs.pop_back();
}

int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> tree(n);
		for(int i = 0; i < n; i++) {
			cin >> tree[i];
		}
		TreeNode* root = TaoCayNP(tree);
		DFS(root);
		dfs.clear();
	}
}
