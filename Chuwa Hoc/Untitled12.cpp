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

void nhinPhai(TreeNode* root) {
	queue<TreeNode*> q;
	q.push(root);
	
	while(!q.empty()) {
		TreeNode* last;
		int size = q.size();
		for(int i = 0; i < size; i++) {
			TreeNode* tmp = q.front();
			q.pop();
			last = tmp;
			
			if(tmp->left) q.push(tmp->left);
			if(tmp->right) q.push(tmp->right);
		}
		cout << last->value << " ";
	}
	cout << endl;
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
		nhinPhai(root);
	}
}
