#include <bits/stdc++.h>
using namespace std;

void insertionSortSteps(vector<int> a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;

        cout << "Buoc " << i << ": ";
        for (int k = 0; k <= i; k++)
            cout << a[k] << " ";
        cout << endl;
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; 
		cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        insertionSortSteps(a);
    }
    return 0;
}
