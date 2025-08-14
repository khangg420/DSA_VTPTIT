#include <iostream>
#include <stack>
#include <string>
#include <cctype>  // for isdigit function
#include <sstream> // for istringstream

using namespace std;

// H�m tr? v? d? uu ti�n c?a to�n t?
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// H�m th?c hi?n ph�p to�n gi?a hai to�n h?ng
int applyOperation(int a, int b, char op, bool &divideByZero) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) {
                divideByZero = true;
                return 0;
            }
            return a / b;
    }
    return 0;
}

// H�m d�nh gi� bi?u th?c trung t?
int evaluateInfix(const string &expression, bool &divideByZero) {
    stack<int> values; // ngan x?p d? luu tr? c�c to�n h?ng
    stack<char> ops; // ngan x?p d? luu tr? c�c to�n t?

    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ') continue; // b? qua kho?ng tr?ng

        // N?u k� t? l� d?u ngo?c m?
        if (expression[i] == '(') {
            ops.push(expression[i]);
        }
        // N?u k� t? l� s?
        else if (isdigit(expression[i])) {
            int val = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                val = (val * 10) + (expression[i] - '0');
                i++;
            }
            values.push(val);
            i--; // gi?m i v� v�ng l?p for cung tang i
        }
        // N?u k� t? l� d?u ngo?c d�ng
        else if (expression[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperation(val1, val2, op, divideByZero));
                if (divideByZero) return 0;
            }
            ops.pop(); // lo?i b? d?u ngo?c m?
        }
        // N?u k� t? l� to�n t?
        else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expression[i])) {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperation(val1, val2, op, divideByZero));
                if (divideByZero) return 0;
            }
            ops.push(expression[i]);
        }
    }

    // Ho�n th�nh c�c ph�p to�n c�n l?i trong ngan x?p
    while (!ops.empty()) {
        int val2 = values.top(); values.pop();
        int val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOperation(val1, val2, op, divideByZero));
        if (divideByZero) return 0;
    }

    return values.top();
}

int main() {
int T;
    cin >> T;
    cin.ignore();  // B? qua k� t? newline sau s? lu?ng b? test

    for (int i = 0; i < T; ++i) {
        string expression;
        getline(cin, expression);
        bool divideByZero = false;
        int result = evaluateInfix(expression, divideByZero);
        if (divideByZero) {
            cout << "0" << endl;
        } else {
            cout << result << endl;
        }
    }
    return 0;
}
