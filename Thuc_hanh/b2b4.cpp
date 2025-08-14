#include <bits/stdc++.h>
using namespace std;

//Chen mot phan tu vao cuoi chuoi da dao nguoc
void insertAtBottom(stack<int> &st, int item) {
    if (st.empty()) {
        st.push(item);
        return;
    }
    int top = st.top();
    st.pop();
    insertAtBottom(st, item);
    st.push(top);
}

//Ham de quy dao nguoc ngan xep
void reverseStack(stack<int> &st) {
    if (st.empty()) return;
    int top = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, top);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        
        //Cho tung phan tu vao stack tu cuoi len dau
        stack<int> st;
        for (int i = N - 1; i >= 0; i--) {
            st.push(arr[i]);
        }
        
        reverseStack(st);
        
        //In ket qua
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
    return 0;
}
