#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(vector<int> &a) {
	int max_sum = 0, cur_sum = 0;
	for(int i = 1; i < a.size(); i++) {
		cur_sum += a[i];
		if(cur_sum < 0) {
			cur_sum = 0;
		}
		else {
			max_sum = max(max_sum, cur_sum);
		}
	}
	return max_sum;
}

int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i++) cin >> a[i];
		cout << maxSubArraySum(a) << endl;
	}
}
