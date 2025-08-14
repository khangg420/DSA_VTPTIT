#include <iostream>
#include <stack>
#include <string>
#include <cctype>  // for isdigit function
#include <sstream> // for istringstream

using namespace std;

// Hàm tr? v? d? uu tiên c?a toán t?
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Hàm th?c hi?n phép toán gi?a hai toán h?ng
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

// Hàm dánh giá bi?u th?c trung t?
int evaluateInfix(const string &expression, bool &divideByZero) {
    stack<int> values; // ngan x?p d? luu tr? các toán h?ng
    stack<char> ops; // ngan x?p d? luu tr? các toán t?

    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ') continue; // b? qua kho?ng tr?ng

        // N?u ký t? là d?u ngo?c m?
        if (expression[i] == '(') {
            ops.push(expression[i]);
        }
        // N?u ký t? là s?
        else if (isdigit(expression[i])) {
            int val = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                val = (val * 10) + (expression[i] - '0');
                i++;
            }
            values.push(val);
            i--; // gi?m i vì vòng l?p for cung tang i
        }
        // N?u ký t? là d?u ngo?c dóng
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
        // N?u ký t? là toán t?
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

    // Hoàn thành các phép toán còn l?i trong ngan x?p
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
    cin.ignore();  // B? qua ký t? newline sau s? lu?ng b? test

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
