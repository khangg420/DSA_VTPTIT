#include <iostream>
using namespace std;

int n;
int x[100]; // x[i] l� gi� tr? t?i v? tr� i: 0 ho?c 1

void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        x[i] = j; // ch?n 0 ho?c 1 t?i v? tr� i
        if (i == n - 1) {
            // in ra m?t c?u h�nh ho�n ch?nh
            for (int k = 0; k < n; k++) {
                cout << x[k];
            }
            cout << endl;
        } else {
            Try(i + 1); // quay lui d? ch?n bit ti?p theo
        }
    }
}

int main() {
    cout << "Nhap do dai xau n: ";
    cin >> n;
    Try(0); // b?t d?u t? v? tr� d?u ti�n
    return 0;
}

