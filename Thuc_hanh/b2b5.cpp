#include<bits/stdc++.h>
using namespace std;

int partition(int a[], int l, int r){
	int i = l-1;
	int pivot = a[r];
	for(int j = l; j < r; j++){
		if(a[j] <= pivot){
			i++;
			swap(a[i], a[j]);
		}
	}
	i++;
	swap(a[i], a[r]);
	return i;
}

void quicksort(int a[], int l, int r){
	if(l >= r) 
		return;
	int q = partition(a, l, r);
	quicksort(a, l, q-1);
	quicksort(a, q+1, r);
}

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[n];
		for(int i = 0; i <= n-1; i++){
			cin >> a[i];
		}
		quicksort(a, 0, n-1);
		for(int i = 0; i < n; i++){
			cout << a[i] << " ";
		}
		cout << endl;
	}
}
